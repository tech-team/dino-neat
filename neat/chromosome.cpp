#include "chromosome.h"

#include <iostream>

#include "net.h"
#include "neuron.h"
#include "edge.h"
#include "innovation_number_getter.h"
#include "util.h"

Chromosome::Chromosome(const NeatConfig& conf, Net* net)
    : net_(net),
      conf_(conf) {

}

Chromosome::Chromosome(Chromosome&& ch)
    : conf_(ch.conf_) {
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
    // TODO
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
    Net* net = new Net(conf.net_conf);

    net->assignInputNeurons(ch1.net()->inputs());
    net->assignOutputNeurons(ch1.net()->outputs());

    int max_innovation = std::max(ch1.net()->getMaxInnovation(), ch2.net()->getMaxInnovation());
    for (int i = 1; i <= max_innovation; ++i) {
        const Edge* e1 = ch1.net()->getEdgeByInnovation(i);
        const Edge* e2 = ch2.net()->getEdgeByInnovation(i);

        const Edge* parent = nullptr;
        if (e1 && e2) {
            parent = rand() % 2 ? e1 : e2;
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
        if (!net->getNeuronById(parent->to()->id())) {
            net->createHiddenNeuron(parent->to()->id());
        }

        Edge* edge = net->createEdge(from, to, parent->w());
        edge->set_innovation(i);
        net->indexEdge(edge);
        if (!parent->is_enabled()) {
            if (RandomGenerator::instance().rand() < conf.edge_enable_prob) {
                edge->set_enabled(true);
            } else {
                edge->set_enabled(false);
            }
        }
    }



    return Chromosome(ch1.conf_, net);
}



