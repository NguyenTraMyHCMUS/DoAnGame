#ifndef TETROMINO_MOVEMENT_H
#define TETROMINO_MOVEMENT_H

#include "../Point.h"
#include "../Interface/ITetrominoMovement.h"

/**
 * @file TetrominoMovement.h
 * @brief Định nghĩa lớp TetrominoMovement để xử lý việc di chuyển khối Tetromino
 */

/**
 * @class TetrominoMovement
 * @brief Lớp chịu trách nhiệm di chuyển khối Tetromino
 * 
 * Lớp này tuân thủ nguyên tắc Single Responsibility Principle (SRP) trong SOLID,
 * chỉ xử lý việc di chuyển khối Tetromino theo chiều ngang và rơi xuống.
 */
class TetrominoMovement : public ITetrominoMovement {
private:
    /**
     * @brief Tham chiếu đến mảng 4 điểm đại diện cho các ô của khối Tetromino
     */
    Point (&_blocks)[4];

public:
    /**
     * @brief Constructor khởi tạo với mảng các ô của khối Tetromino
     * 
     * @param blocks Mảng 4 điểm của khối Tetromino
     */
    TetrominoMovement(Point (&blocks)[4]);

    /**
     * @brief Hủy đối tượng TetrominoMovement
     * 
     * Phương thức hủy ảo đảm bảo lớp kế thừa được hủy đúng cách.
     */
    void move(int dx) override;

    /**
     * @brief Di chuyển khối Tetromino xuống dưới một ô
     */
    void fall() override;
};

#endif
