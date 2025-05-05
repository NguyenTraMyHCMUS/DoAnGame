#include "LevelManager.h"

LevelManager::LevelManager() : currentLevel(1), linesCleared(0) {}

void LevelManager::increaseLevel() {
    currentLevel++;
}

void LevelManager::addClearedLines(int lines) {
    linesCleared += lines;
}

int LevelManager::getLevel() const {
    return currentLevel;
}

int LevelManager::getLinesCleared() const {
    return linesCleared;
}

void LevelManager::reset() {
    currentLevel = 1;
    linesCleared = 0;
}

void LevelManager::resetLinesCleared() {
    linesCleared = 0; // Chỉ đặt lại số dòng đã xóa
}
