#ifndef WORLD_H
#define WORLD_H

#include <deque>

#include "obstacle.h"
#include "player.h"
#include "timer.h"

class World {
public:
    World(sf::Vector2f size);

    void draw(sf::RenderWindow& window) const;
    void update(float dt);

    void createObstacle();

private:
    sf::Vector2f size_;
    double scrollSpeed_ = 100;

    double groundLevel_ = 500;

    Timer obstacleCreationTimer_;

    Player player_;
    std::deque<Obstacle> obstables_;
};

#endif // WORLD_H
