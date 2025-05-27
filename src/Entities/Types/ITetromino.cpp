#include "ITetromino.h"
#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối I với ID 0 và tên "I"
REGISTER_TETROMINO(ITetromino, 0, "I")

ITetromino::ITetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("I");
    initializeShape();
    setupRotator();
}

// Hàm khởi tạo khối I
ITetromino::ITetromino() : Tetromino() {
    _color = ColorMapper::getInstance().getColor("I");
    initializeShape();
    setupRotator();
}

void ITetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("I");
    }
}

// Hàm khởi tạo hình dạng khối I
void ITetromino::initializeShape() {
    int figures[4] = {1, 3, 5, 7}; // Hình dạng khối I
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

void ITetromino::rotate() {
    // Gọi hàm rotate của _rotator
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối I
std::unique_ptr<Tetromino> ITetromino::clone() const {
    auto copy = std::make_unique<ITetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Đảm bảo khởi tạo rotator cho bản sao
    copy->setRotator(RotatorFactory::createRotator("I"));
    
    return copy;
}

std::string ITetromino::getTypeName() const { 
    return "I"; 
}
