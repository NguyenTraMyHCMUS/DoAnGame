#include "Field.h"

using namespace sf;

Field::Field() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;
}

bool Field::isInside(int x, int y) const {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

bool Field::isOccupied(int x, int y) const {
    if (!isInside(x, y)) return true;
    return (grid[y][x] != 0);
}

void Field::setCell(int x, int y, int color) {
    if (isInside(x, y))
        grid[y][x] = color;
}

int Field::getCell(int x, int y) const {
    if (isInside(x, y))
        return grid[y][x];
    return 0;
}

int Field::clearLines() {
    int k = M - 1;
    int linesCleared = 0;
    for (int i = M - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) count++;
            grid[k][j] = grid[i][j];
        }
        if (count < N)
            k--;
        else
            linesCleared++; // Đếm số dòng đã xóa
    }
    return linesCleared;
}


void Field::draw(RenderWindow& window, Sprite& sprite) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) continue;
            sprite.setTextureRect(IntRect(grid[i][j] * 18, 0, 18, 18));
            sprite.setPosition(j * 18, i * 18);
            sprite.move(28, 31); // offset
            window.draw(sprite);
        }
    }
}

bool Field::isTopReached() const {
    for (int j = 0; j < N; j++) {
        if (grid[0][j] != 0) { // Nếu có ô nào trên dòng 0 đã bị chiếm
            return true;
        }
    }
    return false;
}

