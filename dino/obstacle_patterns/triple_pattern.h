#ifndef TRIPLE_PATTERN_H
#define TRIPLE_PATTERN_H

#include "obstacle_pattern.h"

class TriplePattern : public ObstaclePattern {
public:
    TriplePattern(World& world);


    virtual sf::Vector2f getPosition() const override;
};

#endif // TRIPLE_PATTERN_H
