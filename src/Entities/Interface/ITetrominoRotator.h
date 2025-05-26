#ifndef ITETROMINO_ROTATOR_H
#define ITETROMINO_ROTATOR_H

#include "../Point.h"

class ITetrominoRotator {
public:
    virtual ~ITetrominoRotator() = default;
    virtual void rotate(Point (&blocks)[4]) = 0;
};

#endif
