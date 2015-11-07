#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <SFML/Graphics.hpp>

class WorldObject {
public:
    WorldObject();

    virtual const sf::Drawable& getDrawable() const = 0;
    virtual void update(float dt) = 0;

    virtual void moveTo(sf::Vector2f pos) = 0;
    virtual void move(sf::Vector2f delta) = 0;
private:

};

#endif // WORLDOBJECT_H
