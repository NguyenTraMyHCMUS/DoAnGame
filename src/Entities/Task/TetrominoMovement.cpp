#include "TetrominoMovement.h"

TetrominoMovement::TetrominoMovement(Point (&blocks)[4]) : _blocks(blocks) {}

void TetrominoMovement::move(int dx) {
    for (int i = 0; i < 4; i++) {
        _blocks[i].setX(_blocks[i].getX() + dx);
    }
}

void TetrominoMovement::fall() {
    for (int i = 0; i < 4; i++) {
        _blocks[i].setY(_blocks[i].getY() + 1);
    }
}
