#include "TetrominoState.h"

TetrominoState::TetrominoState(Point (&blocks)[4]) : _blocks(blocks) {
    for (int i = 0; i < 4; i++) {
        _backup[i] = {0,0};
    }
}

void TetrominoState::backupState() {
    for (int i = 0; i < 4; i++) {
        _backup[i] = _blocks[i];
    }
}

void TetrominoState::restoreState() {
    for (int i = 0; i < 4; i++) {
        _blocks[i] = _backup[i];
    }
}
