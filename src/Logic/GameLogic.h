#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <memory>
#include "../Entities/Tetromino.h"
#include "../Entities/Field.h"
#include "../States/NextTetrominoPreview.h"
#include "ScoreManager.h"
#include "LevelManager.h"

/**
 * @class GameLogic
 * @brief Xử lý logic chính của game (Single Responsibility)
 */
class GameLogic {
private:
    Field& field;
    std::unique_ptr<Tetromino>& tetromino;
    NextTetrominoPreview& nextPreview;
    ScoreManager& scoreManager;
    LevelManager& levelManager;
    float& delay;

public:
    GameLogic(Field& field, std::unique_ptr<Tetromino>& tetromino, 
              NextTetrominoPreview& nextPreview, ScoreManager& scoreManager,
              LevelManager& levelManager, float& delay);
    
    bool update(int dx, bool rotate);
    bool moveTetrominoHorizontally(int dx);
    bool rotateTetrominoIfPossible(bool rotate);
    bool moveTetrominoDown();
    bool isGameOver();
    void handleLineClearing();
    void resetGame();
};

#endif