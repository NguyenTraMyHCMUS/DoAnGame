#ifndef ITETROMINO_LOCKER_H
#define ITETROMINO_LOCKER_H

#include "../Field.h"

/**
 * @file ITetrominoLocker.h
 * @brief Giao diện định nghĩa chức năng cố định khối Tetromino vào lưới trò chơi.
 */

/**
 * @class ITetrominoLocker
 * @brief Interface dùng để xác định hành vi cố định (lock) Tetromino vào lưới sau khi rơi xong.
 *
 * Áp dụng nguyên lý **Interface Segregation Principle (ISP)** trong SOLID:
 * - Chỉ tập trung vào một chức năng duy nhất là "cố định khối".
 * - Cho phép các thành phần khác sử dụng mà không bị ràng buộc với các chức năng không liên quan.
 */
class ITetrominoLocker {
public:
    /**
     * @brief Hàm hủy ảo để đảm bảo hủy tài nguyên đúng cách khi dùng đa hình.
     */
    virtual ~ITetrominoLocker() = default;

    /**
     * @brief Thực hiện việc cố định khối Tetromino vào lưới chơi (Field).
     * 
     * Phương thức này sẽ cập nhật dữ liệu lưới tại các vị trí tương ứng với khối Tetromino
     * bằng màu sắc đã chỉ định, đánh dấu rằng khối này không còn có thể di chuyển.
     *
     * @param field Lưới trò chơi (Field) nơi khối được cố định.
     * @param color Màu của khối được ghi vào lưới (dùng để hiển thị).
     */
    virtual void lock(Field& field, int color) const = 0;
};

#endif // ITETROMINO_LOCKER_H
