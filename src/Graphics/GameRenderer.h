#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "../Entities/Field.h"
#include "../Entities/Tetromino.h"
#include "../States/NextTetrominoPreview.h"
#include "../Logic/ScoreManager.h"
#include "../Logic/LevelManager.h"

/**
 * @class GameRenderer
 * @brief Chịu trách nhiệm vẽ các thành phần game (Single Responsibility)
 */
class GameRenderer {
private:
    sf::RenderWindow& window;
    ResourceManager& resources;

public:
    GameRenderer(sf::RenderWindow& window, ResourceManager& resources);
    
    void clear();
    void display();
    void drawBackground();
    void drawField(const Field& field);    void drawTetromino(const Tetromino* tetromino);
    void drawInfoBox(const std::string& title, const std::string& value, float yPos);
    void drawNextPreview(const NextTetrominoPreview& preview);
    void drawStats(const ScoreManager& scoreManager, const LevelManager& levelManager);
    void drawFrame();
};

#endif