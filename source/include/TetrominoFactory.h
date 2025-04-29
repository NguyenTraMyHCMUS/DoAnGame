#ifndef TETROMINO_FACTORY_H
#define TETROMINO_FACTORY_H

#include "ITetromino.h"
#include "JTetromino.h"
#include "LTetromino.h"
#include "OTetromino.h"
#include "STetromino.h"
#include "TTetromino.h"
#include "ZTetromino.h"
#include <memory>
#include <cstdlib>

class TetrominoFactory {
public:
    static std::unique_ptr<Tetromino> createTetromino(int type); // Tạo khối theo loại
    static std::unique_ptr<Tetromino> createRandomTetromino(); // Tạo khối ngẫu nhiên
};

#endif
