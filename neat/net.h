#ifndef NET_H
#define NET_H

#include <vector>
#include <ostream>

#include "neuron.h"

class Edge;

class Net {
public:

    struct Config {
        int input_size;
        int output_size;
    };

    Net(const Net::Config& conf);
    ~Net();

    std::vector<double> activate(const std::vector<double>& data);
    Neuron* createNeuron();
    Edge* createEdge(int innovation, Neuron* from, Neuron* to);
    Edge* createRandEdge(int innovation);
    Edge* randEdge();

    friend std::ostream& operator <<(std::ostream& os, const Net& net);

private:
    Neuron* createNeuron(Neuron::Type neuronType);
    int nextNeuronId();
    bool checkEdgeExists(Neuron* from, Neuron* to) const;

    Net::Config conf_;
    std::vector<Neuron*> neurons_;  // HIDDEN and OUTPUT neurons only
    std::vector<Edge*> edges_;      // edges

    std::vector<Neuron*> inputs_;   // not contained in |neurons|
    std::vector<Neuron*> outputs_;  // contained in |neurons|

    int neuron_id_ = 0;
};

#endif // NET_H
