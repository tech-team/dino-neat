#include "chromosome.h"

#include <iostream>

#include "net.h"
#include "neuron.h"
#include "edge.h"

Chromosome::Chromosome(Net* net)
    : net_(net) {

}

Chromosome::Chromosome(Chromosome&& ch) {
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

void Chromosome::mutateWeights(int innovation) {
    // TODO
}

void Chromosome::mutateStructure(int innovation) {
    mutateAddConnection(innovation);
    mutateAddNode(innovation);
}

void Chromosome::mutateAddConnection(int innovation) {
    auto edge = net_->createRandEdge(innovation);
    if (edge == nullptr) {
        std::cout << "Couldn't create edge. net: " << net_ << std::endl;
    }
}

void Chromosome::mutateAddNode(int innovation) {
    auto node = net_->createNeuron();
    auto edge = net_->randEdge();
    edge->set_enabled(false);

    auto edge1 = net_->createEdge(innovation, edge->from(), node);
    auto edge2 = net_->createEdge(innovation, node, edge->to());

    edge1->set_w(1.0);
    edge2->set_w(edge->w());
}

Chromosome Chromosome::crossover(const Chromosome& ch1, const Chromosome& ch2) {

}
