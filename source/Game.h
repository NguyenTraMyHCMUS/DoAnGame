#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Field.h"
#include "Tetromino.h"

class Game
{
    private:
        RenderWindow window; // cửa sổ trò chơi
        Texture t1, t2, t3; // hình ảnh cho các ô vuông
        Sprite s, background, frame; // hình ảnh nền và khung
        Field field; // trường đại diện cho các ô vuông trong trò chơi
        Tetromino tetromino; // Tetromino đại diện cho các khối trong trò chơi
        Clock clock; // đồng hồ để theo dõi thời gian
        float timer = 0, delay = 0.3; // biến thời gian để điều chỉnh tốc độ rơi của Tetromino
        int dx = 0; // biến để lưu trữ hướng di chuyển của Tetromino
        bool rotate = false; // biến để kiểm tra xem có cần quay Tetromino hay không
    public:
        Game(); // constructor khởi tạo trò chơi
        void handleInput(); // xử lý đầu vào từ bàn phím
        void update(); // cập nhật trạng thái trò chơi
        void draw(); // vẽ các đối tượng lên cửa sổ
        void run(); // chạy trò chơi
};


#endif