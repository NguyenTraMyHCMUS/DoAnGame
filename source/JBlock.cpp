#include "JBlock.h"

JBlock::JBlock() {
    id = 2;
    cells[0] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};  // Hình J
    cells[1] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};  // Xoay 90 độ
}

void JBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Blue);  // Đặt màu cho khối J
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
