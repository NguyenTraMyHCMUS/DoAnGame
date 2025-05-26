#ifndef I_ROTATOR_H  
#define I_ROTATOR_H

#include "../../Interface/ITetrominoRotator.h"

// Xoay 2 trạng thái - dùng cho khối I
class IRotator : public ITetrominoRotator {
private:
    bool _isHorizontal = true;

public:
    void rotate(Point (&blocks)[4]);
};

#endif
