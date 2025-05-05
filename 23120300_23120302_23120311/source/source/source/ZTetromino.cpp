#include "ZTetromino.h"

// Hàm khởi tạo khối Z
ZTetromino::ZTetromino() {
    _color = 7; // Màu sắc cho khối Z
    initializeShape(); 
}

// Hàm khởi tạo hình dạng khối Z
void ZTetromino::initializeShape() {
    int figures[4] = {2, 4, 5, 7}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

// Hàm xoay khối Z
void ZTetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}

// Hàm tạo một bản sao của khối Z
std::unique_ptr<Tetromino> ZTetromino::clone() const {
    return std::make_unique<ZTetromino>(*this); 
}
