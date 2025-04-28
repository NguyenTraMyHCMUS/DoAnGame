#include "TBlock.h"

TBlock::TBlock() {
    id = 6;
    cells[0] = {{0, 0}, {1, 0}, {2, 0}, {1, 1}};  // Hình T
    cells[1] = {{1, -1}, {1, 0}, {1, 1}, {0, 0}};  // Xoay 90 độ
}

void TBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Magenta);  // Đặt màu cho khối T
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
