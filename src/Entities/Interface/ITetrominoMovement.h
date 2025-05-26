#ifndef ITETROMINO_MOVEMENT_H
#define ITETROMINO_MOVEMENT_H

#include "../Point.h"

/**
 * @brief Interface cho việc di chuyển khối Tetromino
 * 
 * Tuân thủ nguyên tắc Interface Segregation (ISP) trong SOLID,
 * interface này chỉ chứa các phương thức liên quan đến việc di chuyển.
 */
class ITetrominoMovement {
public:
    virtual ~ITetrominoMovement() = default;
    
    /**
     * @brief Di chuyển khối theo chiều ngang
     * 
     * @param dx Khoảng cách di chuyển (dương là sang phải, âm là sang trái)
     */
    virtual void move(int dx) = 0;
    
    /**
     * @brief Di chuyển khối xuống dưới một ô
     */
    virtual void fall() = 0;
};

#endif
