#ifndef ROTATOR_FACTORY_H
#define ROTATOR_FACTORY_H

#include "Interface/ITetrominoRotator.h"
#include "Task/TypeRotation/StandardRotator.h"
#include "Task/TypeRotation/IRotator.h"
#include "Task/TypeRotation/CounterclockwiseRotator.h"
#include <memory>
#include <string>

/**
 * @brief Factory tạo các rotator phù hợp với từng loại khối
 */
class RotatorFactory {
public:
    static ITetrominoRotator* createRotator(const std::string& type);
};

#endif
