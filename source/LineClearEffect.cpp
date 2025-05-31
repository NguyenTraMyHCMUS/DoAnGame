#include "LineClearEffect.h"

LineClearEffect::LineClearEffect(int cellSize, sf::Vector2f offset, int gridWidth)
    : _duration(0.6f), _elapsedTime(0.0f), _flashInterval(0.1f),
      _isActive(false), _isFlashOn(false), _cellSize(cellSize), _offset(offset),
      _gridWidth(gridWidth), _flashColor(sf::Color::Yellow) {
}

void LineClearEffect::init(const std::vector<int>& lines) {
    _lines = lines;
    _elapsedTime = 0.0f;
    _isActive = true;
    _isFlashOn = true;
}

bool LineClearEffect::update(float deltaTime) {
    if (!_isActive) {
        return false;
    }
    
    _elapsedTime += deltaTime;
    
    // Kiểm tra kết thúc hiệu ứng
    if (_elapsedTime >= _duration) {
        _isActive = false;
        return false;
    }
    
    // Cập nhật trạng thái nhấp nháy
    if (static_cast<int>(_elapsedTime / _flashInterval) % 2 == 0) {
        _isFlashOn = true;
    } else {
        _isFlashOn = false;
    }
    
    return true;
}

void LineClearEffect::render(sf::RenderWindow& window) {
    if (!_isActive || !_isFlashOn) {
        return;
    }
    
    // Vẽ hình chữ nhật sáng cho các dòng đang xóa
    for (int line : _lines) {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(_gridWidth * _cellSize, _cellSize));
        rect.setPosition(_offset.x, line * _cellSize + _offset.y);
        rect.setFillColor(_flashColor);
        window.draw(rect);
    }
}

bool LineClearEffect::isActive() const {
    return _isActive;
}

const std::vector<int>& LineClearEffect::getLines() const {
    return _lines;
}
