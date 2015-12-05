#include "random.h"

#include <chrono>

Random::Random() {
    generator_.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Random::Random(uint32_t seed) {
    generator_.seed(seed);
}

int Random::nextInt(int min, double max) {
    std::uniform_int_distribution<int> unif(min, max);
    return unif(generator_);
}

double Random::nextDouble(double min, double max) {
    std::uniform_real_distribution<double> unif(min, max);
    return unif(generator_);
}
