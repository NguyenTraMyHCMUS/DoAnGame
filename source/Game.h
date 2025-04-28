#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Block.h"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    sf::Texture t1, t2, t3;
    sf::Sprite s, background, frame;
    Grid grid;
    Block currentBlock;
    float timer, delay;
    int colorNum;

    void processEvents();
    void update(float deltaTime);
    void render();
};

#endif
