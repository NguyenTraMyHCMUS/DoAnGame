#include "TTetromino.h"

#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối O với ID 5 và tên "T"
REGISTER_TETROMINO(TTetromino, 5, "T")

// Hàm khởi tạo khối T với thành phần từ factory
TTetromino::TTetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("T"); // Màu sắc cho khối T
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối T
}

// Hàm khởi tạo khối T
TTetromino::TTetromino() {
    _color = ColorMapper::getInstance().getColor("T"); // Màu sắc cho khối T
    initializeShape(); 
   setupRotator(); // Tạo rotator cho khối L
}

void TTetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("T");
    }
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
        _rotator->rotate(_blocks); 
    }
}

// Hàm tạo một bản sao của khối T
std::unique_ptr<Tetromino> TTetromino::clone() const {
    auto copy = std::make_unique<TTetromino>();

    copy->setColor(_color);
    copy->cloneComponents(*this);
    copy->setRotator(RotatorFactory::createRotator("T"));
    
    return copy;
}

std::string TTetromino::getTypeName() const { 
    return "T"; // Trả về tên loại khối T
}

