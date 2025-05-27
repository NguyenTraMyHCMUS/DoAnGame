#include "TetrominoLocker.h"

// Hàm khởi tạo TetrominoLocker với mảng các ô
TetrominoLocker::TetrominoLocker(const Point (&blocks)[4]) : _blocks(blocks){}

// Hàm cố định khối vào lưới
void TetrominoLocker::lock(Field& field, int color) const {
    for (int i = 0; i < 4; i++) {
        field.setCell(
            _blocks[i].getX(), 
            _blocks[i].getY(), 
            color);
    }
}