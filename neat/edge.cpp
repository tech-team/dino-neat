#include "edge.h"

#include <assert.h>

#include "neuron.h"

bool operator ==(const EdgeInfo& e1, const EdgeInfo& e2) {
   return e1.from == e2.from && e1.to == e2.to;
}

Edge::Edge(Neuron* from, Neuron* to)
    : from_(from),
      to_(to) {
    assert(from != nullptr);
    assert(to != nullptr);

    edge_info_ = EdgeInfo{from->id(), to->id()};

    to_->add_input(this);
}

Neuron* Edge::from() const {
    return from_;
}

Neuron* Edge::to() const {
    return to_;
}

double Edge::w() const {
    return w_;
}

int Edge::innovation() const {
    return innovation_;
}

bool Edge::is_enabled() const {
    return enabled_;
}

const EdgeInfo& Edge::edge_info() const {
    return edge_info_;
}

void Edge::set_w(double w) {
    w_ = w;
}

void Edge::set_enabled(bool enabled) {
    enabled_ = enabled;
}

void Edge::set_innovation(int innovation) {
    innovation_ = innovation;
}
