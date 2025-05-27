#ifndef TETROMINO_LOCKER_H
#define TETROMINO_LOCKER_H

#include "../Point.h"
#include "../Field.h"
#include "../Interface/ITetrominoLocker.h"

/**
 * @file TetrominoLocker.h
 * @brief Định nghĩa lớp TetrominoLocker để cố định khối Tetromino vào lưới game.
 */

/**
 * @class TetrominoLocker
 * @brief Lớp xử lý việc cố định khối Tetromino vào lưới game.
 * 
 * Lớp này tuân thủ nguyên tắc Single Responsibility Principle (SRP) trong SOLID,
 * chỉ đảm nhận trách nhiệm cố định vị trí các ô của khối Tetromino vào lưới khi khối không thể di chuyển tiếp.
 */
class TetrominoLocker : public ITetrominoLocker {
private:
    /**
     * @brief Tham chiếu đến mảng 4 điểm đại diện cho các ô của khối Tetromino
     */
    const Point (&_blocks)[4];

public:
    /**
     * @brief Constructor khởi tạo TetrominoLocker với mảng các ô của khối Tetromino
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối Tetromino
     */
    TetrominoLocker(const Point (&blocks)[4]);
    
    /**
     * @brief Cố định khối Tetromino vào lưới game
     * 
     * Phương thức này sẽ gán màu sắc cho các ô tương ứng trong lưới
     * tại vị trí các điểm của khối Tetromino.
     * 
     * @param field Tham chiếu tới lưới game để cố định khối
     * @param color Màu sắc của khối Tetromino cần cố định
     */
    void lock(Field& field, int color) const;
};

#endif
