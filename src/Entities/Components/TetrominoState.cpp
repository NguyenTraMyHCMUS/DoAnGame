#include "TetrominoState.h"

// Hàm khởi tạo TetrominoState với mảng các ô
TetrominoState::TetrominoState(Point (&blocks)[4]) : _blocks(blocks) {
    for (int i = 0; i < 4; i++) {
        _backup[i] = {0,0};
    }
}

// Hàm lưu trạng thái hiện tại
void TetrominoState::backupState() {
    for (int i = 0; i < 4; i++) {
        _backup[i] = _blocks[i];
    }
}

// Hàm khôi phục trạng thái đã lưu
void TetrominoState::restoreState() {
    for (int i = 0; i < 4; i++) {
        _blocks[i] = _backup[i];
    }
}
