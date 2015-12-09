#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "common/random.h"
#include "neat_config.h"

class Net;
class InnovationNumberGetter;
class Chromosome {
public:
    Chromosome(Random& random, const NeatConfig& conf, Net* net);
    Chromosome(const Chromosome& other) = delete;
    Chromosome(Chromosome&& ch);

    Chromosome& operator=(const Chromosome& ch) = delete;
    Chromosome& operator=(Chromosome&& ch);

    ~Chromosome();

    Net* net() const;
    double fitness() const;

    void set_fitness(double fitness);

    void mutateWeights();
    void mutateStructure(InnovationNumberGetter* innov_getter);
    void mutateAddConnection(InnovationNumberGetter* innov_getter);
    void mutateAddNode(InnovationNumberGetter* innov_getter);

    static Chromosome crossover(const Chromosome& ch1, const Chromosome& ch2);
    static double distance(const Chromosome& ch1, const Chromosome& ch2);

private:
    Net* net_;
    double fitness_ = 0;

    const NeatConfig& conf_;

    Random& random_;
};

#endif // CHROMOSOME_H
