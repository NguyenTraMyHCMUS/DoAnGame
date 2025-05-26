#include "TetrominoRenderer.h"

TetrominoRenderer::TetrominoRenderer(const Point (&blocks)[4], int cellSize) : _blocks(blocks) {
    _cellSize = cellSize;
}

TetrominoRenderer::TetrominoRenderer(const Point (&blocks)[4]) : _blocks(blocks) { 
    _cellSize = 18;
}

void TetrominoRenderer::draw(RenderWindow& window, Sprite& sprite, int color) const {
    for (int i = 0; i < 4; ++i){
        sprite.setTextureRect(IntRect(color * _cellSize, 0, _cellSize, _cellSize)); 
        sprite.setPosition(_blocks[i].getX() * _cellSize, _blocks[i].getY() * _cellSize); 
        sprite.move(28, 31); 
        window.draw(sprite);
    }
}

void TetrominoRenderer::setCellSize(int size){
    _cellSize = size;
}

int TetrominoRenderer::getCellSize() const {
    return _cellSize;
}

