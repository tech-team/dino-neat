#ifndef UTIL
#define UTIL

#include <random>

class RandomGenerator {
public:
    static RandomGenerator& instance();
    void srand(uint32_t seed);
    double rand(double min = 0.0, double max = 1.0);

private:
    RandomGenerator();

    std::mt19937 generator_;
};


#endif // UTIL

