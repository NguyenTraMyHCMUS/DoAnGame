#include "BlockFactory.h"
#include <cstdlib>

std::unique_ptr<Block> CreateRandomBlock() {
    int blockType = rand() % 7; // Chọn ngẫu nhiên từ 0 đến 6
    switch (blockType) {
        case 0: return std::make_unique<OBlock>();
        case 1: return std::make_unique<IBlock>();
        case 2: return std::make_unique<JBlock>();
        case 3: return std::make_unique<LBlock>();
        case 4: return std::make_unique<TBlock>();
        case 5: return std::make_unique<SBlock>();
        case 6: return std::make_unique<ZBlock>();
        default: return nullptr;
    }
}
