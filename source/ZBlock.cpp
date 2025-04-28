#include "ZBlock.h"

ZBlock::ZBlock() {
    id = 7;
    cells[0] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};  // Hình Z
    cells[1] = {{1, -1}, {0, 0}, {1, 0}, {0, 1}};  // Xoay 90 độ
}

void ZBlock::Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setColor(sf::Color::Red);  // Đặt màu cho khối Z
    for (auto& p : cells[rotationState]) {
        sprite.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
        window.draw(sprite);  // Vẽ sprite lên cửa sổ
    }
}
