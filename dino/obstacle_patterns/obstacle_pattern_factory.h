#ifndef OBSTACLEPATTERNFACTORY_H
#define OBSTACLEPATTERNFACTORY_H

#include <functional>
#include <vector>
#include <memory>

#include "obstacle_patterns/obstacle_pattern.h"

class ObstaclePatternFactory {
public:
    ObstaclePatternFactory() = delete;

    static std::shared_ptr<ObstaclePattern> createRandom(World& world);
};

#endif // OBSTACLEPATTERNFACTORY_H
