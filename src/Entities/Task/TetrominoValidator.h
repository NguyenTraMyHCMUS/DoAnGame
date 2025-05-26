#ifndef TETROMINO_VALIDATOR_H
#define TETROMINO_VALIDATOR_H

#include "../Interface/ITetrominoValidator.h"

class TetrominoValidator : public ITetrominoValidator {
    private:
        const Point (&_blocks)[4];

    public:
        TetrominoValidator(const Point (&blocks)[4]) : _blocks(blocks) {}
        
        bool isValid(const Field& field) const override;
};

#endif
