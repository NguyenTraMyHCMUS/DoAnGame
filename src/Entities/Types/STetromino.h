/**
 * @file STetromino.h
 * @brief Định nghĩa lớp STetromino cho khối S trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối S,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#ifndef STETROMINO_H
#define STETROMINO_H

#include "../Tetromino.h"
#include "../Task/TypeRotation/StandardRotator.h"

/**
 * @class STetromino
 * @brief Lớp đại diện cho khối S trong trò chơi Tetris.
 * 
 * Khối S là một trong các hình dạng Tetromino có cấu trúc đặc trưng và có thể xoay được. Khối này tạo thành hình chữ S khi nằm ngang.
 */
class STetromino : public Tetromino {
public:
    /**
     * @brief Constructor cho khối S.
     * 
     * Khởi tạo khối S với hình dạng ban đầu.
     */
    STetromino();

    /**
     * @brief Destructor cho khối S.
     * 
     * Giải phóng bộ nhớ khi khối S bị hủy.
     */
    ~STetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng của khối S.
     * 
     * Phương thức này thiết lập hình dạng ban đầu của khối S, thường là một hình dạng giống như chữ S.
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối S theo chiều kim đồng hồ.
     * 
     * Phương thức này xoay khối S theo chiều kim đồng hồ, thay đổi vị trí của các ô trong khối.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối S.
     * 
     * Phương thức này tạo một bản sao mới của khối S bằng cách sao chép dữ liệu hiện tại.
     * 
     * @return Một con trỏ duy nhất đến bản sao của khối S.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
