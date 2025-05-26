#ifndef TETROMINO_STATE_H
#define TETROMINO_STATE_H

#include "../Point.h"
#include "../Interface/ITetrominoState.h"

class TetrominoState : public ITetrominoState {
    private:
        Point (&_blocks)[4];
        Point _backup[4];

    public:
        TetrominoState(Point (&blocks)[4]);

        void backupState() override;
        void restoreState() override;
};

#endif
