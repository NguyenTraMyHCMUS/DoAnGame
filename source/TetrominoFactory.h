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

/**
 * @class TetrominoFactory
 * @brief Lớp nhà máy (factory) tạo ra các khối Tetris.
 * 
 * Lớp này cung cấp các phương thức để tạo ra các khối Tetris theo loại hoặc ngẫu nhiên. Các khối này có thể là một trong những loại như I, J, L, O, S, T, Z.
 */
class TetrominoFactory {
public:
    /**
     * @brief Tạo khối Tetris theo loại.
     * 
     * Phương thức này tạo ra một khối Tetris cụ thể dựa trên loại được chỉ định.
     * 
     * @param type Loại của khối Tetris cần tạo (ví dụ: 0 = I, 1 = J, 2 = L, ...).
     * @return Một con trỏ duy nhất đến đối tượng khối Tetris tạo ra.
     */
    static std::unique_ptr<Tetromino> createTetromino(int type);

    /**
     * @brief Tạo khối Tetris ngẫu nhiên.
     * 
     * Phương thức này tạo ra một khối Tetris ngẫu nhiên từ các loại khối có sẵn.
     * 
     * @return Một con trỏ duy nhất đến đối tượng khối Tetris tạo ra.
     */
    static std::unique_ptr<Tetromino> createRandomTetromino();
};

#endif
