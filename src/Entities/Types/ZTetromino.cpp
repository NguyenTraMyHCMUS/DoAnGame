#include "ZTetromino.h"
#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối O với ID 6 và tên "Z"
REGISTER_TETROMINO(ZTetromino, 6, "Z")

// Hàm khởi tạo khối Z với thành phần từ factory
ZTetromino::ZTetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("Z"); // Màu sắc cho khối Z
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối Z
}

// Hàm khởi tạo khối Z
ZTetromino::ZTetromino() {
    _color = ColorMapper::getInstance().getColor("Z"); // Màu sắc cho khối Z
    initializeShape(); 
    setupRotator(); // Tạo rotator cho khối L
}

void ZTetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("Z");
    }
}

// Hàm khởi tạo hình dạng khối Z
void ZTetromino::initializeShape() {
    int figures[4] = {2, 4, 5, 7}; 
    int offsetX = rand() % (N - 3);
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2 + offsetX);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối Z
void ZTetromino::rotate(){
    if (_rotator) {
        _rotator->rotate(_blocks); 
    }
}

// Hàm tạo một bản sao của khối Z
std::unique_ptr<Tetromino> ZTetromino::clone() const {
    auto copy = std::make_unique<ZTetromino>();

    copy->setColor(_color);
    copy->cloneComponents(*this);
    copy->setRotator(RotatorFactory::createRotator("Z"));
    
    return copy;
}

std::string ZTetromino::getTypeName() const { 
    return "Z"; // Trả về tên loại khối Z
}
