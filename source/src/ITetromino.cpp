#include "include/ITetromino.h"

ITetromino::ITetromino() {
    _color = 1; // Màu sắc cho khối I
    initializeShape();
}

void ITetromino::initializeShape() {
    int figures[4] = {1, 3, 5, 7}; // Hình dạng khối I
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}
