#ifndef WORLD_H
#define WORLD_H

#include <deque>
#include <memory>

#include "obstacle.h"
#include "player.h"
#include "timer.h"
#include "world_rasterizer.h"

class Obstacle;

class World {
public:
    World(sf::Vector2f size);

    void draw(sf::RenderWindow& window) const;

    /**
     * @brief Returns true in case of game over
     * @param dt
     * @return game_over
     */
    bool update(float dt);

    void createObstacle();

    void playerJump();

    double groundLevel() const;
    const sf::Vector2f& size() const;

    int score() const;

    std::vector<int> getWorldRaster() const;

    bool isPointOnScreen(int i, int j) const;

    sf::Time randomTime(double min, double max) const;

private:
    sf::Vector2f size_;
    double scrollSpeed_ = 20;
    double groundLevel_ = 500;

    int score_ = 0;

    Timer obstacleCreationTimer_;

    std::shared_ptr<Player> player_;
    std::deque<std::shared_ptr<Obstacle>> obstables_;

    friend class WorldRasterizer;
};

#endif // WORLD_H
