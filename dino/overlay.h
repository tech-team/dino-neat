#ifndef OVERLAY_H
#define OVERLAY_H

#include <SFML/Graphics.hpp>

class Overlay {
public:
    Overlay();
    void draw(sf::RenderWindow& window) const;

    void set_score(int score);
    void set_time_scale(float time_scale);
private:
    sf::Font font_;
    sf::Text score_message_;
    sf::Text time_scale_message_;
};

#endif // OVERLAY_H
