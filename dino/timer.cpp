#include "timer.h"
#include "game.h"

Timer::Timer(Callback cb)
    : cb_(cb) {

}


void Timer::start(sf::Time time) {
    time_ = time;

    isStarted_ = true;
    runOnce_ = false;
    clock_.restart();
}

void Timer::startOnce(sf::Time time) {
    time_ = time;

    isStarted_ = true;
    runOnce_ = true;
    clock_.restart();
}

void Timer::stop() {
    isStarted_ = false;
}

void Timer::update() {
    if (!isStarted_)
        return;

    if (clock_.getElapsedTime() > time_) {
        clock_.restart();
        isStarted_ = !runOnce_;

        cb_(*this);
    }
}
