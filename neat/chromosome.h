#ifndef CHROMOSOME_H
#define CHROMOSOME_H

class Net;
class Chromosome {
public:
    Chromosome(Net* net);
    Chromosome(const Chromosome& other) = delete;
    Chromosome(Chromosome&& ch);

    Chromosome& operator=(const Chromosome& ch) = delete;
    Chromosome& operator=(Chromosome&& ch);

    ~Chromosome();

    Net* net() const;
    double fitness() const;

    void set_fitness(double fitness);

    void mutateWeights(int innovation);
    void mutateStructure(int innovation);
    static Chromosome crossover(const Chromosome& ch1, const Chromosome& ch2);

private:
    void mutateAddConnection(int innovation);
    void mutateAddNode(int innovation);

    Net* net_;
    double fitness_ = 0;
};

#endif // CHROMOSOME_H
