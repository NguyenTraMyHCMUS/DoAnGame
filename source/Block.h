#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <array>

struct Point {
    int x, y;
};

class Block {
public:
    Block(int shapeIndex);
    void rotate();
    void move(int dx, int dy);
    const std::array<Point, 4>& getShape() const;
    int getColor() const;
    bool check();

private:
    std::array<Point, 4> shape;
    int color;
    static const int shapes[7][4]; // Định nghĩa hình dạng các khối Tetris
};

#endif
