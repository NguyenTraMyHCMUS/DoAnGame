#include "Game.h"
#include "../Entities/Configuration/ColorMapper.h"
#include "../Entities/Configuration/ConfigurationManager.h"
#include "../Entities/Factories/TetrominoFactory.h"

Game::Game() 
    : _window(sf::VideoMode(320, 480), "Tetris"),
      _renderer(_window, _resourceManager),
      _delay(0.3f),
      _gameLogic(_field, _tetromino, _nextPreview, _scoreManager, _levelManager, _delay) {
    
    // Load configuration từ file
    auto& config = ConfigurationManager::getInstance();
    if (!config.loadFromFile("../Entities/Configguration/tetris_config.txt")) {
        // Use default values if file not found
        config.setInt("cell_size", 18);
        config.setInt("fall_speed", 300);
    }

    // Update color mapping từ config
    //ColorMapper::updateFromConfig();
    ColorMapper::getInstance().updateFromConfig();
    // Khởi tạo tài nguyên
    _resourceManager.loadResources();
    
    // Khối đầu tiên
    _tetromino = TetrominoFactory::createRandomTetromino();
    if (!_tetromino) {
        // Fallback nếu factory trả về nullptr
        throw std::runtime_error("Failed to create initial Tetromino");
    }
    
    // Khối tiếp theo
    _tetromino = _nextPreview.getNext();
    _nextPreview.generateNext();
    
    // Khởi tạo trạng thái ban đầu là MainMenu
    _currentState = std::make_unique<MainMenuState>(*this);
}

void Game::update() {
    if (_currentState == nullptr) return;

    // Cập nhật thời gian
    _gameTimer.update();
    
    // Xử lý di chuyển ngang và xoay
    bool horizontalMoved = _gameLogic.moveTetrominoHorizontally(_inputManager.getDx());
    bool rotated = _gameLogic.rotateTetrominoIfPossible(_inputManager.getRotate());
    
    // Reset input
    _inputManager.reset();
    
    // Xử lý di chuyển xuống theo thời gian
    if (_gameTimer.shouldUpdate()) {
        if (!_gameLogic.update(0, false)) {
            // Game over
            _currentState = std::make_unique<GameOverState>(*this);
        }
    }
}

void Game::run() {
    while (_window.isOpen()) {
        if (_currentState != nullptr) {
            // Xử lý input và cập nhật state
            _currentState->handleInput(*this);
            
            if (dynamic_cast<PlayingState*>(_currentState.get()) != nullptr) {
                update();
            }
            
            // Vẽ state
            _currentState->draw(*this);
        }
    }
}

void Game::resetGame() {
    _gameLogic.resetGame();
    _gameTimer.restart();
    _inputManager.reset();
}

sf::RenderWindow& Game::getWindow() {
    return _window;
}

ResourceManager& Game::getResourceManager() {
    return _resourceManager;
}

GameRenderer& Game::getRenderer() {
    return _renderer;
}

InputManager& Game::getInputManager() {
    return _inputManager;
}

GameTimer& Game::getGameTimer() {
    return _gameTimer;
}

Field& Game::getField() {
    return _field;
}

std::unique_ptr<Tetromino>& Game::getTetromino() {
    return _tetromino;
}

NextTetrominoPreview& Game::getNextTetrominoPreview() {
    return _nextPreview;
}

ScoreManager& Game::getScoreManager() {
    return _scoreManager;
}

LevelManager& Game::getLevelManager() {
    return _levelManager;
}

void Game::setState(std::unique_ptr<GameState> newState) {
    _currentState = std::move(newState);
}

void Game::setDelay(float value) {
    _delay = value;
}

float Game::getDelay() const {
    return _delay;
}

const std::string& Game::getPlayerName() const {
    return _playerName;
}

void Game::setPlayerName(const std::string& name) {
    _playerName = name;
}
