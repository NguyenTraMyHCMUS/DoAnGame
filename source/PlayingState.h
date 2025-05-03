#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

class PlayingState : public GameState {
private:
    Game& _game; // Tham chiếu đến đối tượng Game
    sf::Font _font; // Font cho chữ

public:
    PlayingState(Game& game); // Constructor
    void handleInput(Game& game) override; // Xử lý đầu vào (tải hình ảnh, font chữ, v.v.)
    void drawInfoBox(sf::RenderWindow& window, sf::Vector2f position, const std::string& title, const std::string& value); // Vẽ hộp thông tin chứa điểm số, level, khối tiếp theo
    void draw(Game& game) override; // Vẽ toàn cảnh trạng thái playing 
};

#endif 
