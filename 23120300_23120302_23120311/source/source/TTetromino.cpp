#include "TTetromino.h"

// Hàm khởi tạo khối T
TTetromino::TTetromino() {
    _color = 4; // Màu sắc cho khối T
    initializeShape(); 
}

// Hàm khởi tạo hình dạng khối T
void TTetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 7}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

// Hàm xoay khối T
void TTetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}

// Hàm tạo một bản sao của khối T
std::unique_ptr<Tetromino> TTetromino::clone() const {
    return std::make_unique<TTetromino>(*this); 
}
