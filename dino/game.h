#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "world.h"


class Game {
public:
    static constexpr float TIME_SCALE = 20;

    Game(int fps);

    void startEventLoop();

    void update(float dt);
    void draw();

    void onKeyPressed(sf::Event& event);

    void logRaster();

private:
    static constexpr int game_width_ = 800;
    static constexpr int game_height_ = 600;
    sf::RenderWindow window_;

    World world_;
    bool game_over_ = false;
};

#endif // GAME_H
