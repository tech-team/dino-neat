#ifndef WORLD_H
#define WORLD_H

#include <deque>
#include <memory>

#include "timer.h"


class Obstacle;
class Player;
class WorldRasterizer;
class Game;

class World {
public:
    World(Game* game, sf::Vector2f size);

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

    float randomTime(double min, double max) const;

    const Game* game() const;

private:
    const Game* game_;

    sf::Vector2f size_;
    double scrollSpeed_ = 20;
    double groundLevel_ = 500;

    int score_ = 0;

    Timer obstacle_creation_timer_;
    Timer score_timer_;

    std::shared_ptr<Player> player_;
    std::deque<std::shared_ptr<Obstacle>> obstables_;

    friend class WorldRasterizer;
};

#endif // WORLD_H
