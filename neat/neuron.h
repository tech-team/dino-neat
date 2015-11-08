#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Edge;

class Neuron {
public:
    enum class Type {
        INPUT, HIDDEN, OUTPUT
    };

    Neuron(int id, Type type = Type::HIDDEN);

    double value() const;
    void set_value(double value);

    void add_input(Edge* edge);

    double activate();

private:
    static double sigmoid(double x);

    int id_;
    Type type_ = Type::HIDDEN;

    std::vector<Edge*> in_;
    double value_ = 0;
};

#endif // NEURON_H
