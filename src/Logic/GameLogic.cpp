#include "GameLogic.h"
#include "../Entities/TetrominoFactory.h"
#include <algorithm>

GameLogic::GameLogic(Field& field, std::unique_ptr<Tetromino>& tetromino, 
                     NextTetrominoPreview& nextPreview, ScoreManager& scoreManager, 
                     LevelManager& levelManager, float& delay)
    : field(field), tetromino(tetromino), nextPreview(nextPreview), 
      scoreManager(scoreManager), levelManager(levelManager), delay(delay) {
}

bool GameLogic::update(int dx, bool rotate) {
    bool gameOver = false;
    
    moveTetrominoHorizontally(dx);
    rotateTetrominoIfPossible(rotate);
    
    if (!moveTetrominoDown()) {
        // Khối đã chạm đất, xử lý tiếp
        auto temp = nextPreview.cloneNext();
        if (!temp->isValid(field)) {
            // Game over
            gameOver = true;
        } else {
            handleLineClearing();
            tetromino = nextPreview.getNext();
            nextPreview.generateNext();
        }
    }
    
    return !gameOver;
}

bool GameLogic::moveTetrominoHorizontally(int dx) {
    if (dx == 0) return false;
    
    tetromino->backupState();
    tetromino->move(dx);
    if (!tetromino->isValid(field)) {
        tetromino->restoreState();
        return false;
    }
    return true;
}

bool GameLogic::rotateTetrominoIfPossible(bool rotate) {
    if (!rotate) return false;
    
    tetromino->backupState();
    tetromino->rotate();
    if (!tetromino->isValid(field)) {
        tetromino->restoreState();
        return false;
    }
    return true;
}

bool GameLogic::moveTetrominoDown() {
    tetromino->backupState();
    tetromino->fall();
    
    if (!tetromino->isValid(field)) {
        tetromino->restoreState();
        tetromino->lock(field);
        return false;
    }
    
    return true;
}

bool GameLogic::isGameOver() {
    auto temp = nextPreview.cloneNext();
    return !temp->isValid(field);
}

void GameLogic::handleLineClearing() {
    int clearedLines = field.clearLines();
    
    if (clearedLines > 0) {
        // Tính điểm theo số dòng xóa (công thức điểm)
        int points = clearedLines * 10 * clearedLines;
        scoreManager.addScore(points);
        levelManager.addClearedLines(clearedLines);
        
        // Tăng cấp độ nếu đủ điểm
        if (scoreManager.getScore() >= levelManager.getLevel() * 100) {
            levelManager.increaseLevel();
            
            // Giảm delay khi cấp độ tăng, nhưng không để delay quá nhỏ
            delay = std::max(0.1f, delay - 0.02f);
        }
    }
}

void GameLogic::resetGame() {
    field.clear();
    tetromino = TetrominoFactory::createRandomTetromino();
    nextPreview.reset();
    scoreManager.reset();
    levelManager.reset();
    delay = 0.3f;
}