#ifndef TETROMINO_RENDERER_H
#define TETROMINO_RENDERER_H

#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Interface/ITetrominoRenderer.h"

using namespace sf;

class TetrominoRenderer : public ITetrominoRenderer {
    private:
        const Point (&_blocks)[4];
        int _cellSize;
    public:
        TetrominoRenderer(const Point (&blocks)[4], int cellSize);
        TetrominoRenderer(const Point (&blocks)[4]);

        void setCellSize(int size);
        int getCellSize() const;

        void draw(RenderWindow& window, Sprite& sprite, int color) const;
};

#endif
