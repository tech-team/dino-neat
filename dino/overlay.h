#ifndef OVERLAY_H
#define OVERLAY_H

#include <SFML/Graphics.hpp>

class Overlay
{
public:
    Overlay();
    void draw(sf::RenderWindow& window) const;

    void set_score(int score);
private:
    sf::Font font_;
    sf::Text scoreMessage_;
};

#endif // OVERLAY_H
