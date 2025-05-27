#ifndef ITETROMINO_RENDERER_H
#define ITETROMINO_RENDERER_H

#include <SFML/Graphics.hpp>

/**
 * @file ITetrominoRenderer.h
 * @brief Giao diện định nghĩa chức năng hiển thị khối Tetromino lên màn hình.
 */

/**
 * @class ITetrominoRenderer
 * @brief Interface quy định các chức năng liên quan đến việc vẽ khối Tetromino trong game.
 *
 * Tuân thủ nguyên lý **Interface Segregation Principle (ISP)** trong SOLID:
 * - Chỉ tập trung vào logic hiển thị, không liên quan đến logic di chuyển hay trạng thái.
 */
class ITetrominoRenderer {
public:
    /**
     * @brief Hàm hủy ảo để đảm bảo giải phóng tài nguyên đúng cách khi sử dụng đa hình.
     */
    virtual ~ITetrominoRenderer() = default;

    /**
     * @brief Vẽ khối Tetromino lên cửa sổ game.
     *
     * @param window Đối tượng cửa sổ của SFML để vẽ lên.
     * @param sprite Đối tượng sprite được sử dụng để vẽ các ô của khối.
     * @param color Mã màu đại diện cho loại khối.
     */
    virtual void draw(sf::RenderWindow& window, sf::Sprite& sprite, int color) const = 0;

    /**
     * @brief Thiết lập kích thước mỗi ô của khối Tetromino.
     *
     * @param size Kích thước (pixel) cho mỗi ô vuông của khối.
     */
    virtual void setCellSize(int size) = 0;

    /**
     * @brief Lấy kích thước hiện tại của mỗi ô khối.
     *
     * @return Kích thước (pixel) của ô khối.
     */
    virtual int getCellSize() const = 0;
};

#endif // ITETROMINO_RENDERER_H
