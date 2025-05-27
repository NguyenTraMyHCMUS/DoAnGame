#include "STetromino.h"
#include "../Factories/RotatorFactory.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối O với ID 4 và tên "S"
REGISTER_TETROMINO(STetromino, 4, "S")

// Hàm khởi tạo khối S với thành phần từ factory
STetromino::STetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("S"); // Màu sắc cho khối S
    initializeShape(); // Khởi tạo hình dạng khối
    setupRotator(); // Tạo rotator cho khối S
}

// Hàm khởi tạo khối S
STetromino::STetromino() {
    _color = ColorMapper::getInstance().getColor("S"); // Màu sắc cho khối S
    initializeShape(); 
    setupRotator(); // Tạo rotator cho khối L
}

void STetromino::setupRotator() {
    if (_componentFactory) {
        _rotator = _componentFactory->createRotator("S");
    }
}

// Hàm khởi tạo hình dạng khối S
void STetromino::initializeShape() {
    int figures[4] = {3, 5, 4, 6}; 
    int offsetX = rand() % (N - 3);
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2 + offsetX);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối S
void STetromino::rotate(){
    if (_rotator) {
        _rotator->rotate(_blocks); 
    }
}

// Hàm tạo một bản sao của khối S
std::unique_ptr<Tetromino> STetromino::clone() const {
    auto copy = std::make_unique<STetromino>();

    copy->setColor(_color);
    copy->cloneComponents(*this);
    copy->setRotator(RotatorFactory::createRotator("S"));
    
    return copy;
}

std::string STetromino::getTypeName() const { 
    return "S"; // Trả về tên loại khối S
}
