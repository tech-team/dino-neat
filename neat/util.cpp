#include "util.h"

#include <chrono>

RandomGenerator::RandomGenerator()
    : generator_(std::chrono::system_clock::now().time_since_epoch().count()) {

}

RandomGenerator& RandomGenerator::instance() {
    static RandomGenerator g;
    return g;
}

void RandomGenerator::srand(uint32_t seed) {
    generator_.seed(seed);
}

double RandomGenerator::rand(double min, double max) {
    std::uniform_real_distribution<double> unif(min, max);
    return unif(generator_);
}

int RandomGenerator::randInt(int min, int max) {
    std::uniform_int_distribution<int> unif(min, max);
    return unif(generator_);
}

