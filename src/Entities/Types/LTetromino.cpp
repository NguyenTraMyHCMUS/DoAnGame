#include "LTetromino.h"
#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối L với ID 2 và tên "L"
REGISTER_TETROMINO(LTetromino, 2, "L")

// Hàm khởi tạo khối L với thành phần từ factory
LTetromino::LTetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("L"); // Màu sắc cho khối L
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối L
}

// Hàm khởi tạo khối L
LTetromino::LTetromino() {
    _color = ColorMapper::getInstance().getColor("L");; // Màu sắc cho khối L
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối L
}

void LTetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("L");
    }
}

// Hàm khởi tạo hình dạng khối L
void LTetromino::initializeShape() {
    int figures[4] = {2, 3, 5, 7}; // Hình dạng khối L
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối L
void LTetromino::rotate() {
     // Gọi hàm rotate của _rotator
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm tạo một bản sao của khối L
std::unique_ptr<Tetromino> LTetromino::clone() const {
    auto copy = std::make_unique<LTetromino>();
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Đảm bảo khởi tạo rotator cho bản sao
    copy->setRotator(RotatorFactory::createRotator("L"));
    
    return copy;
}

std::string LTetromino::getTypeName() const { 
    return "L"; 
}
