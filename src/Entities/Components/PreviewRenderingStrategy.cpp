#include "PreviewRenderingStrategy.h"

// Hàm khởi tạo của lớp PreviewRenderingStrategy
PreviewRenderingStrategy::PreviewRenderingStrategy(sf::Vector2f basePos) : _basePosition(basePos) {}

// Hàm render để vẽ một ô trên cửa sổ game
void PreviewRenderingStrategy::render(sf::RenderWindow& window, sf::Sprite& sprite, const Point& position, int cellSize, int color) const {
    sprite.setTextureRect(sf::IntRect(color * cellSize, 0, cellSize, cellSize));
    sprite.setPosition(_basePosition.x + position.getX() * cellSize, _basePosition.y + position.getY() * cellSize);
    window.draw(sprite);
}
