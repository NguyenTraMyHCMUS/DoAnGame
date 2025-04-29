#include "ZTetromino.h"

ZTetromino::ZTetromino() {
    _color = 7; // Màu sắc cho khối Z
    initializeShape(); // Khởi tạo hình dạng khối
}

void ZTetromino::initializeShape() {
    int figures[4] = {2, 4, 5, 7}; // Hình dạng khối Z
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

void ZTetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}
