#include "game.h"

#include <iostream>
#include <thread>

Game::Game(int fps)
    : window_(sf::VideoMode(gameWidth_, gameHeight_, 32),
              "Dino NEAT",
              sf::Style::Titlebar | sf::Style::Close),
      world_(sf::Vector2f(gameWidth_, gameHeight_)) {

    window_.setFramerateLimit(30);
}

void Game::startEventLoop() {
    sf::Clock clock;
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window_.close();
                break;
            case sf::Event::KeyPressed:
                onKeyPressed(event);
                break;
            default:

                break;
            }
        }

        float dt = clock.restart().asSeconds() * TIME_SCALE;
        update(dt);

        window_.clear(sf::Color(0, 0, 0));
        draw();
        window_.display();

        //sf::Image img = window_.capture();
        //img.getPixel(0, 0);
    }
}

void Game::update(float dt) {
    world_.update(dt);
}

void Game::draw() {
    world_.draw(window_);
}

void Game::onKeyPressed(sf::Event& event) {
    switch (event.key.code) {
    case sf::Keyboard::Escape:
        window_.close();
        break;

    case sf::Keyboard::Space:
        world_.playerJump();
        break;

    default:

        break;
    }
}
