#include "triple_pattern.h"

TriplePattern::TriplePattern(World& world) {
    for (int i = 0; i < 3; ++i) {
        auto obstacle = std::make_shared(new Obstacle(world));
        obstacle->move(sf::Vector2f(world.size().x + i * 30, world.groundLevel()));
        obstacles_.push_back(o1);
    }
}

