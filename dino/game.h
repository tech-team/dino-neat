#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "world.h"


class Game {
public:
    Game(int fps);

    void start();
    void tick(double dt);

private:
    World world_;
    bool gameOver_ = false;
    std::chrono::milliseconds frame_size_;
};

#endif // GAME_H
