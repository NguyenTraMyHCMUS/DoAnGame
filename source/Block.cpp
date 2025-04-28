#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Point.h"

class Block {
protected:
    int cellSize; // kích thước của mỗi ô trong khối
    int rotationState; // vị trí hiện tại của khối (0-3 cho 4 trạng thái xoay)
    int color; // màu sắc của khối
    int rowOffset; // vị trí hàng hiện tại của khối
    int columnOffset; // vị trí cột hiện tại của khối

public:
    int id;
    std::map<int, std::vector<Point>> cells;

    Block();
    //virtual ~Block() = default; 
    virtual void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) = 0;

    void Move(int rows, int cols);
    std::vector<Point> GetCellPositions();
    void Rotate();
    void UndoRotation();
};

#endif 
