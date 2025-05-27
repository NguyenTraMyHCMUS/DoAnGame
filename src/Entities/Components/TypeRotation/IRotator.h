#ifndef I_ROTATOR_H  
#define I_ROTATOR_H

#include "../../Interface/ITetrominoRotator.h"

/**
 * @file IRotator.h
 * @brief Định nghĩa lớp IRotator để xoay khối Tetromino dạng chữ I
 */

/**
 * @class IRotator
 * @brief Lớp thực thi việc xoay khối Tetromino dạng chữ I
 * 
 * Khối I có đặc điểm chỉ có 2 trạng thái xoay: ngang và dọc,
 * do đó lớp này quản lý trạng thái xoay hiện tại (_isHorizontal),
 * và cài đặt phương thức xoay sao cho phù hợp với đặc thù của khối I.
 */
class IRotator : public ITetrominoRotator {
private:
    bool _isHorizontal = true; ///< Trạng thái xoay hiện tại: true là ngang, false là dọc

public:
    /**
     * @brief Xoay khối Tetromino dạng chữ I giữa 2 trạng thái ngang và dọc
     * 
     * @param blocks Mảng 4 điểm đại diện cho vị trí các ô của khối Tetromino
     * 
     * Phương thức sẽ thay đổi vị trí các ô trong mảng để xoay khối I,
     * chuyển đổi trạng thái từ ngang sang dọc hoặc ngược lại.
     */
    void rotate(Point (&blocks)[4]) override;
};

#endif
