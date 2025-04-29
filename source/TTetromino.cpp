#include "TTetromino.h"

TTetromino::TTetromino() {
    _color = 4; // Màu sắc cho khối T
    initializeShape(); // Khởi tạo hình dạng khối
}

void TTetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 7}; // Hình dạng khối T
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

void TTetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}
