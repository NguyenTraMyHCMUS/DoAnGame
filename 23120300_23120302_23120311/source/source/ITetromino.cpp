#include "ITetromino.h"

// Hàm khởi tạo khối I
ITetromino::ITetromino() {
    _color = 1; // Màu sắc cho khối I
    initializeShape();
}

// Hàm khởi tạo hình dạng khối I
void ITetromino::initializeShape() {
    int figures[4] = {1, 3, 5, 7}; // Hình dạng khối I
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x = figures[i] % 2;
        _blocks[i]._y = figures[i] / 2;
    }
}

// Hàm xoay khối I
// Khối I có thể xoay ngang hoặc dọc
void ITetromino::rotate() {
    static bool isHorizontal = true;
    Point center = _blocks[1]; // Điểm trung tâm để xoay

    if (isHorizontal) {
        for (int i = 0; i < 4; i++) {
            _blocks[i]._x = center._x;
            _blocks[i]._y = center._y - 1 + i;
        }
    } 
    else {
        for (int i = 0; i < 4; i++) {
            _blocks[i]._x = center._x - 1 + i;
            _blocks[i]._y = center._y;
        }
    }

    isHorizontal = !isHorizontal;
}

// Hàm tạo một bản sao của khối I
std::unique_ptr<Tetromino> ITetromino::clone() const {
    return std::make_unique<ITetromino>(*this);
}
