#ifndef OVERLAY_H
#define OVERLAY_H

#include <SFML/Graphics.hpp>
#include <string>

class Overlay {
public:
    Overlay();
    void draw(sf::RenderWindow& window) const;

    void set_score(int score);
    void set_time_scale(float time_scale);
    void set_debug_info(const std::string& info);
private:
    sf::Font font_;

    sf::Text score_message_;
    sf::Text time_scale_message_;
    sf::Text debug_info_message_;
};

#endif // OVERLAY_H
