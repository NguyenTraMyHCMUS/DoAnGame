#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include "Block.h"

class SBlock : public Block{
    public:
        SBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
