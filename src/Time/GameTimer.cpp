#include "GameTimer.h"

GameTimer::GameTimer(float initialDelay) : timer(0.0f), delay(initialDelay) {
}

void GameTimer::update() {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
}

bool GameTimer::shouldUpdate() {
    if (timer > delay) {
        timer = 0;
        return true;
    }
    return false;
}

void GameTimer::restart() {
    clock.restart();
    timer = 0;
}

void GameTimer::setDelay(float value) {
    delay = value;
}

float GameTimer::getDelay() const {
    return delay;
}

float GameTimer::getTimer() const {
    return timer;
}