#ifndef TETROMINO_RENDERER_H
#define TETROMINO_RENDERER_H

#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Interface/ITetrominoRenderer.h"
#include "../Interface/IRenderingStrategy.h"
#include <memory>

using namespace sf;

/**
 * @file TetrominoRenderer.h
 * @brief Định nghĩa lớp TetrominoRenderer để vẽ khối Tetromino
 */

/**
 * @class TetrominoRenderer
 * @brief Lớp để hiển thị khối Tetromino lên cửa sổ game sử dụng SFML.
 * 
 * Lớp này tuân thủ nguyên tắc Single Responsibility Principle (SRP) trong SOLID,
 * chỉ chịu trách nhiệm về việc vẽ khối Tetromino.
 * 
 * Sử dụng mẫu thiết kế Strategy để có thể thay đổi cách vẽ (rendering strategy) linh hoạt.
 */
class TetrominoRenderer : public ITetrominoRenderer {
private:
    /**
     * @brief Tham chiếu tới mảng 4 điểm đại diện cho các ô của khối Tetromino
     */
    const Point (&_blocks)[4];

    /**
     * @brief Kích thước (pixel) của mỗi ô trong khối Tetromino
     */
    int _cellSize;

    /**
     * @brief Chiến lược vẽ (Rendering Strategy) dùng để tùy chỉnh cách hiển thị khối
     */
    std::unique_ptr<IRenderingStrategy> _strategy;

public:
    /**
     * @brief Constructor khởi tạo với mảng ô, kích thước ô và chiến lược vẽ tùy chọn
     * 
     * @param blocks Mảng 4 điểm của khối Tetromino
     * @param cellSize Kích thước mỗi ô (pixel)
     * @param strategy Con trỏ thông minh tới chiến lược vẽ (mặc định nullptr)
     */
    TetrominoRenderer(const Point (&blocks)[4], int cellSize, std::unique_ptr<IRenderingStrategy> strategy = nullptr);
    
    /**
     * @brief Constructor khởi tạo với mảng ô và kích thước ô mặc định
     * 
     * @param blocks Mảng 4 điểm của khối Tetromino
     */
    TetrominoRenderer(const Point (&blocks)[4]);

    /**
     * @brief Thiết lập kích thước của mỗi ô
     * 
     * @param size Kích thước mới cho mỗi ô (pixel)
     */
    void setCellSize(int size);

    /**
     * @brief Lấy kích thước hiện tại của mỗi ô
     * 
     * @return Kích thước mỗi ô (pixel)
     */
    int getCellSize() const;

    /**
     * @brief Vẽ khối Tetromino lên cửa sổ SFML
     * 
     * @param window Cửa sổ SFML để vẽ lên
     * @param sprite Sprite dùng để hiển thị (có thể dùng texture)
     * @param color Màu sắc đại diện cho khối Tetromino
     */
    void draw(RenderWindow& window, Sprite& sprite, int color) const;

    /**
     * @brief Thiết lập hoặc thay đổi chiến lược vẽ (Rendering Strategy)
     * 
     * Cho phép thay đổi linh hoạt cách thức hiển thị khối mà không cần thay đổi lớp TetrominoRenderer
     * 
     * @param strategy Chiến lược vẽ mới được truyền dưới dạng unique_ptr
     */
    void setRenderingStrategy(std::unique_ptr<IRenderingStrategy> strategy);
};

#endif
