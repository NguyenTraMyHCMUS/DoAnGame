#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_

#include "Block.h"

class ZBlock : public Block{
    public:
        ZBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
