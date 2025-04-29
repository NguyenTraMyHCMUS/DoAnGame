#ifndef _LBLOCK_H_
#define _LBLOCK_H_

#include "Block.h"

class LBlock : public Block{
    public:
        LBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
