#ifndef JTETROMINO_H
#define JTETROMINO_H

/**
 * @file JTetromino.h
 * @brief Định nghĩa lớp JTetromino đại diện cho khối hình chữ J trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cung cấp các phương thức đặc trưng cho khối J,
 * bao gồm khởi tạo hình dạng, xoay khối, và tạo bản sao.
 */

#include "../Tetromino.h"
#include "../Task/TypeRotation/CounterclockwiseRotator.h"

/**
 * @class JTetromino
 * @brief Lớp đại diện cho khối Tetromino hình chữ J trong trò chơi Tetris.
 * 
 * Khối J là một trong bảy hình dạng Tetromino cơ bản. Nó có hình dạng đặc trưng giống
 * chữ "J" và có thể xoay để thay đổi hướng. Lớp này định nghĩa cách khối J được khởi tạo,
 * xoay, và sao chép.
 */
class JTetromino : public Tetromino {
public:
    /**
     * @brief Constructor khởi tạo khối J với hình dạng ban đầu.
     * 
     * Thiết lập trạng thái ban đầu của khối J, bao gồm vị trí và hình dạng mặc định.
     */
    JTetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     * 
     * Đảm bảo việc giải phóng bộ nhớ được thực hiện đúng cách khi đối tượng bị hủy.
     */
    ~JTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối J.
     * 
     * Thiết lập ma trận biểu diễn khối J ở trạng thái ban đầu (chưa xoay).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối J theo chiều ngược kim đồng hồ.
     * 
     * Thay đổi ma trận biểu diễn khối J để phản ánh trạng thái sau khi xoay.
     * Nếu khối J đạt trạng thái xoay cuối cùng, nó sẽ quay lại trạng thái ban đầu.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối J.
     * 
     * Sử dụng Prototype Pattern để tạo một đối tượng mới giống hệt khối J hiện tại.
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối J.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
