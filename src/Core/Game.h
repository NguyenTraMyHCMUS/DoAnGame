
#ifndef GAME_H
#define GAME_H

/**
 * @file Game.h
 * @brief Định nghĩa lớp Game điều khiển logic chính của trò chơi Tetris.
 */

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Graphics/ResourceManager.h"
#include "../Graphics/GameRenderer.h"
#include "../Input/InputManager.h"
#include "../Time/GameTimer.h"
#include "../Logic/GameLogic.h"
#include "../Entities/Field.h"
#include "../Entities/Tetromino.h"
#include "../States/GameState.h"
#include "../Logic/ScoreManager.h"
#include "../Logic/LevelManager.h"
#include "../States/NextTetrominoPreview.h"
#include "../States/MainMenuState.h"
#include "../States/GameOverState.h"
#include "../States/PlayingState.h"

/**
 * @class Game
 * @brief Lớp chính điều khiển trò chơi Tetris (Facade Pattern)
 */
class Game {
private:
    sf::RenderWindow window;
    ResourceManager resourceManager;
    GameRenderer renderer;
    InputManager inputManager;
    GameTimer gameTimer;
    
    Field field;
    std::unique_ptr<Tetromino> tetromino;
    NextTetrominoPreview nextPreview;
    ScoreManager scoreManager;
    LevelManager levelManager;
    std::unique_ptr<GameState> currentState;
    
    GameLogic gameLogic;
    float delay;

public:
    Game();
    void update();
    void run();
    void resetGame();
    
    // Các phương thức truy cập cần thiết
    sf::RenderWindow& getWindow();
    ResourceManager& getResourceManager();
    GameRenderer& getRenderer();
    InputManager& getInputManager();
    GameTimer& getGameTimer();
    
    Field& getField();
    std::unique_ptr<Tetromino>& getTetromino();
    NextTetrominoPreview& getNextTetrominoPreview();
    ScoreManager& getScoreManager();
    LevelManager& getLevelManager();
    
    void setState(std::unique_ptr<GameState> newState);
    void setDelay(float value);
    float getDelay() const;
};

#endif
