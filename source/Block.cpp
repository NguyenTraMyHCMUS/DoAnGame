#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

struct Point {
    int x, y;
};

class Block {
protected:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;

public:
    int id;
    std::map<int, std::vector<Point>> cells;

    Block() : cellSize(18), rotationState(0), rowOffset(0), columnOffset(0) {}

    virtual void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) = 0;

    void Move(int rows, int cols) {
        rowOffset += rows;
        columnOffset += cols;
    }

    std::vector<Point> GetCellPositions() {
        std::vector<Point> positions;
        for (auto& cell : cells) {
            for (auto& p : cell.second) {
                positions.push_back({ p.x + columnOffset, p.y + rowOffset });
            }
        }
        return positions;
    }

    void Rotate() {
        for (auto& cell : cells) {
            for (auto& p : cell.second) {
                int x = p.y;
                int y = -p.x;
                p.x = x;
                p.y = y;
            }
        }
    }

    void UndoRotation() {
        for (auto& cell : cells) {
            for (auto& p : cell.second) {
                int x = p.y;
                int y = -p.x;
                p.x = x;
                p.y = y;
            }
        }
    }
};

class IBlock : public Block {
public:
    IBlock() {
        id = 1;
        cells[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};  // Hình I
        cells[1] = {{1, -1}, {1, 0}, {1, 1}, {1, 2}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class JBlock : public Block {
public:
    JBlock() {
        id = 2;
        cells[0] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};  // Hình J
        cells[1] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class LBlock : public Block {
public:
    LBlock() {
        id = 3;
        cells[0] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}};  // Hình L
        cells[1] = {{1, -1}, {1, 0}, {1, 1}, {2, -1}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class OBlock : public Block {
public:
    OBlock() {
        id = 4;
        cells[0] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};  // Hình O (khối vuông)
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[0]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class SBlock : public Block {
public:
    SBlock() {
        id = 5;
        cells[0] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};  // Hình S
        cells[1] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class TBlock : public Block {
public:
    TBlock() {
        id = 6;
        cells[0] = {{0, 0}, {1, 0}, {2, 0}, {1, 1}};  // Hình T
        cells[1] = {{1, -1}, {1, 0}, {1, 1}, {0, 0}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};

class ZBlock : public Block {
public:
    ZBlock() {
        id = 7;
        cells[0] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};  // Hình Z
        cells[1] = {{1, -1}, {0, 0}, {1, 0}, {0, 1}};  // Xoay 90 độ
    }

    void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Color color) override {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        for (auto& p : cells[rotationState]) {
            blockShape.setPosition((p.x + columnOffset + offsetX) * cellSize, (p.y + rowOffset + offsetY) * cellSize);
            blockShape.setFillColor(color);  // Đặt màu cho ô
            window.draw(blockShape);  // Vẽ ô lên cửa sổ
        }
    }
};
