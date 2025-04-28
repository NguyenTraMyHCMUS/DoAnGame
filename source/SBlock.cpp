#include "SBlock.h"

SBlock::SBlock() {
    id = 5;
    cells[0] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};  // Hình S
    cells[1] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};  // Xoay 90 độ
}

void SBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Green);  // Đặt màu cho khối S
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
