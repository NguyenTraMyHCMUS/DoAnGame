#ifndef STANDARD_ROTATORS_H
#define STANDARD_ROTATORS_H

#include "../../Interface/ITetrominoRotator.h"

/**
 * @file StandardRotator.h
 * @brief Định nghĩa lớp StandardRotator để xoay các khối Tetromino chuẩn (T, S, Z)
 */

/**
 * @class StandardRotator
 * @brief Lớp thực thi việc xoay các khối Tetromino theo cách xoay thông thường
 * 
 * Áp dụng cho các khối Tetromino như T, S, Z,
 * phương thức rotate sẽ thay đổi vị trí các ô trong mảng blocks
 * để xoay khối theo chiều xoay chuẩn (counterclockwise hoặc clockwise tùy triển khai).
 */
class StandardRotator : public ITetrominoRotator {
public:
    /**
     * @brief Xoay khối Tetromino
     * 
     * @param blocks Mảng 4 điểm đại diện cho vị trí các ô của khối Tetromino
     * 
     * Phương thức này sẽ cập nhật vị trí của các ô trong blocks
     * để xoay khối theo quy tắc xoay chuẩn.
     */
    void rotate(Point (&blocks)[4]) override;
};

#endif
