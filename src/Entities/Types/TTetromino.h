#ifndef TTETROMINO_H
#define TTETROMINO_H

/**
 * @file TTetromino.h
 * @brief Định nghĩa lớp TTetromino cho khối T trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối T,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#include "../Tetromino.h"

/**
 * @class TTetromino
 * @brief Lớp đại diện cho khối T trong trò chơi Tetris.
 * 
 * Khối T có hình dạng chữ T và có khả năng xoay theo chiều kim đồng hồ. 
 * Lớp này kế thừa từ lớp `Tetromino` và cài đặt các phương thức đặc trưng cho khối T.
 */
class TTetromino : public Tetromino {
private:
    /**
     * @brief Thiết lập bộ xoay cho khối T.
     * 
     * Phương thức này thiết lập bộ xoay cho khối T để có thể xoay khối theo quy tắc.
     */
    void setupRotator();

public:
    /**
     * @brief Constructor khởi tạo khối T với thành phần từ factory.
     * 
     * @param factory Factory để tạo các thành phần của khối T.
     */
    explicit TTetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối T với hình dạng ban đầu.
     */
    TTetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     */
    ~TTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối T.
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối T theo chiều kim đồng hồ.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối T.
     * 
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối T.
     */
    std::unique_ptr<Tetromino> clone() const override;

    /**
     * @brief Lấy tên loại khối T.
     * 
     * @return Tên loại khối T.
     */
    std::string getTypeName() const override;
};

#endif
