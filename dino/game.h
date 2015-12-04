#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <functional>
#include <memory>
#include <vector>

#include "world.h"
#include "overlay.h"

class Game {
public:
    Game(int time_scale);

    void subscribeOnUpdate(std::function<void()> update_listener);

    void startEventLoop();
    void stop();

    void update(float dt);
    void draw();

    void onKeyPressed(sf::Event& event);
    void onKeyReleased(sf::Event& event);

    void restart();

    void logRaster();
    std::vector<double> rasterizeWorld();

    int score() const;
    int is_game_over() const;

    float time_scale() const;
    void set_time_scale(float time_scale);
    void set_debug_info(const std::string& debug_info);

private:
    static constexpr int game_width_ = 800;
    static constexpr int game_height_ = 600;
    sf::RenderWindow window_;

    std::shared_ptr<World> world_;
    Overlay overlay_;
    bool game_over_ = false;

    float time_scale_;

    std::function<void()> update_listener_;
};

#endif // GAME_H
