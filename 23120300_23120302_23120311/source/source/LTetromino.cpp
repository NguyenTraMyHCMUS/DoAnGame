#include "LTetromino.h"

// Hàm khởi tạo khối L
LTetromino::LTetromino() {
    _color = 5; // Màu sắc cho khối L
    initializeShape(); // Khởi tạo hình dạng khối
}

// Hàm khởi tạo hình dạng khối L
void LTetromino::initializeShape() {
    int figures[4] = {2, 3, 5, 7}; // Hình dạng khối L
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

// Hàm xoay khối L
void LTetromino::rotate() {
    Point center = _blocks[1]; 
    for (int i = 0; i < 4; i++) {
        int x = _blocks[i]._y - center._y;
        int y = _blocks[i]._x - center._x;
        _blocks[i]._x = center._x + x;
        _blocks[i]._y = center._y - y;
    }
}

// Hàm tạo một bản sao của khối L
std::unique_ptr<Tetromino> LTetromino::clone() const {
    return std::make_unique<LTetromino>(*this);
}
