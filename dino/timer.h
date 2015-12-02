#ifndef TIMER_H
#define TIMER_H

#include <functional>
#include <SFML/Graphics.hpp>

class Timer {
public:
    using Callback = std::function<void(Timer&)>;

    Timer(Callback cb);
    void start(float seconds);
    void startOnce(float seconds);
    void stop();

    void update(float dt);

private:
    float elapsed_;

    float time_;
    bool runOnce_ = false;
    Callback cb_;

    bool isStarted_ = false;
};

#endif // TIMER_H
