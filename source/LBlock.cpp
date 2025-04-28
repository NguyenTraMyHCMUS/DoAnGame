#include "LBlock.h"

LBlock::LBlock() {
    id = 3;
    cells[0] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}};  // Hình L
    cells[1] = {{1, -1}, {1, 0}, {1, 1}, {2, -1}};  // Xoay 90 độ
}

void LBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Blue);  // Đặt màu cho khối L
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
