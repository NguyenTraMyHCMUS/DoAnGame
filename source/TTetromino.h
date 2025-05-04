/**
 * @file TTetromino.h
 * @brief Định nghĩa lớp TTetromino cho khối T trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối T,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#ifndef TTETROMINO_H
#define TTETROMINO_H

#include "Tetromino.h"

/**
 * @class TTetromino
 * @brief Lớp đại diện cho khối T trong trò chơi Tetris.
 * 
 * Khối T có hình dạng chữ T và có khả năng xoay theo chiều kim đồng hồ. Lớp này kế thừa từ lớp `Tetromino` và cài đặt các phương thức đặc trưng cho khối T.
 */
class TTetromino : public Tetromino {
public:
    /**
     * @brief Constructor khởi tạo khối T.
     * 
     * Khởi tạo các thuộc tính của khối T, bao gồm kích thước ô và màu sắc.
     */
    TTetromino();

    /**
     * @brief Destructor ảo để giải phóng bộ nhớ.
     * 
     * Phương thức này sẽ giải phóng bộ nhớ khi đối tượng khối T bị hủy.
     */
    ~TTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng khối T.
     * 
     * Phương thức này cài đặt hình dạng ban đầu của khối T (các ô được sắp xếp theo hình chữ T).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối T theo chiều kim đồng hồ.
     * 
     * Phương thức này xoay khối T theo chiều kim đồng hồ khi người chơi thực hiện thao tác xoay.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối T.
     * 
     * Phương thức này tạo một bản sao của khối T và trả về một con trỏ duy nhất đến đối tượng bản sao.
     * 
     * @return Một con trỏ duy nhất đến bản sao của khối T.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
