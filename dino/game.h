#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "world.h"


class Game {
public:
    Game(int fps);

    void startEventLoop();

    void update(float dt);
    void draw();

    void onKeyPressed(sf::Event& event);

private:
    static constexpr int gameWidth_ = 800;
    static constexpr int gameHeight_ = 600;
    sf::RenderWindow window_;


    World world_;
    bool gameOver_ = false;
};

#endif // GAME_H
