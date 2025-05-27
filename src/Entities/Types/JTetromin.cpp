#include "JTetromino.h"
#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối J với ID 1 và tên "J"
REGISTER_TETROMINO(JTetromino, 1, "J")

JTetromino::JTetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("J"); // Màu sắc cho khối J
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối J
}

// Hàm khởi tạo khối J
JTetromino::JTetromino() {
    _color = ColorMapper::getInstance().getColor("J");; // Màu sắc cho khối J
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator();  // Tạo rotator cho khối J
}

void JTetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("J");
    }
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

std::string JTetromino::getTypeName() const { 
    return "J"; 
}
