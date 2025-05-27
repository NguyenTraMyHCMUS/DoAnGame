#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <string>

class PlayerNameState : public GameState {
public:
    PlayerNameState(Game& game);
    void handleInput(Game& game) override;
    void update(Game& game) override;
    void draw(Game& game) override;
private:
    std::string _playerName;
    sf::Font _font;
    sf::Text _titleText;
    sf::Text _promptText;
    sf::Text _inputText;
    sf::RectangleShape _inputBox;
    sf::Text _guideText;
    bool _nameEntered = false;
    float _cursorTimer = 0.f;
    bool _showCursor = true;
};
