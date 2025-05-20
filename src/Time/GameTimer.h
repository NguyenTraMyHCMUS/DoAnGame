#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <SFML/System/Clock.hpp>

/**
 * @class GameTimer
 * @brief Quản lý thời gian cập nhật game (Single Responsibility)
 */
class GameTimer {
private:
    sf::Clock clock;
    float timer;
    float delay;

public:
    GameTimer(float initialDelay = 0.3f);
    
    void update();
    bool shouldUpdate();
    void restart();
    
    void setDelay(float value);
    float getDelay() const;
    float getTimer() const;
};

#endif