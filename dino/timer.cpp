#include "timer.h"
#include "game.h"

Timer::Timer(sf::Time time, Callback cb)
    : time_(time), cb_(cb) {

}


void Timer::start() {
    isStarted_ = true;
    runOnce_ = false;
    clock_.restart();
}

void Timer::startOnce() {
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
