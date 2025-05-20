#include "Field.h"

using namespace sf;

Field::Field() {
    clear(); // Khởi tạo lưới bằng cách xóa toàn bộ
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

void Field::clear() {
    for (int y = 0; y < M; ++y) { // Sử dụng M thay cho height
        for (int x = 0; x < N; ++x) { // Sử dụng N thay cho width
            grid[y][x] = 0; // Đặt tất cả các ô trong lưới về giá trị 0
        }
    }
}

bool Field::canPlaceBlock(const std::vector<std::pair<int, int>>& blockPositions) const {
    for (const auto& pos : blockPositions) {
        int x = pos.first;
        int y = pos.second;

        // Nếu ô nằm ngoài lưới hoặc đã bị chiếm, không thể đặt khối
        if (!isInside(x, y) || isOccupied(x, y)) {
            return false;
        }
    }
    return true; // Tất cả các ô đều hợp lệ, có thể đặt khối
}

int Field::getWidth() const {
    return N; // Trả về chiều rộng của lưới
}

int Field::getHeight() const {
    return M; // Trả về chiều cao của lưới
}
