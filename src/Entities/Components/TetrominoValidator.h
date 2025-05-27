#ifndef TETROMINO_VALIDATOR_H
#define TETROMINO_VALIDATOR_H

#include "../Interface/ITetrominoValidator.h"

/**
 * @file TetrominoValidator.h
 * @brief Định nghĩa lớp TetrominoValidator dùng để kiểm tra tính hợp lệ của khối Tetromino trên lưới game.
 */

/**
 * @class TetrominoValidator
 * @brief Lớp kiểm tra tính hợp lệ của khối Tetromino trên lưới game.
 * 
 * Lớp này tuân thủ nguyên tắc Single Responsibility Principle (SRP) trong SOLID,
 * chỉ đảm nhiệm trách nhiệm kiểm tra xem các ô của khối Tetromino có thể đặt vào
 * lưới hay không mà không phụ thuộc vào các chức năng khác.
 */
class TetrominoValidator : public ITetrominoValidator {
private:
    /**
     * @brief Mảng 4 điểm đại diện cho các ô của khối Tetromino
     * 
     * Sử dụng tham chiếu mảng cố định 4 phần tử để đảm bảo không sao chép dữ liệu,
     * và giữ nguyên trạng thái các ô của khối cần kiểm tra.
     */
    const Point (&_blocks)[4];

public:
    /**
     * @brief Constructor khởi tạo TetrominoValidator với mảng các ô của khối Tetromino
     * 
     * @param blocks Mảng chứa 4 điểm đại diện cho các ô của khối Tetris
     */
    TetrominoValidator(const Point (&blocks)[4]) : _blocks(blocks) {}

    /**
     * @brief Destructor ảo để đảm bảo các lớp kế thừa được hủy đúng cách
     */
    ~TetrominoValidator() override = default;

    /**
     * @brief Kiểm tra tính hợp lệ của khối Tetromino trên lưới game
     * 
     * Phương thức này sẽ kiểm tra từng ô trong mảng `_blocks` xem có nằm trong
     * biên giới của lưới hay không và vị trí đó có bị chiếm bởi ô khác hay không.
     * 
     * @param field Lưới game để kiểm tra
     * @return true nếu tất cả các ô đều hợp lệ và có thể đặt vào lưới
     * @return false nếu có ít nhất một ô không hợp lệ hoặc bị chiếm
     */
    bool isValid(const Field& field) const override;
};

#endif
