#ifndef ITETROMINO_RENDERER_H
#define ITETROMINO_RENDERER_H

#include <SFML/Graphics.hpp>

/**
 * @brief Interface cho việc vẽ khối Tetromino
 * 
 * Tuân thủ nguyên tắc Interface Segregation (ISP) trong SOLID,
 * interface này chỉ chứa các phương thức liên quan đến việc hiển thị.
 */
class ITetrominoRenderer {
public:
    virtual ~ITetrominoRenderer() = default;
    
    /**
     * @brief Vẽ khối Tetris lên cửa sổ
     * 
     * @param window Cửa sổ để vẽ lên
     * @param sprite Sprite để hiển thị khối
     * @param color Màu sắc của khối
     */
    virtual void draw(sf::RenderWindow& window, sf::Sprite& sprite, int color) const = 0;
    
    /**
     * @brief Thiết lập kích thước cho mỗi ô
     * 
     * @param size Kích thước mới
     */
    virtual void setCellSize(int size) = 0;
    virtual int getCellSize() const = 0;
};

#endif
