#ifndef COUNTERCLOCKWISE_ROTATOR_H
#define COUNTERCLOCKWISE_ROTATOR_H

#include "../../Interface/ITetrominoRotator.h"

/**
 * @file CounterclockwiseRotator.h
 * @brief Định nghĩa lớp CounterclockwiseRotator để xoay khối Tetromino ngược chiều kim đồng hồ
 */

/**
 * @class CounterclockwiseRotator
 * @brief Lớp thực thi việc xoay khối Tetromino theo chiều ngược kim đồng hồ
 * 
 * Lớp này cài đặt interface ITetrominoRotator,
 * cung cấp phương thức xoay các ô của khối Tetromino 4 ô (J, L)
 * theo chiều ngược kim đồng hồ, phù hợp với logic xoay của hầu hết các khối.
 */
class CounterclockwiseRotator : public ITetrominoRotator {
public:
    /**
     * @brief Xoay khối Tetromino 4 ô theo chiều ngược kim đồng hồ
     * 
     * @param blocks Mảng 4 điểm đại diện cho vị trí các ô của khối Tetromino
     * 
     * Hàm sẽ thay đổi vị trí các ô trong mảng để xoay khối một góc 90 độ ngược chiều kim đồng hồ.
     */
    void rotate(Point (&blocks)[4]) override;
};

#endif
