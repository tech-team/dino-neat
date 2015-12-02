#ifndef OFFSETTED_TRIPLE_PATTERN_H
#define OFFSETTED_TRIPLE_PATTERN_H

#include "obstacle_pattern.h"

class OffsettedTriplePattern : public ObstaclePattern {
public:
    OffsettedTriplePattern(World& world);


    virtual sf::Vector2f getPosition() const override;
};

#endif // OFFSETTED_TRIPLE_PATTERN_H
