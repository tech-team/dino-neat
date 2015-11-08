#ifndef PLAYER_H
#define PLAYER_H

#include "world_object.h"

class Player : public WorldObject {
public:
    enum class State {
        RUN, JUMP
    };

    Player(World& world);

    virtual const sf::Drawable& getDrawable() const override;
    virtual void update(float dt) override;
    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;
    virtual void rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const override;

    void jump();

private:
    sf::RectangleShape shape_;
    State state_ = State::RUN;
    sf::Clock jumpClock_;

    sf::Vector2f defaultPos_;
};

#endif // PLAYER_H
