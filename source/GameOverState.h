#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

class GameOverState : public GameState {
private:
    Game& _game;
    sf::Texture _gameOverTexture; // Texture cho hình ảnh Game Over
    sf::Sprite _gameOverSprite;   // Sprite để hiển thị hình ảnh Game Over
    sf::Font _font; // Phông chữ cho menu
    sf::Text _title; // Tiêu đề Game Over
    sf::Text _menuOptions[2]; // Các mục menu: Retry, Exit
    int _selectedIndex; // Chỉ số của mục menu hiện tại đang được chọn

public:
    GameOverState(Game& game); // Constructor
    void handleInput(Game& game) override; // Xử lý đầu vào
    void draw(Game& game) override; // Vẽ hình ảnh Game Over
};

#endif
