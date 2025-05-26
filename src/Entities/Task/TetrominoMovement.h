#ifndef TETROMINO_MOVEMENT_H
#define TETROMINO_MOVEMENT_H

#include "../Point.h"
#include "../Interface/ITetrominoMovement.h"

class TetrominoMovement : public ITetrominoMovement {
    private:
        Point (&_blocks)[4]; /**< Mảng chứa 4 ô của khối Tetris */

    public:
        TetrominoMovement(Point (&blocks)[4]); /**< Constructor khởi tạo mảng ô */
        
        void move(int dx) override; /**< Di chuyển khối theo chiều ngang */
        void fall() override; /**< Di chuyển khối xuống dưới */
};

#endif
