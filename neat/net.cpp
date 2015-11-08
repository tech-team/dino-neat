#include "net.h"

#include <assert.h>
#include <algorithm>

#include "neuron.h"
#include "edge.h"

Net::Net(const Config& conf)
    : conf_(conf) {
    for (int i = 0; i < conf.input_size; ++i) {
        inputs_.push_back(createNeuron(Neuron::Type::INPUT));
    }

    for (int i = 0; i < conf.output_size; ++i) {
        auto n = createNeuron(Neuron::Type::OUTPUT);
        outputs_.push_back(n);
        neurons_.push_back(n);
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

int Net::nextNeuronId() {
    return ++neuron_id_;
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

Neuron* Net::createNeuron() {
    Neuron* n = createNeuron(Neuron::Type::HIDDEN);
    neurons_.push_back(n);
    return n;
}

Edge* Net::createEdge(int innovation, Neuron* from, Neuron* to) {
    Edge* e = new Edge(innovation, from, to);
    edges_.push_back(e);
    return e;
}

Edge* Net::createRandEdge(int innovation) {
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
        size_t rand_index = rand() % total_size;

        if (rand_index < n) {
            from = neurons_[rand_index];
        } else {
            from = inputs_[rand_index - n];
        }

        rand_index = rand() % n;
        to = neurons_[rand_index];
    } while (checkEdgeExists(from, to));

    auto edge = createEdge(innovation, from, to);
    return edge;
}

Edge* Net::randEdge() {
    if (edges_.empty()) {
        return nullptr;
    }
    size_t rand_edge_index = rand() % edges_.size();
    return edges_[rand_edge_index];
}

Neuron* Net::createNeuron(Neuron::Type neuronType) {
    return new Neuron(nextNeuronId(), neuronType);
}

bool Net::checkEdgeExists(Neuron* from, Neuron* to) const {
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
