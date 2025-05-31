#ifndef LINE_CLEAR_EFFECT_H
#define LINE_CLEAR_EFFECT_H

#include "IEffect.h"
#include <vector>

/**
 * @brief Hiệu ứng xóa dòng trong Tetris
 * 
 * Tuân theo nguyên tắc Single Responsibility Principle (SRP) của SOLID,
 * lớp này chỉ chịu trách nhiệm tạo hiệu ứng khi xóa dòng.
 */
class LineClearEffect : public IEffect {
private:
    std::vector<int> _lines;     // Các dòng cần xóa
    float _duration;             // Thời gian hiệu ứng
    float _elapsedTime;          // Thời gian đã trôi qua
    float _flashInterval;        // Thời gian giữa các lần nhấp nháy
    bool _isActive;              // Trạng thái hiệu ứng
    bool _isFlashOn;             // Trạng thái nhấp nháy
    int _cellSize;               // Kích thước ô
    sf::Vector2f _offset;        // Vị trí offset của field
    int _gridWidth;              // Chiều rộng lưới
    sf::Color _flashColor;       // Màu nhấp nháy

public:
    /**
     * @brief Khởi tạo hiệu ứng xóa dòng
     * @param cellSize Kích thước ô
     * @param offset Offset của field
     * @param gridWidth Chiều rộng lưới
     */
    LineClearEffect(int cellSize = 18, sf::Vector2f offset = sf::Vector2f(28, 31), int gridWidth = 10);
    
    /**
     * @brief Khởi tạo hiệu ứng với các dòng cần xóa
     * @param lines Danh sách các dòng cần xóa
     */
    void init(const std::vector<int>& lines);
    
    /**
     * @brief Cập nhật hiệu ứng
     * @param deltaTime Thời gian trôi qua từ frame trước
     * @return true nếu hiệu ứng vẫn đang hoạt động
     */
    bool update(float deltaTime) override;
    
    /**
     * @brief Vẽ hiệu ứng
     * @param window Cửa sổ để vẽ
     */
    void render(sf::RenderWindow& window) override;
    
    /**
     * @brief Kiểm tra hiệu ứng có đang hoạt động
     * @return true nếu hiệu ứng đang hoạt động
     */
    bool isActive() const override;
    
    /**
     * @brief Lấy danh sách các dòng đang có hiệu ứng
     * @return Danh sách các dòng
     */
    const std::vector<int>& getLines() const;
};

#endif // LINE_CLEAR_EFFECT_H
