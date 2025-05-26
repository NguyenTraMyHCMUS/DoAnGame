#ifndef STANDARD_ROTATORS_H
#define STANDARD_ROTATORS_H

#include "../../Interface/ITetrominoRotator.h"

// Xoay thông thường - áp dụng cho đa số các khối (J, L, T, S, Z)
class StandardRotator : public ITetrominoRotator {
public:
    void rotate(Point (&blocks)[4]) override;
};

#endif
