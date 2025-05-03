#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "TetrominoFactory.h"
#include "GameState.h"
#include "LevelManager.h"
#include "ScoreManager.h"
#include "NextTetrominoPreview.h"

using namespace sf;

class Game {
private:
    RenderWindow window;
    Texture t1, t2, t3;
    Sprite s, background, frame;
    Field field;
    Clock clock;
    float timer = 0;
    float delay = 0.3;
    int dx = 0;
    bool rotate = false;
    int score = 0; // Biến lưu điểm số của trò chơi
    int level = 1; // Cấp độ hiện tại
    int linesCleared = 0; // Số dòng đã xóa
    
    std::unique_ptr<Tetromino> tetromino; // Sử dụng con trỏ thông minh để quản lý Tetromino
    std::unique_ptr<GameState> currentState; // Trạng thái hiện tại của trò chơi

    NextTetrominoPreview nextPreview; // Đối tượng hiển thị khối tiếp theo

    ScoreManager scoreManager;
    LevelManager levelManager;

public:
    Game();
    void update();
    void run();

    const Texture& getT1() const;
    void setT1(const Texture& texture);

    const Texture& getT2() const;
    void setT2(const Texture& texture);

    const Texture& getT3() const;
    void setT3(const Texture& texture);

    Sprite& getSprite() ; // chỗ này không có cost 
    void setSprite(const Sprite& sprite);

    const Sprite& getBackground() const;
    void setBackground(const Sprite& sprite);

    const Sprite& getFrame() const;
    void setFrame(const Sprite& sprite);

    void setDelay(float value); 
    float getDelay() const;  

    void setDx(int dx); // Setter cho dx
    void setRotate(bool rotate); // Setter cho rotate
    
    NextTetrominoPreview& getNextTetrominoPreview(); // Getter cho hiển thị khối tiếp theo
    LevelManager& getLevelManager(); // Getter cho level manager
    ScoreManager& getScoreManager(); // Getter cho score manager

    RenderWindow& getWindow();

    Field& getField(); // Trả về lưới hiện tại
    std::unique_ptr<Tetromino>& getTetromino(); // Getter cho tetromino
    int getLevel() const;                      // Getter cho level
    void setState(std::unique_ptr<GameState> newState); // Thay đổi trạng thái trò chơi
   
    void resetGame(); 
};

#endif
