#ifndef ITETROMINO_H
#define ITETROMINO_H

/**
 * @file ITetromino.h
 * @brief Định nghĩa lớp ITetromino đại diện cho khối hình chữ I trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cung cấp các phương thức đặc trưng cho khối I,
 * bao gồm khởi tạo hình dạng, xoay khối, và tạo bản sao.
 */

#include "../Tetromino.h"
#include "../Task/TypeRotation/IRotator.h"

/**
 * @class ITetromino
 * @brief Lớp đại diện cho khối Tetromino hình chữ I trong trò chơi Tetris.
 * 
 * Khối I là một trong bảy hình dạng Tetromino cơ bản. Nó có hình dạng đặc trưng là
 * một đường thẳng dài, có thể xoay để chuyển đổi giữa trạng thái ngang và dọc.
 * Lớp này định nghĩa cách khối I được khởi tạo, xoay, và sao chép.
 */
class ITetromino : public Tetromino {
public:
    /**
     * @brief Constructor khởi tạo khối I với hình dạng ban đầu.
     * 
     * Thiết lập trạng thái ban đầu của khối I, bao gồm vị trí và hình dạng mặc định.
     */
    ITetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     * 
     * Đảm bảo việc giải phóng bộ nhớ được thực hiện đúng cách khi đối tượng bị hủy.
     */
    ~ITetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối I.
     * 
     * Thiết lập ma trận biểu diễn khối I ở trạng thái ban đầu (dạng ngang).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối I giữa trạng thái ngang và dọc.
     * 
     * Thay đổi ma trận biểu diễn khối I để phản ánh trạng thái sau khi xoay.
     * Nếu khối I đang ở trạng thái ngang, nó sẽ chuyển sang trạng thái dọc và ngược lại.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối I.
     * 
     * Sử dụng Prototype Pattern để tạo một đối tượng mới giống hệt khối I hiện tại.
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối I.
     */
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
