#include "ScoreManager.h"

ScoreManager::ScoreManager() : currentScore(0), highScore(0) {}

void ScoreManager::addScore(int points) {
    currentScore += points;
    if (currentScore > highScore) {
        highScore = currentScore;
    }
}

int ScoreManager::getScore() const {
    return currentScore;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::reset() {
    currentScore = 0;
}
