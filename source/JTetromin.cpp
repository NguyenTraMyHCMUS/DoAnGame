#include "JTetromino.h"

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

void JTetromino::rotate() {
    Point center = _blocks[1]; // Điểm trung tâm để xoay
    for (int i = 0; i < 4; i++) {
        int x = _blocks[i]._y - center._y;
        int y = _blocks[i]._x - center._x;
        _blocks[i]._x = center._x + x;
        _blocks[i]._y = center._y - y;
    }
}
