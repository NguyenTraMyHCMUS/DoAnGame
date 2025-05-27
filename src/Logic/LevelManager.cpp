#include "LevelManager.h"

LevelManager::LevelManager() : _currentLevel(1), _linesCleared(0) {}

void LevelManager::increaseLevel() {
    _currentLevel++;
}

void LevelManager::addClearedLines(int lines) {
    _linesCleared += lines;
}

int LevelManager::getLevel() const {
    return _currentLevel;
}

int LevelManager::getLinesCleared() const {
    return _linesCleared;
}

void LevelManager::reset() {
    _currentLevel = 1;
    _linesCleared = 0;
}

void LevelManager::resetLinesCleared() {
    _linesCleared = 0;
}
