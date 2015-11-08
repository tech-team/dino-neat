#include "edge.h"

#include <assert.h>

#include "neuron.h"

Edge::Edge(int innovation, Neuron* from, Neuron* to)
    : innovation_(innovation),
      from_(from),
      to_(to) {
    assert(from != nullptr);
    assert(to != nullptr);
    assert(innovation_ > 0);

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

double Edge::innovation() const {
    return innovation_;
}

bool Edge::is_enabled() const {
    return enabled_;
}

void Edge::set_w(double w) {
    w_ = w;
}

void Edge::set_enabled(bool enabled) {
    enabled_ = enabled;
}
