#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include "Block.h"

class JBlock : public Block{
    public:
        JBlock();
        void Draw(int offsetX, int offsetY, sf::RenderWindow& window, sf::Sprite& sprite) override;
};

#endif
