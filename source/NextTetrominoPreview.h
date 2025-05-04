#ifndef NEXTTETROMINOPREVIEW_H
#define NEXTTETROMINOPREVIEW_H

#include "TetrominoFactory.h"
#include <memory>

/**
 * @class NextTetrominoPreview
 * @brief Lớp đại diện cho bản xem trước của Tetromino tiếp theo trong trò chơi Tetris.
 * 
 * Lớp này quản lý việc tạo ra và hiển thị Tetromino tiếp theo, cũng như cung cấp các phương thức để lấy và sao chép Tetromino đó.
 */
class NextTetrominoPreview {
private:
    std::unique_ptr<Tetromino> _next; /**< Con trỏ duy nhất quản lý Tetromino tiếp theo */
    sf::Vector2f _position; /**< Vị trí của bản xem trước Tetromino */
    int _cellSize; /**< Kích thước ô vuông cho mỗi hình tế bào của Tetromino */

public:
    /**
     * @brief Constructor mặc định cho lớp NextTetrominoPreview.
     * 
     * Khởi tạo đối tượng xem trước Tetromino với các giá trị mặc định.
     */
    NextTetrominoPreview();

    /**
     * @brief Sinh ra Tetromino tiếp theo.
     * 
     * Phương thức này tạo ra một Tetromino mới cho bản xem trước bằng cách gọi đến factory.
     */
    void generateNext();

    /**
     * @brief Lấy Tetromino tiếp theo.
     * 
     * @return Một con trỏ duy nhất đến Tetromino tiếp theo.
     */
    std::unique_ptr<Tetromino> getNext();

    /**
     * @brief Sao chép Tetromino tiếp theo.
     * 
     * Phương thức này tạo ra một bản sao của Tetromino tiếp theo.
     * 
     * @return Một con trỏ duy nhất đến bản sao của Tetromino tiếp theo.
     */
    std::unique_ptr<Tetromino> cloneNext() const;

    /**
     * @brief Vẽ bản xem trước Tetromino lên cửa sổ.
     * 
     * Phương thức này vẽ hình ảnh của Tetromino tiếp theo lên cửa sổ của trò chơi.
     * 
     * @param window Cửa sổ render nơi bản xem trước sẽ được vẽ.
     * @param sprite Sprite dùng để vẽ các ô của Tetromino.
     */
    void draw(sf::RenderWindow& window, sf::Sprite& sprite);
};

#endif
