#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "Block.h"

class IBlock : public Block{
    public:
        IBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
