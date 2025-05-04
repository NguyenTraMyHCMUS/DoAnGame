#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "Tetromino.h"

/**
 * @class OTetromino
 * @brief Lớp đại diện cho khối O trong trò chơi Tetris.
 * 
 * Khối O là một trong các hình dạng Tetromino có cấu trúc cố định, không xoay được.
 */
class OTetromino : public Tetromino {
public:
    /**
     * @brief Constructor cho khối O.
     * 
     * Khởi tạo khối O với hình dạng ban đầu.
     */
    OTetromino();

    /**
     * @brief Destructor cho khối O.
     * 
     * Giải phóng bộ nhớ khi khối O bị hủy.
     */
    ~OTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng của khối O.
     * 
     * Phương thức này thiết lập hình dạng ban đầu của khối O (một ô vuông 2x2).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối O.
     * 
     * Phương thức này không làm gì vì khối O không thay đổi khi xoay.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối O.
     * 
     * Phương thức này tạo một bản sao mới của khối O bằng cách sao chép dữ liệu hiện tại.
     * 
     * @return Một con trỏ duy nhất đến bản sao của khối O.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
