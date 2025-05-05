#include "STetromino.h"

// Hàm khởi tạo khối S
STetromino::STetromino() {
    _color = 3; // Màu sắc cho khối S
    initializeShape(); 
}

// Hàm khởi tạo hình dạng khối S
void STetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 6}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

// Hàm xoay khối S
void STetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}

// Hàm tạo một bản sao của khối S
std::unique_ptr<Tetromino> STetromino::clone() const {
    return std::make_unique<STetromino>(*this); 
}
