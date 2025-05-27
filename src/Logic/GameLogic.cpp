#include "GameLogic.h"
#include "../Entities/Factories/TetrominoFactory.h"
#include <algorithm>

GameLogic::GameLogic(Field& field, std::unique_ptr<Tetromino>& tetromino, 
                     NextTetrominoPreview& nextPreview, ScoreManager& scoreManager, 
                     LevelManager& levelManager, float& delay)
    : _field(field), _tetromino(tetromino), _nextPreview(nextPreview), 
      _scoreManager(scoreManager), _levelManager(levelManager), _delay(delay) {
}

bool GameLogic::update(int dx, bool rotate) {
    bool gameOver = false;

    moveTetrominoHorizontally(dx);
    rotateTetrominoIfPossible(rotate);

    if (!moveTetrominoDown()) {
        auto temp = _nextPreview.cloneNext();
        if (!temp->isValid(_field)) {
            gameOver = true;
        } else {
            handleLineClearing();
            _tetromino = _nextPreview.getNext();
            _nextPreview.generateNext();
        }
    }

    return !gameOver;
}

bool GameLogic::moveTetrominoHorizontally(int dx) {
    if (dx == 0) return false;

    _tetromino->backupState();
    _tetromino->move(dx);
    if (!_tetromino->isValid(_field)) {
        _tetromino->restoreState();
        return false;
    }
    return true;
}

bool GameLogic::rotateTetrominoIfPossible(bool rotate) {
    if (!rotate) return false;

    _tetromino->backupState();
    _tetromino->rotate();
    if (!_tetromino->isValid(_field)) {
        _tetromino->restoreState();
        return false;
    }
    return true;
}

bool GameLogic::moveTetrominoDown() {
    _tetromino->backupState();
    _tetromino->fall();

    if (!_tetromino->isValid(_field)) {
        _tetromino->restoreState();
        _tetromino->lock(_field);
        return false;
    }

    return true;
}

bool GameLogic::isGameOver() {
    auto temp = _nextPreview.cloneNext();
    return !temp->isValid(_field);
}

void GameLogic::handleLineClearing() {
    int clearedLines = _field.clearLines();

    if (clearedLines > 0) {
        int points = clearedLines * 10 * clearedLines;
        _scoreManager.addScore(points);
        _levelManager.addClearedLines(clearedLines);

        if (_scoreManager.getScore() >= _levelManager.getLevel() * 100) {
            _levelManager.increaseLevel();
            _delay = std::max(0.1f, _delay - 0.02f);
        }
    }
}

void GameLogic::resetGame() {
    _field.clear();
    _tetromino = TetrominoFactory::createRandomTetromino();
    _nextPreview.reset();
    _scoreManager.reset();
    _levelManager.reset();
    _delay = 0.3f;
}
