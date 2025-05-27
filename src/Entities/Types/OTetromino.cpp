#include "OTetromino.h"
#include "../Registries/TetrominoAutoRegistrar.h"
#include "../Configuration/ColorMapper.h"

// Đăng ký khối O với ID 3 và tên "O"
REGISTER_TETROMINO(OTetromino, 3, "O")

// Hàm khởi tạo khối O với thành phần từ factory
OTetromino::OTetromino(ITetrominoComponentFactory& factory) : Tetromino(factory) {
    _color = ColorMapper::getInstance().getColor("O"); // Màu sắc cho khối O
    initializeShape(); // Khởi tạo hình dạng khối
    _rotator = nullptr; // Không cần rotator cho khối O
}

// Hàm khởi tạo khối O
OTetromino::OTetromino() {
    _color = ColorMapper::getInstance().getColor("O"); // Màu sắc cho khối O
    initializeShape(); 
    _rotator = nullptr;
}

// Hàm khởi tạo hình dạng khối O
void OTetromino::initializeShape() {
    int figures[4] = {2, 3, 4, 5}; 
    int offsetX = rand() % (N - 3);
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(figures[i] % 2 + offsetX);
        _blocks[i].setY(figures[i] / 2);
    }
}

// Hàm xoay khối O
void OTetromino::rotate() {
    // Không làm gì cả vì khối O không thay đổi hình dạng khi xoay
}   

// Hàm tạo một bản sao của khối O
std::unique_ptr<Tetromino> OTetromino::clone() const {
    // Tạo đối tượng mới thay vì sao chép
    auto copy = std::make_unique<OTetromino>();
    
    // Sao chép các thuộc tính thường
    copy->setColor(_color);
    
    copy->cloneComponents(*this);
    
    // Không cần rotator cho khối O
    
    return copy;
}

std::string OTetromino::getTypeName() const {
    return "O"; // Trả về tên loại khối O
}
