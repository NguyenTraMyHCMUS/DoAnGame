#include "GameFieldRenderingStrategy.h"

// Hàm khởi tạo của lớp GameFieldRenderingStrategy
GameFieldRenderingStrategy::GameFieldRenderingStrategy(sf::Vector2f offset) : _offset(offset) {}

// Phương thức render để vẽ một ô trên cửa sổ game
void GameFieldRenderingStrategy::render(sf::RenderWindow& window, sf::Sprite& sprite, const Point& position, int cellSize, int color) const {
    sprite.setTextureRect(sf::IntRect(color * cellSize, 0, cellSize, cellSize));
    sprite.setPosition(position.getX() * cellSize + _offset.x, position.getY() * cellSize + _offset.y);
    window.draw(sprite);
}

// Phương thức để đặt offset cho việc vẽ
void GameFieldRenderingStrategy::setOffset(sf::Vector2f offset) { 
    _offset = offset; 
}
