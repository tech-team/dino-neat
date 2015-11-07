#ifndef TIMER_H
#define TIMER_H

#include <functional>
#include <SFML/Graphics.hpp>

class Timer {
public:
    using Callback = std::function<void(Timer&)>;

    Timer(sf::Time time, Callback cb);
    void start();
    void startOnce();
    void stop();

    void update();

private:
    sf::Clock clock_;
    sf::Time time_;
    bool runOnce_ = false;
    Callback cb_;

    bool isStarted_ = false;
};

#endif // TIMER_H
