#include "include/JTetromino.h"

JTetromino::JTetromino() {
    _color = 2; // Màu sắc cho khối J
    initializeShape(); // Khởi tạo hình dạng khối
}

void JTetromino::initializeShape() {
    int figures[4] = {3, 5, 7, 6}; // Hình dạng khối J
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}
