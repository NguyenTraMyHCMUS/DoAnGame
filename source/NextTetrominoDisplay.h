#ifndef NEXTTETROMINODISPLAY_H
#define NEXTTETROMINODISPLAY_H

#include <SFML/Graphics.hpp>
#include "Tetromino.h"

class NextTetrominoDisplay {
private:
    sf::Vector2f position; // Vị trí hiển thị khối tiếp theo
    int cellSize;          // Kích thước mỗi ô vuông

public:
    NextTetrominoDisplay(sf::Vector2f pos , int size );

    void draw(sf::RenderWindow &window, const Tetromino &nextTetromino);
};

#endif