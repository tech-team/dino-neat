#ifndef NET_H
#define NET_H

#include <vector>

class Neuron;
class Edge;

class Net
{
public:
    Net();

private:
    std::vector<Neuron*> neurons_;  // HIDDEN and OUTPUT neurons only
    std::vector<Edge*> edges_;      // edges

    std::vector<Neuron*> inputs_;   // not contained in |neurons|
    std::vector<Neuron*> outputs_;  // contained in |neurons|
};

#endif // NET_H
