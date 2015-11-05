#include "game.h"

#include <iostream>
#include <thread>

Game::Game(int fps) {
    frame_size_ = std::chrono::milliseconds(int(1000.0 / fps));
}

void Game::start() {
    using namespace std::chrono;
    using delta_t = std::chrono::duration<double, std::ratio<1, 1>>;

    auto start = system_clock::now();
    auto end = system_clock::now();

    while (!gameOver_) {
        double time_since_last_call =
                duration_cast<delta_t>(system_clock::now() - start).count();

        start = system_clock::now();
        tick(time_since_last_call);
        end = system_clock::now();

        auto dt = end - start;
        std::this_thread::sleep_for(frame_size_ - dt);
    }
}

/**
 * @brief This function should be called evenly by time
 * (regardless to the amount of time it will require to calculate world change)
 *
 * @param dt - will be normally ~1000 / fps, but can be bigger in case of lags
 */
void Game::tick(double dt) {
    static int pos = 0;
    pos += dt * 10;
    std::cout << "Tick: " << dt << "| pos: " << pos << std::endl;

    // payload time
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
