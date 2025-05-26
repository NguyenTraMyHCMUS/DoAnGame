#include "ZTetromino.h"
#include "../RotatorFactory.h"

// Hàm khởi tạo khối Z
ZTetromino::ZTetromino() {
    _color = 7; // Màu sắc cho khối Z
    initializeShape(); 
    _rotator = new StandardRotator();
}

// Hàm khởi tạo hình dạng khối Z
void ZTetromino::initializeShape() {
    int figures[4] = {2, 4, 5, 7}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối Z
void ZTetromino::rotate(){
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối Z
std::unique_ptr<Tetromino> ZTetromino::clone() const {
    auto copy = std::make_unique<ZTetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Đảm bảo khởi tạo rotator cho bản sao
    copy->setRotator(RotatorFactory::createRotator("Z"));
    
    return copy;
}
