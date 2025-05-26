#include "TetrominoLocker.h"

TetrominoLocker::TetrominoLocker(const Point (&blocks)[4]) : _blocks(blocks){}

void TetrominoLocker::lock(Field& field, int color) const {
    for (int i = 0; i < 4; i++) {
        field.setCell(
            _blocks[i].getX(), 
            _blocks[i].getY(), 
            color);
    }
}
