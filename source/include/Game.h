#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "TetrominoFactory.h"
#include "Tetromino.h"
#include "ScoreManager"
using namespace sf;

class Game {
private:
    RenderWindow window;
    Texture t1, t2, t3;
    Sprite s, background, frame;
    Field field;
    std::unique_ptr<Tetromino> tetromino; // Sử dụng con trỏ thông minh để quản lý Tetromino
    Clock clock;
    float timer = 0, delay = 0.3;
    int dx = 0;
    bool rotate = false;
    bool isGameOver = false; // Biến để theo dõi trạng thái kết thúc trò chơi

    int level = 1; // Cấp độ hiện tại
    int linesCleared = 0; // Số dòng đã xóa

public:
    Game();
    void handleInput();
    void update();
    void draw();
    void run();
};

#endif
