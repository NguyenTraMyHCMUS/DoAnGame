#include "Game.h"
#include "TetrominoFactory.h"
#include "MainMenuState.h"
#include "GameOverState.h"
#include "PlayingState.h"
#include "NextTetrominoPreview.h"

#include <iostream>

using namespace sf;

Game::Game() : window(VideoMode(320, 480), "Tetris") {
    tetromino = TetrominoFactory::createRandomTetromino();

    // Khối tiếp theo
    tetromino = nextPreview.getNext();       // lấy khối đầu tiên từ preview
    nextPreview.generateNext();              // tạo khối tiếp theo tiếp theo

    // Khởi tạo trạng thái ban đầu là MainMenu
    currentState = std::make_unique<MainMenuState>(*this);
}

// Getter và Setter cho t1
const Texture& Game::getT1() const {
    return t1;
}

void Game::setT1(const Texture& texture) {
    t1 = texture;
}

// Getter và Setter cho t2
const Texture& Game::getT2() const {
    return t2;
}

void Game::setT2(const Texture& texture) {
    t2 = texture;
}

// Getter và Setter cho t3
const Texture& Game::getT3() const {
    return t3;
}

void Game::setT3(const Texture& texture) {
    t3 = texture;
}

// Getter và Setter cho s
Sprite& Game::getSprite() {
    return s;
}

void Game::setSprite(const Sprite& sprite) {
    s = sprite;
}

// Getter và Setter cho background
const Sprite& Game::getBackground() const {
    return background;
}

void Game::setBackground(const Sprite& sprite) {
    background = sprite;
}

// Getter và Setter cho frame
const Sprite& Game::getFrame() const {
    return frame;
}

void Game::setFrame(const Sprite& sprite) {
    frame = sprite;
}

// Getter và Setter cho delay
void Game::setDelay(float value) {
    delay = value;
}

float Game::getDelay() const {
    return delay;
}

void Game::setDx(int dx) {
    this->dx = dx; // Cập nhật dx
}

void Game::setRotate(bool rotate) {
    this->rotate = rotate; // Cập nhật rotate
}

RenderWindow& Game::getWindow() { 
    return window; 
};

Field& Game::getField() {
    return field;
}

std::unique_ptr<Tetromino>& Game::getTetromino() {
    return tetromino;
}

int Game::getLevel() const {
    return level;
}

void Game::setState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState); 
}


// Getter cho hiển thị khối tiếp theo
NextTetrominoPreview& Game::getNextTetrominoPreview() {
    return nextPreview;
}

// Getter cho level manager và score manager
LevelManager& Game::getLevelManager() {
    return levelManager;
}

ScoreManager& Game::getScoreManager() {
    return scoreManager;
}

void Game::update() {
    if (currentState == nullptr) return; // Nếu không có trạng thái nào, không cập nhật
    if (currentState == std::make_unique<GameOverState>(*this)) return; // Nếu trò chơi đã kết thúc, không cập nhật nữa 

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    tetromino->backupState();
    tetromino->move(dx);
    if (!tetromino->isValid(field)) {
        tetromino->restoreState();
    }

    if (rotate) {
        tetromino->backupState();
        tetromino->rotate();
        if (!tetromino->isValid(field)) {
            tetromino->restoreState();
        }
    }

    if (timer > delay) {
        tetromino->backupState();
        tetromino->fall();

        if (!tetromino->isValid(field)) {
            tetromino->restoreState();
            tetromino->lock(field);

           auto temp = nextPreview.cloneNext();
           if (!temp->isValid(field)) {
               currentState = std::make_unique<GameOverState>(*this); 
               return;
           }
   
           int cleared = field.clearLines(); // Xóa các dòng và trả về số dòng đã xóa

            if (cleared > 0) {
                int points = cleared * 10 * cleared; // Tính điểm theo số dòng xóa
                scoreManager.addScore(points);
                levelManager.addClearedLines(cleared);
            
                if (scoreManager.getScore() >= levelManager.getLevel() * 100) {
                    levelManager.increaseLevel();
            
                    // Giảm delay khi cấp độ tăng, nhưng không để delay quá nhỏ
                    delay = std::max(0.1f, delay - 0.02f); // Giảm 0.02 giây mỗi cấp, tối thiểu là 0.1 giây
                }
            
                levelManager.resetLinesCleared();
            }
    
            tetromino = nextPreview.getNext();  // lấy khối tiếp theo làm hiện tại
            nextPreview.generateNext();         // tạo khối tiếp theo mới
        }
        timer = 0;
    }

    dx = 0;
    rotate = false;
    delay = 0.3;
}

void Game::run() {
    while (window.isOpen()) {
        if (currentState != nullptr) {
            currentState->handleInput(*this);
            
            if (dynamic_cast<PlayingState*>(currentState.get()) != nullptr) {
                currentState->handleInput(*this); 
                update();
            }

            currentState->draw(*this);
        }
    }
}

void Game::resetGame() {
    scoreManager.reset();          
    levelManager.reset();          
    delay = 0.3;                   
    timer = 0;
    dx = 0;
    rotate = false;
    tetromino = TetrominoFactory::createRandomTetromino();
    field.clear();                
}
