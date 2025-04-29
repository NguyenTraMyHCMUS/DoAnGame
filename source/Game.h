#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "TetrominoFactory.h"
using namespace sf;

enum class GameState {
    MainMenu,
    Playing,
    GameOver
};

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
    int score = 0; // Biến lưu điểm số của trò chơi
    int level = 1; // Cấp độ hiện tại
    int linesCleared = 0; // Số dòng đã xóa
    GameState state = GameState::MainMenu; // Trạng thái ban đầu là menu chính
    sf::Texture menuBackgroundTexture; // Texture cho hình ảnh menu
    sf::Sprite menuBackgroundSprite;   // Sprite để hiển thị hình ảnh menu
    sf::Texture gameOverTexture; // Texture cho hình ảnh Game Over
    sf::Sprite gameOverSprite;   // Sprite để hiển thị hình ảnh Game Over
    

public:
    Game();
    void handleInput();
    void update();
    void draw();
    void run();

    void drawMainMenu();
    void handleMainMenuInput();
    void drawGameOverScreen();
    void handleGameOverInput();
    void resetGame(); 
};

#endif
