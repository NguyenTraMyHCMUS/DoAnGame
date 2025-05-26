#include "TTetromino.h"
#include "../RotatorFactory.h"

// Hàm khởi tạo khối T
TTetromino::TTetromino() {
    _color = 4; // Màu sắc cho khối T
    initializeShape(); 
   _rotator = new StandardRotator();
}

// Hàm khởi tạo hình dạng khối T
void TTetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 7}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối T
void TTetromino::rotate(){
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối T
std::unique_ptr<Tetromino> TTetromino::clone() const {
    auto copy = std::make_unique<TTetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Đảm bảo khởi tạo rotator cho bản sao
     copy->setRotator(RotatorFactory::createRotator("T"));
    
    return copy;
}

