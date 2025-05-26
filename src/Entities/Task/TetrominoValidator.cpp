#include "TetrominoValidator.h"

bool TetrominoValidator::isValid(const Field& field) const {
    for (int i = 0; i < 4; i++) {
        if (!field.isInside(_blocks[i].getX(), _blocks[i].getY()) 
        || field.isOccupied(_blocks[i].getX(), _blocks[i].getY())) {
            return false;
        }
    }
    return true;
}
