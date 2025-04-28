#include "Block.h"

Block::Block(){
    cellSize = 18; 
    rotationState = 0; 
    rowOffset = 0; 
    columnOffset = 0; 
} 

void Block::Move(int rows, int cols) {
    rowOffset += rows;
    columnOffset += cols;
}

std::vector<Point> Block::GetCellPositions() {
    std::vector<Point> positions;
    for (auto& p : cells[rotationState]) {
        positions.push_back({ p.x + columnOffset, p.y + rowOffset });
    }
    return positions;
}

void Block::Rotate() {
    for (auto& cell : cells) {
        for (auto& p : cell.second) {
            int x = p.y;
            int y = -p.x;
            p.x = x;
            p.y = y;
        }
    }
}

void Block::UndoRotation() {
    for (auto& cell : cells) {
        for (auto& p : cell.second) {
            int x = -p.y;
            int y = p.x;
            p.x = x;
            p.y = y;
        }
    }
}
