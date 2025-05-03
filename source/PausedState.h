#ifndef PAUSEDSTATE_H
#define PAUSEDSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game; // Forward declaration of Game class
// Để tránh vòng lặp khi bao gồm các tệp tiêu đề

class PausedState : public GameState {
private:
    Game& _game;
    sf::Texture _pausedTexture; // Texture cho hình ảnh tạm dừng
    sf::Sprite _pausedSprite;   // Sprite để hiển thị hình ảnh tạm dừng
    sf::Font _font; // Phông chữ cho menu
    sf::Text _title; // Tiêu đề tạm dừng
    sf::Text _menuOptions[2]; // Các mục menu: Continue, Exit
    int _selectedIndex; // Chỉ số của mục menu hiện tại đang được chọn
public:
    PausedState(Game& game); // Constructor
    void handleInput(Game& game) override; // Xử lý đầu vào
    void draw(Game& game) override; // Vẽ hình ảnh tạm dừng
};

#endif 
