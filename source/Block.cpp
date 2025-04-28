#include "Block.h"
#include "Grid.h"
#include <cstdlib>

const int Block::shapes[7][4] = {
    {1, 3, 5, 7}, // I
    {2, 4, 5, 7}, // Z
    {3, 5, 4, 6}, // S
    {3, 5, 4, 7}, // T
    {2, 3, 5, 7}, // L
    {3, 5, 7, 6}, // J
    {2, 3, 4, 5}  // O
};

Block::Block(int shapeIndex) {
    if (shapeIndex < 0 || shapeIndex >= 7) {
        shapeIndex = rand() % 7;
    }
    color = 1 + rand() % 7;

    for (int i = 0; i < 4; i++) {
        shape[i].x = shapes[shapeIndex][i] % 2 + Grid::N / 2 - 1; // Dịch khối vào giữa
        shape[i].y = shapes[shapeIndex][i] / 2;
    }
}

void Block::move(int dx, int dy) {
    for (auto& p : shape) {
        p.x += dx;
        p.y += dy;
    }
}

void Block::rotate() {
    Point center = shape[1];
    for (auto& p : shape) {
        int x = p.y - center.y;
        int y = p.x - center.x;
        p.x = center.x - x;
        p.y = center.y + y;
    }
}

const std::array<Point, 4>& Block::getShape() const {
    return shape;
}

int Block::getColor() const {
    return color;
}
