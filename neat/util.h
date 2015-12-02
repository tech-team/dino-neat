#ifndef UTIL
#define UTIL

#include <random>
#include <vector>

class RandomGenerator {
public:
    static RandomGenerator& instance();
    void srand(uint32_t seed);
    double rand(double min = 0.0, double max = 1.0);
    int randInt(int min, int max);

private:
    RandomGenerator();

    std::mt19937 generator_;
};

template <typename T>
std::vector<T>& vectorSlice(std::vector<T>& vec, size_t start, size_t end) {
    std::vector<T>(vec.begin() + start, vec.begin() + end).swap(vec);
    return vec;
}


#endif // UTIL

