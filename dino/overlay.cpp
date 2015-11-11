#include "overlay.h"

#include "utils.h"

Overlay::Overlay() {
    if (!font_.loadFromFile("resources/sansation.ttf"))
        throw "Unable to load font";

    scoreMessage_.setFont(font_);
    scoreMessage_.setCharacterSize(20);
    scoreMessage_.setPosition(10.f, 10.f);
    scoreMessage_.setColor(sf::Color::Cyan);
    set_score(0);
}

void Overlay::draw(sf::RenderWindow& window) const {
    window.draw(scoreMessage_);
}

void Overlay::set_score(int score) {
    auto str = utils::format("Score: %d", score);
    scoreMessage_.setString(str);
}
