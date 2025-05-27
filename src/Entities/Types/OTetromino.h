#ifndef OTETROMINO_H
#define OTETROMINO_H

/**
 * @file OTetromino.h
 * @brief Định nghĩa lớp OTetromino đại diện cho khối hình chữ O trong trò chơi Tetris.
 * 
 * Lớp này kế thừa từ lớp Tetromino và cung cấp các phương thức đặc trưng cho khối O.
 * Khối O có cấu trúc cố định (một hình vuông 2x2) và không thay đổi khi xoay.
 */

#include "../Tetromino.h"

/**
 * @class OTetromino
 * @brief Đại diện cho khối Tetromino hình chữ O trong trò chơi Tetris.
 * 
 * Khối O là một trong bảy hình dạng Tetromino cơ bản. Nó có hình dạng cố định là 
 * một hình vuông 2x2 và không thể xoay. Lớp này định nghĩa cách khối O được khởi tạo 
 * và sao chép.
 */
class OTetromino : public Tetromino {
public:
    /**
     * @brief Constructor khởi tạo khối O với thành phần từ factory.
     * 
     * Khởi tạo các thành phần của khối O bằng cách sử dụng một factory để tạo ra các đối tượng cần thiết.
     * @param factory Factory để tạo các thành phần của khối O.
     */
    explicit OTetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối O với hình dạng ban đầu.
     * 
     * Thiết lập trạng thái ban đầu của khối O, bao gồm vị trí và hình dạng mặc định.
     */
    OTetromino();

    /**
     * @brief Destructor ảo mặc định để giải phóng tài nguyên.
     * 
     * Đảm bảo việc giải phóng bộ nhớ được thực hiện đúng cách khi đối tượng bị hủy.
     */
    ~OTetromino() override = default;

    /**
     * @brief Khởi tạo hình dạng mặc định của khối O.
     * 
     * Thiết lập ma trận biểu diễn khối O ở trạng thái ban đầu (một hình vuông 2x2).
     */
    void initializeShape() override;

    /**
     * @brief Xoay khối O.
     * 
     * Phương thức này không thực hiện bất kỳ thay đổi nào vì khối O có hình dạng cố định 
     * và không thay đổi khi xoay.
     */
    void rotate() override;

    /**
     * @brief Tạo một bản sao của khối O.
     * 
     * Sử dụng Prototype Pattern để tạo một đối tượng mới giống hệt khối O hiện tại.
     * @return Con trỏ thông minh chứa đối tượng bản sao của khối O.
     */
    std::unique_ptr<Tetromino> clone() const override;

    /**
     * @brief Lấy tên loại khối O.
     * 
     * Phương thức này trả về tên loại của khối O.
     * 
     * @return Tên loại của khối O.
     */
    std::string getTypeName() const override;
};

#endif
