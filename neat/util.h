#ifndef UTIL
#define UTIL

#include <random>
#include <vector>
#include <unordered_map>

namespace neat {

struct enum_class_hash {
    template <typename T>
    std::size_t operator()(T t) const     {
        return static_cast<std::size_t>(t);
    }
};

template <typename Key>
using HashType = typename std::conditional<std::is_enum<Key>::value, enum_class_hash, std::hash<Key>>::type;

template <typename Key, typename T>
using unordered_map = std::unordered_map<Key, T, HashType<Key>>;
}

enum class RandomGeneratorId {
    GENETIC, GAME
};

class RandomGenerator {
public:
    static RandomGenerator& instance(RandomGeneratorId id);
    void srand(uint32_t seed);
    double rand(double min = 0.0, double max = 1.0);
    int randInt(int min, int max);

    RandomGenerator();
private:

    static neat::unordered_map<RandomGeneratorId, RandomGenerator> generators_;

    std::mt19937 generator_;
};

template <typename T>
std::vector<T>& vectorSlice(std::vector<T>& vec, size_t start, size_t end) {
    std::vector<T>(vec.begin() + start, vec.begin() + end).swap(vec);
    return vec;
}


#endif // UTIL

