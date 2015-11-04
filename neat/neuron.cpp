#include "neuron.h"

Neuron::Neuron(int id, Type type)
    : id_(id),
      type_(type) {

}

double Neuron::sigmoid(double x) {
    return x > 0 ? 1 : -1;
    //return 2.0 / (1 + std::exp(-x * 20)) - 1;
}
