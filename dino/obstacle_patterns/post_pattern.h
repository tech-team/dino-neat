#ifndef POSTPATTERN_H
#define POSTPATTERN_H

#include "obstacle_patterns/obstacle_pattern.h"

class PostPattern : public ObstaclePattern {
public:
    PostPattern(World& world);

    virtual sf::Vector2f getPosition() const override;
};

#endif // POSTPATTERN_H
