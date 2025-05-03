#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

class PlayingState : public GameState {
private:
    Game& _game;
    sf::Font _font; // Font cho chữ
    // sf::Texture _playingTexture; // Texture cho hình ảnh chơi
    // sf::Sprite _playingSprite;   // Sprite để hiển thị hình ảnh chơi

public:
    PlayingState(Game& game);
    void handleInput(Game& game) override;
    void drawInfoBox(sf::RenderWindow& window, sf::Vector2f position, const std::string& title, const std::string& value);
    void draw(Game& game) override;
};

#endif 
