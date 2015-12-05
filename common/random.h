#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
    Random();
    Random(uint32_t seed);

    int nextInt(int min, double max);
    double nextDouble(double min = 0.0, double max = 1.0);

private:
    std::mt19937 generator_;
};

#endif // RANDOM_H
