#include "Game.h"

Game::Game() 
    : window(sf::VideoMode(320, 480), "Tetris"),
      renderer(window, resourceManager),
      delay(0.3f),
      gameLogic(field, tetromino, nextPreview, scoreManager, levelManager, delay) {
    
    // Khởi tạo tài nguyên
    resourceManager.loadResources();
    
    // Khối đầu tiên
    tetromino = TetrominoFactory::createRandomTetromino();
    
    // Khối tiếp theo
    tetromino = nextPreview.getNext();
    nextPreview.generateNext();
    
    // Khởi tạo trạng thái ban đầu là MainMenu
    currentState = std::make_unique<MainMenuState>(*this);
}

void Game::update() {
    if (currentState == nullptr) return;

    // Cập nhật thời gian
    gameTimer.update();
    
    // Xử lý di chuyển ngang và xoay
    bool horizontalMoved = gameLogic.moveTetrominoHorizontally(inputManager.getDx());
    bool rotated = gameLogic.rotateTetrominoIfPossible(inputManager.getRotate());
    
    // Reset input
    inputManager.reset();
    
    // Xử lý di chuyển xuống theo thời gian
    if (gameTimer.shouldUpdate()) {
        if (!gameLogic.update(0, false)) {
            // Game over
            currentState = std::make_unique<GameOverState>(*this);
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        if (currentState != nullptr) {
            // Xử lý input và cập nhật state
            currentState->handleInput(*this);
            
            if (dynamic_cast<PlayingState*>(currentState.get()) != nullptr) {
                update();
            }
            
            // Vẽ state
            currentState->draw(*this);
        }
    }
}

void Game::resetGame() {
    gameLogic.resetGame();
    gameTimer.restart();
    inputManager.reset();
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

ResourceManager& Game::getResourceManager() {
    return resourceManager;
}

GameRenderer& Game::getRenderer() {
    return renderer;
}

InputManager& Game::getInputManager() {
    return inputManager;
}

GameTimer& Game::getGameTimer() {
    return gameTimer;
}

Field& Game::getField() {
    return field;
}

std::unique_ptr<Tetromino>& Game::getTetromino() {
    return tetromino;
}

NextTetrominoPreview& Game::getNextTetrominoPreview() {
    return nextPreview;
}

ScoreManager& Game::getScoreManager() {
    return scoreManager;
}

LevelManager& Game::getLevelManager() {
    return levelManager;
}

void Game::setState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}

void Game::setDelay(float value) {
    delay = value;
}

float Game::getDelay() const {
    return delay;
}
