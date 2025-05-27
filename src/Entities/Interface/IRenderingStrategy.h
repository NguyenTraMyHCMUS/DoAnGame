// IRenderingStrategy.h
#ifndef IRENDERING_STRATEGY_H
#define IRENDERING_STRATEGY_H

#include <SFML/Graphics.hpp>
#include "../Point.h"

/**
 * @file IRenderingStrategy.h
 * @brief Định nghĩa interface IRenderingStrategy để vẽ các đối tượng lên cửa sổ game.
 */

/**
 * @class IRenderingStrategy
 * @brief Giao diện trừu tượng (interface) định nghĩa chiến lược vẽ đối tượng lên cửa sổ game.
 *
 * Interface này cho phép linh hoạt trong việc thay đổi cách hiển thị đối tượng,
 * tuân thủ nguyên lý DIP (Dependency Inversion Principle) trong SOLID:
 * các lớp phụ thuộc vào abstraction thay vì implementation cụ thể.
 */
class IRenderingStrategy {
public:
    /**
     * @brief Hàm hủy ảo giúp đảm bảo việc hủy đúng cách khi sử dụng con trỏ đa hình.
     */
    virtual ~IRenderingStrategy() = default;

    /**
     * @brief Phương thức vẽ đối tượng lên cửa sổ game.
     *
     * Được sử dụng để hiển thị đối tượng với thông tin cụ thể về vị trí, kích thước, màu sắc, v.v.
     *
     * @param window Đối tượng `sf::RenderWindow` đại diện cho cửa sổ game nơi cần vẽ.
     * @param sprite Sprite đại diện hình ảnh được sử dụng để vẽ (có thể dùng chung cho nhiều block).
     * @param position Vị trí lưới (tọa độ logic) nơi vẽ sprite, được biểu diễn bởi `Point`.
     * @param cellSize Kích thước chiều rộng/cao của mỗi ô (block) trong đơn vị pixel.
     * @param color Mã màu (có thể là index, hoặc RGB được encode) để hiển thị sprite với màu tương ứng.
     */
    virtual void render(sf::RenderWindow& window, sf::Sprite& sprite, const Point& position, int cellSize, int color) const = 0;
};

#endif // IRENDERING_STRATEGY_H
