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

/**
 * @class ZTetromino
 * @brief Lớp đại diện cho khối Z trong trò chơi Tetris.
 * 
 * Khối Z có hình dạng chữ Z và có khả năng xoay theo chiều kim đồng hồ. 
 * Lớp này kế thừa từ lớp `Tetromino` và cài đặt các phương thức đặc trưng cho khối Z.
 */
class ZTetromino : public Tetromino {
private:
    /**
     * @brief Thiết lập bộ xoay cho khối Z.
     * 
     * Phương thức này thiết lập bộ xoay cho khối Z để có thể xoay khối theo quy tắc.
     */
    void setupRotator();

public:
    /**
     * @brief Constructor khởi tạo khối Z với thành phần từ factory.
     * 
     * @param factory Factory để tạo các thành phần của khối Z.
     */
    explicit ZTetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối Z với hình dạng ban đầu.
     */
    ZTetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     */
    ~ZTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối Z.
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối Z theo chiều kim đồng hồ.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối Z.
     * 
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối Z.
     */
    std::unique_ptr<Tetromino> clone() const override;

    /**
     * @brief Lấy tên loại khối Z.
     * 
     * @return Tên loại khối Z.
     */
    std::string getTypeName() const override;
};

#endif
