#ifndef IEFFECT_H
#define IEFFECT_H

#include <SFML/Graphics.hpp>

/**
 * @brief Interface cho các hiệu ứng đồ họa
 * 
 * Tuân theo nguyên tắc Interface Segregation Principle (ISP) của SOLID,
 * interface này chỉ chứa các phương thức cần thiết cho tất cả các loại hiệu ứng.
 */
class IEffect {
public:
    virtual ~IEffect() = default;
    
    /**
     * @brief Cập nhật trạng thái hiệu ứng
     * @param deltaTime Thời gian đã trôi qua từ frame trước
     * @return true nếu hiệu ứng vẫn đang hoạt động, false nếu kết thúc
     */
    virtual bool update(float deltaTime) = 0;
    
    /**
     * @brief Vẽ hiệu ứng lên cửa sổ
     * @param window Cửa sổ để vẽ hiệu ứng
     */
    virtual void render(sf::RenderWindow& window) = 0;
    
    /**
     * @brief Kiểm tra hiệu ứng có đang hoạt động không
     * @return true nếu hiệu ứng đang hoạt động
     */
    virtual bool isActive() const = 0;
};

#endif // IEFFECT_H
