#ifndef COUNTERCLOCKWISE_ROTATOR_H
#define COUNTERCLOCKWISE_ROTATOR_H

#include "../../Interface/ITetrominoRotator.h"

// Xoay thông thường - áp dụng cho đa số các khối (J, L, T, S, Z)
class CounterclockwiseRotator : public ITetrominoRotator {
public:
    void rotate(Point (&blocks)[4]) override;
};

#endif
