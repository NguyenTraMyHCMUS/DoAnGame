// PreviewRenderingStrategy.h
#ifndef PREVIEW_RENDERING_STRATEGY_H
#define PREVIEW_RENDERING_STRATEGY_H

#include "../Interface/IRenderingStrategy.h"

/**
 * @file PreviewRenderingStrategy.h
 * @brief Định nghĩa lớp PreviewRenderingStrategy để vẽ bản xem trước (preview) khối Tetromino.
 */

/**
 * @class PreviewRenderingStrategy
 * @brief Chiến lược vẽ bản xem trước khối Tetromino trong giao diện game.
 * 
 * Lớp này cài đặt interface IRenderingStrategy, tập trung vào việc
 * vẽ khối Tetromino tại một vị trí cố định (thường là vùng preview).
 * Vị trí cơ sở (_basePosition) có thể được tùy chỉnh khi khởi tạo đối tượng.
 */
class PreviewRenderingStrategy : public IRenderingStrategy {
private:
    /**
     * @brief Vị trí cơ sở dùng để hiển thị khối preview trên cửa sổ game
     */
    sf::Vector2f _basePosition;

public:
    /**
     * @brief Constructor khởi tạo PreviewRenderingStrategy với vị trí cơ sở tùy chọn
     * 
     * @param basePos Vị trí cơ sở (mặc định là {240, 50})
     */
    PreviewRenderingStrategy(sf::Vector2f basePos = {240, 50});

    /**
     * @brief Thực hiện vẽ khối Tetromino ở vị trí preview
     * 
     * @param window Cửa sổ SFML để vẽ lên
     * @param sprite Sprite để dùng khi vẽ khối
     * @param position Vị trí tương đối của ô trong khối Tetromino
     * @param cellSize Kích thước mỗi ô vuông
     * @param color Màu sắc của khối
     */
    void render(sf::RenderWindow& window, sf::Sprite& sprite, const Point& position, int cellSize, int color) const override;
};

#endif
