#include "ScoreManager.h"
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager() : currentScore(0), highScore(0) {
    loadHighScore(); // Tải điểm cao nhất từ tệp khi khởi tạo
}

ScoreManager::~ScoreManager() {
    saveHighScore(); // Lưu điểm cao nhất khi đối tượng bị hủy
}

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

void ScoreManager::loadHighScore() {
    std::ifstream file(highScoreFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0; // Nếu không có tệp, đặt điểm cao nhất là 0
    }
}

void ScoreManager::saveHighScore() const {
    std::ofstream file(highScoreFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
    } else {
        std::cerr << "Failed to save high score to file: " << highScoreFile << std::endl;
    }
}
