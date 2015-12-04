#include "util.h"

#include <chrono>

neat::unordered_map<RandomGeneratorId, RandomGenerator> RandomGenerator::generators_;

RandomGenerator::RandomGenerator()
    : generator_(std::chrono::system_clock::now().time_since_epoch().count()) {

}

RandomGenerator& RandomGenerator::instance(RandomGeneratorId id) {
    auto gen_it = generators_.find(id);
    if (gen_it != generators_.end()) {
        return gen_it->second;
    } else {
        generators_[id] = RandomGenerator();
        return generators_[id];
    }
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

