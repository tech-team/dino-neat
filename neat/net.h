#ifndef NET_H
#define NET_H

#include <ostream>
#include <vector>
#include <unordered_map>

#include "common/random.h"
#include "neuron.h"

class Edge;

class Net {
public:

    struct Config {
        int input_size;
        int output_size;
    };

    Net(Random& random, const Net::Config& conf, bool init=true);
    ~Net();

    const Net::Config& conf() const;
    const std::vector<Neuron*>& inputs() const;
    const std::vector<Neuron*>& outputs() const;

    std::vector<double> activate(const std::vector<double>& data);
    Neuron* createHiddenNeuron();
    Neuron* createHiddenNeuron(int id);
    Edge* createEdge(Neuron* from, Neuron* to, double w = 0.0);
    Edge* indexEdge(Edge* edge);
    Edge* createRandEdge();
    Edge* randEdge();

    std::vector<Edge*>& edges();

    Neuron* getNeuronById(int id) const;

    const Edge* getEdgeByInnovation(int innovation) const;
    int getMaxInnovation() const;

    void assignInputNeurons(const std::vector<Neuron*>& input_neurons);
    void assignOutputNeurons(const std::vector<Neuron*>& output_neurons);

    friend std::ostream& operator <<(std::ostream& os, const Net& net);

private:
    Neuron* createNeuron(Neuron::Type neuronType);
    Neuron* createNeuron(int id, Neuron::Type neuronType);
    int nextNeuronId();
    bool checkEdgeExists(Neuron* from, Neuron* to) const;

    Net::Config conf_;
    std::vector<Neuron*> neurons_;  // HIDDEN and OUTPUT neurons only
    std::unordered_map<int, Neuron*> neurons_index_;
    std::vector<Edge*> edges_;      // edges
    std::unordered_map<int, Edge*> edges_index_;

    std::vector<Neuron*> inputs_;   // not contained in |neurons|
    std::vector<Neuron*> outputs_;  // contained in |neurons|

    int max_neuron_id_ = 0;

    Random& random_;
};

#endif // NET_H
