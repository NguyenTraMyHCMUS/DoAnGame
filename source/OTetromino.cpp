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

void OTetromino::rotate() {
    // Không làm gì cả vì khối O không thay đổi hình dạng khi xoay
}   

std::unique_ptr<Tetromino> OTetromino::clone() const 
{
    return std::make_unique<OTetromino>(*this);
}
