#include "neuron.h"

#include "edge.h"

Neuron::Neuron(int id, Type type)
    : id_(id),
      type_(type) {

}

double Neuron::value() const {
    return value_;
}

void Neuron::set_value(double value) {
    value_ = value;
}

void Neuron::add_input(Edge* edge) {
    in_.push_back(edge);
}

double Neuron::sigmoid(double x) {
    return x > 0 ? 1 : -1;
    //return 2.0 / (1 + std::exp(-x * 20)) - 1;
}

double Neuron::activate() {
    double activation = 0.0;
    for (auto& e : in_) {
        if (e->is_enabled()) {
            activation += e->from()->value() * e->w();
        }
    }
    activation = sigmoid(activation);
    return activation;
}
