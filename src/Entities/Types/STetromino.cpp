#include "STetromino.h"
#include "../RotatorFactory.h"

// Hàm khởi tạo khối S
STetromino::STetromino() {
    _color = 3; // Màu sắc cho khối S
    initializeShape(); 
    _rotator = new StandardRotator(); // Sử dụng StandardRotator cho khối S
    //_rotator = std::make_unique<StandardRotator>(); // Sử dụng StandardRotator cho khối S
}

// Hàm khởi tạo hình dạng khối S
void STetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 6}; 
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối S
void STetromino::rotate(){
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối S
std::unique_ptr<Tetromino> STetromino::clone() const {
    auto copy = std::make_unique<STetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    // Đảm bảo khởi tạo rotator cho bản sao
     copy->setRotator(RotatorFactory::createRotator("S"));
    
    return copy;
}
