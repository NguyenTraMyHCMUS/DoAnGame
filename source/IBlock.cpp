#include "IBlock.h"

IBlock::IBlock() {
    id = 1;
    cells[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};  // Hình I
    cells[1] = {{1, -1}, {1, 0}, {1, 1}, {1, 2}};  // Xoay 90 độ
}

void IBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Cyan);  // Đặt màu cho khối I
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
