#ifndef NEXTTETROMINOPREVIEW_H
#define NEXTTETROMINOPREVIEW_H

#include "TetrominoFactory.h"
#include <memory>

class NextTetrominoPreview {
private:
    std::unique_ptr<Tetromino> _next;
    sf::Vector2f _position;
    int _cellSize;

public:
    NextTetrominoPreview();
    void generateNext();
    std::unique_ptr<Tetromino> getNext();
    std::unique_ptr<Tetromino> cloneNext() const;
    void draw(sf::RenderWindow& window, sf::Sprite& sprite);
};

#endif
