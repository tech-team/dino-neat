#include "net.h"

#include <assert.h>
#include <algorithm>

#include "neuron.h"
#include "edge.h"
#include "util.h"

Net::Net(const Config& conf, bool init)
    : conf_(conf) {
    if (init) {
        for (int i = 0; i < conf.input_size; ++i) {
            inputs_.push_back(createNeuron(Neuron::Type::INPUT));
        }

        for (int i = 0; i < conf.output_size; ++i) {
            auto n = createNeuron(Neuron::Type::OUTPUT);
            outputs_.push_back(n);
            neurons_.push_back(n);
        }
    }
}

Net::~Net() {
    for (auto& n : inputs_) {
        delete n;
        n = nullptr;
    }

    for (auto& n : neurons_) {
        delete n;
        n = nullptr;
    }

    for (auto& e : edges_) {
        delete e;
        e = nullptr;
    }
}

const Net::Config& Net::conf() const {
    return conf_;
}

const std::vector<Neuron*>& Net::inputs() const {
    return inputs_;
}

const std::vector<Neuron*>& Net::outputs() const {
    return outputs_;
}

int Net::nextNeuronId() {
    return ++max_neuron_id_;
}

std::vector<double> Net::activate(const std::vector<double>& data) {
    assert(data.size() == inputs_.size());
    for (size_t i = 0; i < data.size(); ++i) {
        inputs_[i]->set_value(data[i]);
    }

    for (auto& n : neurons_) {
        n->activate();
    }

    std::vector<double> res(outputs_.size());
    for (size_t i = 0; i < outputs_.size(); ++i) {
        res[i] = outputs_[i]->value();
    }
    return res;
}

Neuron* Net::createHiddenNeuron() {
    Neuron* n = createNeuron(Neuron::Type::HIDDEN);
    neurons_.push_back(n);
    return n;
}

Neuron* Net::createHiddenNeuron(int id) {
    Neuron* n = createNeuron(id, Neuron::Type::HIDDEN);
    neurons_.push_back(n);
    return n;
}

Edge* Net::createEdge(Neuron* from, Neuron* to, double w) {
    Edge* e = new Edge(from, to);
    e->set_w(w);
    edges_.push_back(e);
    return e;
}

Edge* Net::indexEdge(Edge* edge) {
    assert(edge->innovation() != -1);
    edges_index_[edge->innovation()] = edge;
    return edge;
}

Neuron* Net::getNeuronById(int id) const {
    auto it = neurons_index_.find(id);
    if (it == neurons_index_.end()) {
        return nullptr;
    } else {
        return it->second;
    }
}

const Edge* Net::getEdgeByInnovation(int innovation) const {
    auto it = edges_index_.find(innovation);
    if (it == edges_index_.end()) {
        return nullptr;
    } else {
        return it->second;
    }
}

int Net::getMaxInnovation() const {
    if (edges_.empty()) {
        return -1;
    }
    return edges_.back()->innovation();
}

Edge* Net::createRandEdge() {
    size_t n = neurons_.size();
    size_t m = inputs_.size();
    size_t max_edges = n * n + n * m;

    if (edges_.size() == max_edges) {
        return nullptr;
    }

    Neuron* from = nullptr;
    Neuron* to = nullptr;

    do {
        size_t total_size = n + m;
        size_t rand_index = RandomGenerator::instance().randInt(0, total_size - 1);

        if (rand_index < n) {
            from = neurons_[rand_index];
        } else {
            from = inputs_[rand_index - n];
        }

        rand_index = RandomGenerator::instance().randInt(0, n - 1);
        to = neurons_[rand_index];
    } while (checkEdgeExists(from, to));

    auto edge = createEdge(from, to, RandomGenerator::instance().rand(-1.0, 1.0));
    return edge;
}

Edge* Net::randEdge() {
    if (edges_.empty()) {
        return nullptr;
    }
    size_t rand_edge_index = RandomGenerator::instance().randInt(0, edges_.size() - 1);
    return edges_[rand_edge_index];
}

std::vector<Edge*>& Net::edges() {
    return edges_;
}

void Net::assignInputNeurons(const std::vector<Neuron*>& input_neurons) {
    for (auto& n : input_neurons) {
        inputs_.push_back(createNeuron(n->id(), Neuron::Type::INPUT));
    }
}

void Net::assignOutputNeurons(const std::vector<Neuron*>& output_neurons) {
    for (auto& n : output_neurons) {
        outputs_.push_back(createNeuron(n->id(), Neuron::Type::OUTPUT));
        neurons_.push_back(outputs_.back());
    }
}


Neuron* Net::createNeuron(Neuron::Type neuronType) {
    return createNeuron(nextNeuronId(), neuronType);
}

Neuron* Net::createNeuron(int id, Neuron::Type neuronType) {
    Neuron* n = new Neuron(id, neuronType);
    neurons_index_[n->id()] = n;
    if (n->id() > max_neuron_id_) {
        max_neuron_id_ = n->id();
    }
    return n;
}

bool Net::checkEdgeExists(Neuron* from, Neuron* to) const {
    if (from == nullptr || to == nullptr) {
        return false;
    }
    for (const Edge* e : edges_) {
        if (e->from() == from && e->to() == to) {
            return true;
        }
    }
    return false;
}


std::ostream& operator <<(std::ostream& os, const Net& net) {
    os << "neurons_count=" << net.neurons_.size() << "; "
       << "inputs_count=" << net.inputs_.size() << "; "
       << "outputs_count=" << net.outputs_.size() << "; "
       << "edges_count=" << net.edges_.size() << ".";
    return os;
}
