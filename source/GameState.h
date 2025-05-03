#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class Game;

class GameState {
public:
    virtual ~GameState() = default; // Destructor
    virtual void handleInput(Game& game) = 0; // Xử lý đầu vào
    virtual void draw(Game& game) = 0; // Vẽ hình ảnh
};

#endif
