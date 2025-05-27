// GameFieldRenderingStrategy.h
#ifndef GAME_FIELD_RENDERING_STRATEGY_H
#define GAME_FIELD_RENDERING_STRATEGY_H

#include "../Interface/IRenderingStrategy.h"

/**
 * @file GameFieldRenderingStrategy.h
 * @brief Định nghĩa lớp GameFieldRenderingStrategy để vẽ khối Tetromino lên lưới game chính.
 */

/**
 * @class GameFieldRenderingStrategy
 * @brief Chiến lược vẽ khối Tetromino trên lưới game.
 * 
 * Lớp này cài đặt interface IRenderingStrategy, chịu trách nhiệm
 * vẽ các ô Tetromino với vị trí được dịch chuyển theo _offset,
 * phù hợp để vẽ trực tiếp lên vùng chơi chính trong game.
 */
class GameFieldRenderingStrategy : public IRenderingStrategy {
private:
    /**
     * @brief Vị trí dịch chuyển (offset) để căn chỉnh khối Tetromino trên lưới game
     */
    sf::Vector2f _offset; 
    
public:
    /**
     * @brief Constructor khởi tạo GameFieldRenderingStrategy với offset tùy chọn
     * 
     * @param offset Vị trí dịch chuyển (mặc định là {28, 31})
     */
    GameFieldRenderingStrategy(sf::Vector2f offset = {28, 31});
    
    /**
     * @brief Thực hiện vẽ khối Tetromino lên lưới game
     * 
     * @param window Cửa sổ SFML để vẽ lên
     * @param sprite Sprite dùng để vẽ khối
     * @param position Vị trí tương đối của ô trong khối Tetromino
     * @param cellSize Kích thước mỗi ô
     * @param color Màu sắc của khối
     */
    void render(sf::RenderWindow& window, sf::Sprite& sprite, const Point& position, int cellSize, int color) const override;
    
    /**
     * @brief Thiết lập vị trí dịch chuyển offset mới
     * 
     * @param offset Vị trí dịch chuyển mới
     */
    void setOffset(sf::Vector2f offset);
};

#endif
