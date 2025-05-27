#ifndef LTETROMINO_H
#define LTETROMINO_H

/**
 * @file LTetromino.h
 * @brief Định nghĩa lớp LTetromino cho khối L trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cài đặt các phương thức đặc trưng cho khối L,
 * bao gồm việc khởi tạo hình dạng, xoay khối và tạo bản sao của khối.
 */

#include "../Tetromino.h"

/**
 * @class LTetromino
 * @brief Lớp đại diện cho khối L trong trò chơi Tetris.
 * 
 * Khối L là một trong bảy hình dạng Tetromino cơ bản trong trò chơi Tetris. 
 * Nó có hình dạng đặc trưng giống chữ "L" và có thể xoay để thay đổi hướng.
 */
class LTetromino : public Tetromino {
private:
    /**
     * @brief Thiết lập bộ xoay cho khối L.
     * 
     * Phương thức này thiết lập bộ xoay cho khối L để có thể xoay khối theo quy tắc.
     */
    void setupRotator();

public:
    /**
     * @brief Constructor khởi tạo khối L với thành phần từ factory.
     * 
     * Khởi tạo các thành phần của khối L bằng cách sử dụng một factory để tạo ra các đối tượng cần thiết.
     * @param factory Factory để tạo các thành phần của khối L.
     */
    explicit LTetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối L với hình dạng ban đầu.
     * 
     * Thiết lập trạng thái ban đầu của khối L, bao gồm vị trí và hình dạng mặc định.
     */
    LTetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     * 
     * Đảm bảo việc giải phóng bộ nhớ được thực hiện đúng cách khi đối tượng bị hủy.
     */
    ~LTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối L.
     * 
     * Thiết lập ma trận biểu diễn khối L ở trạng thái ban đầu (chưa xoay).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối L theo chiều ngược kim đồng hồ.
     * 
     * Thay đổi ma trận biểu diễn khối L để phản ánh trạng thái sau khi xoay.
     * Nếu khối L đạt trạng thái xoay cuối cùng, nó sẽ quay lại trạng thái ban đầu.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối L.
     * 
     * Sử dụng Prototype Pattern để tạo một đối tượng mới giống hệt khối L hiện tại.
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối L.
     */
    std::unique_ptr<Tetromino> clone() const override;

    /**
     * @brief Lấy tên loại khối L.
     * 
     * Phương thức này trả về tên loại của khối L, thường dùng để hiển thị hoặc ghi nhận.
     * 
     * @return Tên loại khối L.
     */
    std::string getTypeName() const override;
};

#endif
