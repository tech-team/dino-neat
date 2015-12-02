#include "timer.h"
#include "game.h"

Timer::Timer(Callback cb)
    : cb_(cb) {

}


void Timer::start(float seconds) {
    time_ = seconds;

    isStarted_ = true;
    runOnce_ = false;
    elapsed_ = 0;
}

void Timer::startOnce(float seconds) {
    time_ = seconds;

    isStarted_ = true;
    runOnce_ = true;
    elapsed_ = 0;
}

void Timer::stop() {
    isStarted_ = false;
}

void Timer::update(float dt) {
    if (!isStarted_)
        return;

    elapsed_ += dt;

    if (elapsed_ > time_) {
        elapsed_ = 0;
        isStarted_ = !runOnce_;

        cb_(*this);
    }
}
