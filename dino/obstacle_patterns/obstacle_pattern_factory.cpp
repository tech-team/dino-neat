#include "obstacle_pattern_factory.h"

#include <random>

#include "obstacle_patterns/triple_pattern.h"
#include "obstacle_patterns/post_pattern.h"
#include "obstacle_patterns/offsetted_triple_pattern.h"
#include "obstacle_patterns/vertical_triple_pattern.h"

std::shared_ptr<ObstaclePattern> ObstaclePatternFactory::createRandom(World& world) {
    static std::vector<std::function<std::shared_ptr<ObstaclePattern>(World& world)>> generators = {
        [] (World& world) {
            return std::make_shared<TriplePattern>(world);
        },
        [] (World& world) {
            return std::make_shared<PostPattern>(world);
        },
        [] (World& world) {
            return std::make_shared<OffsettedTriplePattern>(world);
        },
        [] (World& world) {
            return std::make_shared<VerticalTriplePattern>(world);
        }
    };

    return generators[rand() % generators.size()](world);
}



