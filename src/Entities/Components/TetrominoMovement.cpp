#include "TetrominoMovement.h"

// Constructor: Khởi tạo với mảng các ô của khối Tetromino
TetrominoMovement::TetrominoMovement(Point (&blocks)[4]) : _blocks(blocks) {}

// Hàm move: Di chuyển khối theo phương ngang
void TetrominoMovement::move(int dx) {
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(_blocks[i].getX() + dx);
    }
}

// Hàm fall: Di chuyển khối xuống dưới một ô
void TetrominoMovement::fall() {
    for (int i = 0; i < 4; i++) {
        _blocks[i].setY(_blocks[i].getY() + 1);
    }
}