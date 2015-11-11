#ifndef PLAYER_H
#define PLAYER_H

#include "rectangular_object.h"

class Obstacle;

class Player : public RectangularObject {
public:
    enum class State {
        RUN, JUMP
    };

    Player(World& world);

    virtual void update(float dt) override;

    void jump();    
    bool passedObstacle(Obstacle &obstacle) const;

private:
    State state_ = State::RUN;
    sf::Clock jumpClock_;

    sf::Vector2f defaultPos_;
};

#endif // PLAYER_H
