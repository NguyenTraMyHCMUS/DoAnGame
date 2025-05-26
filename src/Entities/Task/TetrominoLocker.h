#ifndef TETROMINO_LOCKER_H
#define TETROMINO_LOCKER_H

#include "../Point.h"
#include "../Field.h"
#include "../Interface/ITetrominoLocker.h"

class TetrominoLocker : public ITetrominoLocker {
    private:
        const Point (&_blocks)[4]; 

    public:
        TetrominoLocker(const Point (&blocks)[4]);
        
        void lock(Field& field, int color) const;
};

#endif
