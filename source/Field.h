#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
using namespace sf;
const int M = 20;
const int N = 10;

class Field {
private:
    int grid[M][N];

public:
    Field();

    bool isInside(int x, int y) const;
    bool isOccupied(int x, int y) const;
    void setCell(int x, int y, int color);
    int getCell(int x, int y) const;
    int clearLines();
    void draw(sf::RenderWindow& window, sf::Sprite& sprite);
    void clear(); 
    bool canPlaceBlock(const std::vector<std::pair<int, int>>& blockPositions) const;
    
};

#endif
