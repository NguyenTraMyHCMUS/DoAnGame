#ifndef STETROMINO_H
#define STETROMINO_H

/**
 * @file STetromino.h
 * @brief Định nghĩa lớp STetromino cho khối S trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối S,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#include "../Tetromino.h"

/**
 * @class STetromino
 * @brief Lớp đại diện cho khối S trong trò chơi Tetris.
 * 
 * Khối S là một trong các hình dạng Tetromino có cấu trúc đặc trưng và có thể xoay được. 
 * Khối này tạo thành hình chữ S khi nằm ngang.
 */
class STetromino : public Tetromino {
private:
    /**
     * @brief Thiết lập bộ xoay cho khối S.
     * 
     * Phương thức này thiết lập bộ xoay cho khối S để có thể xoay khối theo quy tắc.
     */
    void setupRotator();

public:
    /**
     * @brief Constructor khởi tạo khối S với thành phần từ factory.
     * 
     * Khởi tạo các thành phần của khối S bằng cách sử dụng một factory để tạo ra các đối tượng cần thiết.
     * @param factory Factory để tạo các thành phần của khối S.
     */
    explicit STetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối S với hình dạng ban đầu.
     */
    STetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     */
    ~STetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối S.
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối S theo chiều kim đồng hồ.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối S.
     * 
     * Sử dụng Prototype Pattern để tạo một đối tượng mới giống hệt khối S hiện tại.
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối S.
     */
    std::unique_ptr<Tetromino> clone() const override;

    /**
     * @brief Lấy tên loại khối S.
     * 
     * @return Tên loại của khối S.
     */
    std::string getTypeName() const override;
};

#endif
