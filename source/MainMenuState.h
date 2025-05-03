#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

class MainMenuState : public GameState {
private:
    Game& _game;
    sf::Texture _menuBackgroundTexture; // Texture cho hình ảnh menu
    sf::Sprite _menuBackgroundSprite;   // Sprite để hiển thị hình ảnh men
    sf::Font _fontTitle; // Phông chữ cho tiêu đề
    sf::Font _fontWelcome; // Phông chữ cho menu
    sf::Text _welcome; // Tiêu đề menu
    sf::Font _font; // Phông chữ cho menu
    sf::Text _title; // Tiêu đề menu
    sf::Texture _buttonTexture; // Texture cho hình ảnh nút
    sf::Sprite _buttonSprites[3]; // Sprite cho các nút
    sf::Text _menuOptions[3]; // Các mục menu: Start Game, Instructions, Exit
    int _selectedIndex; // Chỉ số của mục menu hiện tại đang được chọn

public:
    MainMenuState(Game& game); // Constructor
    void handleInput(Game& game) override; // Xử lý đầu vào
    void draw(Game& game) override; // Vẽ hình ảnh menu
};

#endif
