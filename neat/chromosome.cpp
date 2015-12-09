#include "chromosome.h"

#include <iostream>
#include <assert.h>

#include "common/random.h"
#include "net.h"
#include "neuron.h"
#include "edge.h"
#include "innovation_number_getter.h"
#include "util.h"

Chromosome::Chromosome(Random& random, const NeatConfig& conf, Net* net)
    : net_(net),
      conf_(conf),
      random_(random) {

}

Chromosome::Chromosome(Chromosome&& ch)
    : conf_(ch.conf_),
      random_(ch.random_) {

    net_ = ch.net_;
    fitness_ = ch.fitness_;

    ch.net_ = nullptr;
    ch.fitness_ = 0;
}

Chromosome& Chromosome::operator=(Chromosome&& ch) {
    net_ = ch.net_;
    fitness_ = ch.fitness_;

    ch.net_ = nullptr;
    ch.fitness_ = 0;

    return *this;
}

Chromosome::~Chromosome() {
    delete net_;
    net_ = nullptr;
}

Net* Chromosome::net() const {
    return net_;
}

double Chromosome::fitness() const {
    return fitness_;
}

void Chromosome::set_fitness(double fitness) {
    fitness_ = fitness;
}

void Chromosome::mutateWeights() {
    auto step = conf_.mutate_weights_step;
    for (auto& e : net_->edges()) {
        if (random_.nextDouble() < conf_.mutate_weights_petrurb_prob) {
            e->set_w(e->w() + random_.nextDouble() * step * 2 - step);
        } else {
            e->set_w(random_.nextDouble(-1.0, 1.0));
        }
    }
}

void Chromosome::mutateStructure(InnovationNumberGetter* innov_getter) {
    mutateAddConnection(innov_getter);
    mutateAddNode(innov_getter);
}

void Chromosome::mutateAddConnection(InnovationNumberGetter* innov_getter) {
    auto edge = net_->createRandEdge();
    edge->set_innovation(innov_getter->getInnovNumber(edge));
    net_->indexEdge(edge);
    if (edge == nullptr) {
        std::cout << "Couldn't create edge. net: " << net_ << std::endl;
    }
}

void Chromosome::mutateAddNode(InnovationNumberGetter* innov_getter) {
    auto node = net_->createHiddenNeuron();
    auto edge = net_->randEdge();
    if (edge == nullptr) {
        return;
    }
    edge->set_enabled(false);

    auto edge1 = net_->createEdge(edge->from(), node);
    auto edge2 = net_->createEdge(node, edge->to());

    edge1->set_innovation(innov_getter->getInnovNumber(edge1));
    edge2->set_innovation(innov_getter->getInnovNumber(edge2));

    net_->indexEdge(edge1);
    net_->indexEdge(edge2);

    edge1->set_w(1.0);
    edge2->set_w(edge->w());
}

Chromosome Chromosome::crossover(const Chromosome& ch1, const Chromosome& ch2) {
    auto& conf = ch1.conf_;
    auto& random = ch1.random_;

    Net* net = new Net(random, conf.net_conf, false);

    net->assignInputNeurons(ch1.net()->inputs());
    net->assignOutputNeurons(ch1.net()->outputs());

    int max_innovation = std::max(ch1.net()->getMaxInnovation(), ch2.net()->getMaxInnovation());
    std::cout << "max_innovation = " << max_innovation << std::endl;
    for (int i = 1; i <= max_innovation; ++i) {
        const Edge* e1 = ch1.net()->getEdgeByInnovation(i);
        const Edge* e2 = ch2.net()->getEdgeByInnovation(i);

        const Edge* parent = nullptr;
        if (e1 && e2) {
            parent = random.nextInt(0, 1) ? e1 : e2;
        } else if (e1) {
            parent = e1;
        } else if (e2) {
            parent = e2;
        } else {
            continue;
        }

        // check if endpoint neurons exist
        Neuron* from = net->getNeuronById(parent->from()->id());
        if (!from) {
            from = net->createHiddenNeuron(parent->from()->id());
        }

        Neuron* to = net->getNeuronById(parent->to()->id());
        if (!to) {
            to = net->createHiddenNeuron(parent->to()->id());
        }

        Edge* edge = net->createEdge(from, to, parent->w());
        edge->set_innovation(i);

        net->indexEdge(edge);
        if (!parent->is_enabled()) {
            if (random.nextDouble() < conf.crossover_edge_enable_prob) {
                edge->set_enabled(true);
            } else {
                edge->set_enabled(false);
            }
        }
    }

    return Chromosome(random, conf, net);
}

double Chromosome::distance(const Chromosome& ch1, const Chromosome& ch2) {
    const NeatConfig& conf = ch1.conf_;
    uint32_t excess = 0;
    uint32_t disjoint = 0;
    double w_avg = 0;
    uint32_t matched_genes = 0;
    uint32_t n = std::max(ch1.net()->edges().size(), ch2.net()->edges().size());
    if (n < 20) {
        n = 1;
    }

    bool is_disjoint = false;

    int min_innovation = std::min(ch1.net()->getMaxInnovation(), ch2.net()->getMaxInnovation());
    int max_innovation = std::max(ch1.net()->getMaxInnovation(), ch2.net()->getMaxInnovation());
    for (int i = 1; i <= min_innovation; ++i) {
        const Edge* e1 = ch1.net()->getEdgeByInnovation(i);
        const Edge* e2 = ch2.net()->getEdgeByInnovation(i);

        if (e1 && e2) {
            w_avg += std::abs(e1->w() - e2->w());
            ++matched_genes;
            is_disjoint = true;
            continue;
        } else if (e1 || e2) {
            if (is_disjoint) {
                ++disjoint;
            } else {
                ++excess;
            }
        } else {
            continue;
        }
    }

    for (int i = min_innovation + 1; i <= max_innovation; ++i) {
        const Edge* e1 = ch1.net()->getEdgeByInnovation(i);
        const Edge* e2 = ch2.net()->getEdgeByInnovation(i);

        assert(!(e1 && e2));
        if (e1 || e2) {
            ++excess;
        } else {
            continue;
        }
    }

    w_avg /= matched_genes;
    double delta = conf.dist_excess_ratio * excess / n + conf.dist_disjoint_ratio * disjoint / n + conf.dist_avg_weights_raio * w_avg;
    return delta;
}



