#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

ScoreManager::ScoreManager() : _currentScore(0), _highScore(0) {
    loadHighScore();
}

ScoreManager::~ScoreManager() {
    saveHighScore();
}

void ScoreManager::addScore(int points) {
    _currentScore += points;
    if (_currentScore > _highScore) {
        _highScore = _currentScore;
    }
}

int ScoreManager::getScore() const {
    return _currentScore;
}

int ScoreManager::getHighScore() const {
    return _highScore;
}

void ScoreManager::reset() {
    _currentScore = 0;
}

void ScoreManager::loadHighScore() {
    _topScores.clear();
    std::ifstream file(_highScoreFile);
    _highScore = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            int score;
            if (iss >> name >> score) {
                _topScores.push_back({name, score});
                if (score > _highScore) _highScore = score;
            }
        }
        file.close();
    }
}

void ScoreManager::saveHighScore() const {
    std::ofstream file(_highScoreFile);
    if (file.is_open()) {
        for (const auto& entry : _topScores) {
            file << entry.first << " " << entry.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Failed to save high score to file: " << _highScoreFile << std::endl;
    }
}

void ScoreManager::submitScore(const std::string& name) {
    _topScores.push_back({name, _currentScore});
    std::sort(_topScores.begin(), _topScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    if (_topScores.size() > 3) _topScores.resize(3);
    _highScore = _topScores.empty() ? 0 : _topScores.front().second;
    saveHighScore();
}

std::vector<std::pair<std::string, int>> ScoreManager::getTopScores(int n) const {
    std::vector<std::pair<std::string, int>> result;
    for (int i = 0; i < n && i < (int)_topScores.size(); ++i) {
        result.push_back(_topScores[i]);
    }
    return result;
}
