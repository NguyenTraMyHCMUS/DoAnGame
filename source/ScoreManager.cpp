#include "ScoreManager.h"

void ScoreManager::addObserver(const std::function<void(int)>& observer) {
    observers.push_back(observer);
}

void ScoreManager::notifyObservers() {
    for (const auto& observer : observers) {
        observer(score);
    }
}

void ScoreManager::addScore(int points) {
    score += points;
    notifyObservers();
}

int ScoreManager::getScore() const {
    return score;
}
