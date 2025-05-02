#include "STetromino.h"

STetromino::STetromino() {
    _color = 3; // Màu sắc cho khối S
    initializeShape(); // Khởi tạo hình dạng khối
}

void STetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 6}; // Hình dạng khối S
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

void STetromino::rotate(){
    Tetromino::rotate(); // Gọi hàm xoay của lớp cha
}

std::unique_ptr<Tetromino> STetromino::clone() const 
{
    return std::make_unique<STetromino>(*this);
}
