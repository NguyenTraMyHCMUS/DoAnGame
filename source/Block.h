#ifndef BLOCK_H
#define BLOCK_H

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

    Block();
    virtual void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) = 0;

    void Move(int rows, int cols);
    std::vector<Point> GetCellPositions();
    void Rotate();
    void UndoRotation();
};

#endif // BLOCK_H
