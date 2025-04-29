#ifndef _TBLOCK_H_
#define _TBLOCK_H_

#include "Block.h"

class TBlock : public Block{
    public:
        TBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
