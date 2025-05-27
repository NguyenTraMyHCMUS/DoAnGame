#ifndef ITETROMINO_MOVEMENT_H
#define ITETROMINO_MOVEMENT_H

#include "../Point.h"

/**
 * @file ITetrominoMovement.h
 * @brief Giao diện định nghĩa chức năng di chuyển khối Tetromino trong trò chơi.
 */

/**
 * @class ITetrominoMovement
 * @brief Interface quy định hành vi di chuyển của khối Tetromino trên lưới trò chơi.
 *
 * Áp dụng nguyên lý **Interface Segregation Principle (ISP)** trong SOLID:
 * - Chỉ tập trung vào chức năng di chuyển.
 * - Giúp tách biệt rõ ràng logic di chuyển khỏi các logic khác như xoay hoặc render.
 */
class ITetrominoMovement {
public:
    /**
     * @brief Hàm hủy ảo để đảm bảo hủy tài nguyên đúng cách khi sử dụng đa hình.
     */
    virtual ~ITetrominoMovement() = default;

    /**
     * @brief Di chuyển khối theo phương ngang.
     *
     * Phương thức này thay đổi vị trí của tất cả các ô trong khối theo trục X.
     *
     * @param dx Giá trị dịch chuyển theo trục X (dương: sang phải, âm: sang trái).
     */
    virtual void move(int dx) = 0;

    /**
     * @brief Di chuyển khối xuống một hàng.
     *
     * Phương thức này dịch toàn bộ khối xuống một đơn vị theo trục Y, mô phỏng hiệu ứng trọng lực.
     */
    virtual void fall() = 0;
};

#endif // ITETROMINO_MOVEMENT_H
