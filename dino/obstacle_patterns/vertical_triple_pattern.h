#ifndef VERTICAL_TRIPLE_PATTERN_H
#define VERTICAL_TRIPLE_PATTERN_H

#include "obstacle_pattern.h"

class VerticalTriplePattern : public ObstaclePattern {
public:
    VerticalTriplePattern(World& world);


    virtual sf::Vector2f getPosition() const override;
};

#endif // VERTICAL_TRIPLE_PATTERN_H
