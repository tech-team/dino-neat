#ifndef PLAYER_H
#define PLAYER_H

#include "rectangular_object.h"

#include "rectangular_obstacle.h"

class Obstacle;

class Player : public RectangularObject {
public:
    enum class State {
        RUN, JUMP_PREPARE, JUMP
    };

    Player(World& world);

    virtual void update(float dt) override;

    void jumpStart();
    void jumpEnd();

    bool passedObstacle(Obstacle& obstacle) const;
    bool passedObstacle(RectangularObstacle& obstacle) const;

private:
    State state_ = State::RUN;
    sf::Clock jumpClock_;
    float initial_jump_speed_ = 60;

    sf::Vector2f defaultPos_;

    static constexpr float MIN_JUMP_SPEED = 60;
    static constexpr float MAX_JUMP_SPEED = 80;
};

#endif // PLAYER_H
