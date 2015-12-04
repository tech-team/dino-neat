#include "overlay.h"

#include "utils.h"

Overlay::Overlay() {
    if (!font_.loadFromFile("resources/sansation.ttf"))
        throw "Unable to load font";

    score_message_.setFont(font_);
    score_message_.setCharacterSize(20);
    score_message_.setPosition(10.f, 10.f);
    score_message_.setColor(sf::Color::Cyan);

    time_scale_message_.setFont(font_);
    time_scale_message_.setCharacterSize(20);
    time_scale_message_.setPosition(150.f, 10.f);
    time_scale_message_.setColor(sf::Color::Cyan);

    debug_info_message_.setFont(font_);
    debug_info_message_.setCharacterSize(20);
    debug_info_message_.setPosition(400.f, 10.f);
    debug_info_message_.setColor(sf::Color::Yellow);

    set_score(0);
    set_time_scale(0);
}

void Overlay::draw(sf::RenderWindow& window) const {
    window.draw(score_message_);
    window.draw(time_scale_message_);
    window.draw(debug_info_message_);
}

void Overlay::set_score(int score) {
    auto str = utils::format("Score: %d", score);
    score_message_.setString(str);
}

void Overlay::set_time_scale(float time_scale) {
    auto str = utils::format("Time scale: %0.1f", time_scale);
    time_scale_message_.setString(str);
}

void Overlay::set_debug_info(const std::string& debug_info) {
    debug_info_message_.setString(debug_info);
}
