#ifndef INSTRUCTIONSSTATE_H
#define INSTRUCTIONSSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

class InstructionsState : public GameState {
private:
    Game& _game;
    sf::Texture _instructionTexture; // Texture cho nền
    sf::Sprite _instructionSprite; // Sprite cho nền
    sf::Font _font; // Phông chữ cho hướng dẫn
    sf::Text _title; // Tiêu đề "Hướng dẫn"
    sf::Text _instructions; // Nội dung hướng dẫn
    sf::Text _backOption; // Tùy chọn quay lại menu chính

public:
    InstructionsState(Game& game); // Constructor
    void handleInput(Game& game) override; // Xử lý đầu vào
    void draw(Game& game) override; // Vẽ nội dung hướng dẫn
};

#endif
