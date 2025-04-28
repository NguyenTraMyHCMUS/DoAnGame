#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <array>

struct Point {
    int x, y;
};

const int M = 20;
const int N = 10;

class Grid {
private:
    int grid[M][N]; // giữ đúng như Grid

public:
    Field();

    bool check(const std::array<Point, 4>& shape) const;
    void placeBlock(const std::array<Point, 4>& shape, int color);
    int clearFullLines();
    void draw(sf::RenderWindow& window, sf::Sprite& sprite) const;
    bool isTopReached() const;
};

#endif
