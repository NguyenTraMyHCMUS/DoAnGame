#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

#include <memory>
//#include "Block.h"
#include "OBlock.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "TBlock.h"
#include "SBlock.h"
#include "ZBlock.h"

std::unique_ptr<Block> CreateRandomBlock();

#endif
