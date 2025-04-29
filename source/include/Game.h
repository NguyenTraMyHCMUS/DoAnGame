#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Tetromino.h"
#include "ScoreManager.h"
#include "TetrominoFactory.h"

class Game {
private:
    RenderWindow window;
    Texture t1, t2, t3;
    Sprite s, background, frame;
    Field field;
    Tetromino tetromino;
    Clock clock;
    ScoreManager scoreManager;
    float timer = 0, delay = 0.3;
    int dx = 0;
    bool rotate = false;

public:
    Game();
    void handleInput();
    void update();
    void draw();
    void run();
};

#endif
