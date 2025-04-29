#include "OBlock.h"

OBlock::OBlock() {
    id = 4;
    cells[0] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};  // Hình O (khối vuông)
}

void OBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Yellow);  // Đặt màu cho khối O
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
