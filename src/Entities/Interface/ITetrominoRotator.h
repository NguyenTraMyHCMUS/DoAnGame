#ifndef ITETROMINO_ROTATOR_H
#define ITETROMINO_ROTATOR_H

#include "../Point.h"

/**
 * @file ITetrominoRotator.h
 * @brief Định nghĩa interface cho chức năng xoay khối Tetromino trong game Tetris.
 */

/**
 * @class ITetrominoRotator
 * @brief Interface chuyên trách việc xoay khối Tetromino.
 *
 * Tuân thủ nguyên lý **Interface Segregation Principle (ISP)** trong SOLID:
 * - Chỉ tập trung vào chức năng xoay, không phụ thuộc vào logic khác như di chuyển hay hiển thị.
 */
class ITetrominoRotator {
public:
    /**
     * @brief Hàm hủy ảo để hỗ trợ đa hình và đảm bảo hủy tài nguyên đúng cách.
     */
    virtual ~ITetrominoRotator() = default;

    /**
     * @brief Xoay khối Tetromino bằng cách cập nhật các điểm tọa độ của các ô.
     *
     * @param blocks Mảng gồm 4 điểm đại diện cho vị trí các ô của khối Tetromino.
     *               Sau khi thực hiện, mảng sẽ chứa các vị trí mới sau khi xoay.
     */
    virtual void rotate(Point (&blocks)[4]) = 0;
};

#endif // ITETROMINO_ROTATOR_H
