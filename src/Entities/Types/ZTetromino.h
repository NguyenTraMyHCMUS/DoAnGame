#ifndef ZTETROMINO_H
#define ZTETROMINO_H

/**
 * @file ZTetromino.h
 * @brief Định nghĩa lớp ZTetromino cho khối Z trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối Z,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#include "../Tetromino.h"
#include "../Task/TypeRotation/StandardRotator.h"

/**
 * @class ZTetromino
 * @brief Lớp đại diện cho khối Z trong trò chơi Tetris.
 * 
 * Khối Z có hình dạng chữ Z và có khả năng xoay theo chiều kim đồng hồ. Lớp này kế thừa từ lớp `Tetromino` và cài đặt các phương thức đặc trưng cho khối Z.
 */
class ZTetromino : public Tetromino {
public:
    /**
     * @brief Constructor khởi tạo khối Z.
     * 
     * Khởi tạo các thuộc tính của khối Z, bao gồm kích thước ô và màu sắc.
     */
    ZTetromino();

    /**
     * @brief Destructor ảo để giải phóng bộ nhớ.
     * 
     * Phương thức này sẽ giải phóng bộ nhớ khi đối tượng khối Z bị hủy.
     */
    ~ZTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng khối Z.
     * 
     * Phương thức này cài đặt hình dạng ban đầu của khối Z (các ô được sắp xếp theo hình chữ Z).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối Z theo chiều kim đồng hồ.
     * 
     * Phương thức này xoay khối Z theo chiều kim đồng hồ khi người chơi thực hiện thao tác xoay.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối Z.
     * 
     * Phương thức này tạo một bản sao của khối Z và trả về một con trỏ duy nhất đến đối tượng bản sao.
     * 
     * @return Một con trỏ duy nhất đến bản sao của khối Z.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
