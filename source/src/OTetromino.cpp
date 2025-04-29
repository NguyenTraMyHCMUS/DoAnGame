#include "OTetromino.h"

OTetromino::OTetromino() {
    _color = 6; // Màu sắc cho khối O
    initializeShape(); // Khởi tạo hình dạng khối
}

void OTetromino::initializeShape() {
    int figures[4] = {2, 3, 4, 5}; // Hình dạng khối O
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}
