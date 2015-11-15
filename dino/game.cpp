#include "game.h"

#include <iostream>
#include <thread>

#include "world_rasterizer.h"

Game::Game(int fps)
    : window_(sf::VideoMode(game_width_, game_height_, 32),
              "Dino NEAT",
              sf::Style::Titlebar | sf::Style::Close) {
    window_.setFramerateLimit(30);

    restart();
}

void Game::subscribeOnUpdate(std::function<void()> update_listener) {
    update_listener_ = update_listener;
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

        if(update_listener_)
            update_listener_();

        window_.clear(sf::Color(0, 0, 0));
        draw();
        window_.display();
    }
}

void Game::stop() {
    window_.close();
}

void Game::update(float dt) {
    if (!game_over_) {
        game_over_ = world_->update(dt);
        if (game_over_) {
            std::cout << "Game over: " << world_->score() << std::endl;
        }

        overlay_.set_score(world_->score());
    } else {

    }
}

void Game::draw() {
    if (!game_over_ || true) {
        world_->draw(window_);
        overlay_.draw(window_);
    } else {

    }
}

void Game::onKeyPressed(sf::Event& event) {
    switch (event.key.code) {
    case sf::Keyboard::Escape:
        window_.close();
        break;

    case sf::Keyboard::Space:
        world_->playerJump();
        break;

    case sf::Keyboard::R:
        restart();
        break;

    case sf::Keyboard::L:
        logRaster();
        break;

    default:

        break;
    }
}

void Game::restart() {
    world_.reset(new World(sf::Vector2f(game_width_, game_height_)));
    game_over_ = false;
}

void Game::logRaster() {
    WorldRasterizer rasterizer(*world_);
    PlainWorld raster = rasterizer.rasterize();
    double scaleFactor = rasterizer.scaleFactor();

    for (int j = 0; j < game_height_ - scaleFactor; j += scaleFactor) {
        for (int i = 0; i < game_width_ - scaleFactor; i += scaleFactor) {
            //std::cout << ". type=" << raster.at(rasterizer.to1d(i, j)) << std::endl;
            std::cout << raster.at(rasterizer.to1d(i, j)) << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<double> Game::rasterizeWorld() {
    WorldRasterizer rasterizer(*world_);
    PlainWorld raster = rasterizer.rasterize();

    return raster;
}

int Game::score() const {
    return world_->score();
}

int Game::is_game_over() const {
    return game_over_;
}
