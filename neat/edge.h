#ifndef EDGE_H
#define EDGE_H

#include <algorithm>

class Neuron;

struct EdgeInfo {
    int from;
    int to;
};

bool operator ==(const EdgeInfo& e1, const EdgeInfo& e2);

class Edge
{
public:
    Edge(Neuron* from, Neuron* to);

    Neuron* from() const;
    Neuron* to() const;
    double w() const;
    int innovation() const;
    bool is_enabled() const;
    const EdgeInfo& edge_info() const;

    void set_w(double w);
    void set_enabled(bool enabled);
    void set_innovation(int innovation);

private:
    double w_ = 1.0;
    int innovation_ = -1;
    bool enabled_ = true;

    Neuron* from_ = nullptr;
    Neuron* to_ = nullptr;

    EdgeInfo edge_info_;
};


namespace std {

    template <>
    struct hash<EdgeInfo> {
        std::size_t operator()(const EdgeInfo& edgeInfo) const
        {
            int hash = 23;
            hash = hash * 31 + std::hash<int>()(edgeInfo.from);
            hash = hash * 31 + std::hash<int>()(edgeInfo.to);

            return hash;
        }
    };

}


#endif // EDGE_H
