#ifndef PLAYER_H
#define PLAYER_H

#include "world_object.h"

class Player : public WorldObject {
public:
    Player();

    virtual const sf::Drawable& getDrawable() const override;
    virtual void update(float dt) override;
    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;

private:
    sf::RectangleShape shape_;
};

#endif // PLAYER_H
