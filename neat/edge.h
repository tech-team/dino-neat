#ifndef EDGE_H
#define EDGE_H

class Neuron;
class Edge
{
public:
    Edge(int innovation, Neuron* from, Neuron* to);

    Neuron* from() const;
    Neuron* to() const;
    double w() const;
    double innovation() const;
    bool is_enabled() const;

    void set_w(double w);
    void set_enabled(bool enabled);

private:
    double w_ = 1.0;
    int innovation_ = -1;
    bool enabled_ = true;

    Neuron* from_ = nullptr;
    Neuron* to_ = nullptr;
};

#endif // EDGE_H
