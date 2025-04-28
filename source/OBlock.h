#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include "Block.h"

class OBlock : public Block{
    public:
        OBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
