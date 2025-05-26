#include "JTetromino.h"
#include "../RotatorFactory.h"

// Hàm khởi tạo khối J
JTetromino::JTetromino() {
    _color = 2; // Màu sắc cho khối J
    initializeShape(); // Khởi tạo hình dạng khối
    _rotator = new CounterclockwiseRotator();
    //_rotator = std::make_unique<CounterclockwiseRotator>(); // Sử dụng IRotator cho khối J
}

// Hàm khởi tạo hình dạng khối J
void JTetromino::initializeShape() {
    int figures[4] = {3, 5, 7, 6}; // Hình dạng khối J
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối J
void JTetromino::rotate() {
     // Gọi hàm rotate của _rotator
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối J
std::unique_ptr<Tetromino> JTetromino::clone() const {
    auto copy = std::make_unique<JTetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Đảm bảo khởi tạo rotator cho bản sao
    copy->setRotator(RotatorFactory::createRotator("J"));
    
    return copy;
}
