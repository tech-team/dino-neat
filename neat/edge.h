#ifndef EDGE_H
#define EDGE_H

class Neuron;
class Edge
{
public:
    Edge(Neuron* from, Neuron* to);

private:
    double w_ = 0;
    int innovation_ = 0;
    bool enabled_ = true;

    Neuron* from_ = nullptr;
    Neuron* to_ = nullptr;
};

#endif // EDGE_H
