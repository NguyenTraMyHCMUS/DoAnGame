#include "Grid.h"

using namespace sf;

Grid::Grid() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;
}

bool Grid::check(const std::array<Point, 4>& shape) const {
    for (const auto& p : shape) {
        if (p.x < 0 || p.x >= N || p.y >= M || (p.y >= 0 && grid[p.y][p.x] != 0)) {
            return false;
        }
    }
    return true;
}

void Grid::placeBlock(const std::array<Point, 4>& shape, int color) {
    for (const auto& p : shape) {
        if (p.y >= 0) {
            grid[p.y][p.x] = color;
        }
    }
}

int Grid::clearFullLines() {
    int linesCleared = 0;
    for (int i = M - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != 0) count++;
        }
        if (count == N) { // nếu hàng đầy
            linesCleared++;
            // Di chuyển các hàng phía trên xuống
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < N; j++) {
                    grid[k][j] = grid[k - 1][j];
                }
            }
            // Xóa hàng trên cùng
            for (int j = 0; j < N; j++) {
                grid[0][j] = 0;
            }
            i++; // kiểm tra lại hàng sau khi dịch xuống
        }
    }
    return linesCleared;
}

void Grid::draw(RenderWindow& window, Sprite& sprite) const {
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

bool Grid::isTopReached() const {
    for (int j = 0; j < N; j++) {
        if (grid[0][j] != 0) {
            return true;
        }
    }
    return false;
}
