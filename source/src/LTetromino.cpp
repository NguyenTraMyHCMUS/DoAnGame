#include "include/LTetromino.h"

LTetromino::LTetromino() {
    _color = 5; // Màu sắc cho khối L
    initializeShape(); // Khởi tạo hình dạng khối
}

void LTetromino::initializeShape() {
    int figures[4] = {2, 3, 5, 7}; // Hình dạng khối L
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}
