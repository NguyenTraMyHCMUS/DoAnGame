// DefaultTetrominoComponentFactory.cpp - ✅ Fixed implementation
#include "DefaultTetrominoComponentFactory.h"
#include "../Components/TetrominoValidator.h"
#include "../Components/TetrominoState.h"
#include "../Components/TetrominoRenderer.h"
#include "../Components/TetrominoMovement.h"
#include "../Components/TetrominoLocker.h"
#include "RotatorFactory.h"

// const blocks - read-only components
std::unique_ptr<ITetrominoValidator> DefaultTetrominoComponentFactory::createValidator(const Point (&blocks)[4]) {
    return std::make_unique<TetrominoValidator>(blocks);
}

std::unique_ptr<ITetrominoRenderer> DefaultTetrominoComponentFactory::createRenderer(const Point (&blocks)[4], int cellSize) {
    return std::make_unique<TetrominoRenderer>(blocks, cellSize);
}

std::unique_ptr<ITetrominoLocker> DefaultTetrominoComponentFactory::createLocker(const Point (&blocks)[4]) {
    return std::make_unique<TetrominoLocker>(blocks);
}

// non-const blocks - modifying components
std::unique_ptr<ITetrominoState> DefaultTetrominoComponentFactory::createState(Point (&blocks)[4]) {
    return std::make_unique<TetrominoState>(blocks);
}

std::unique_ptr<ITetrominoMovement> DefaultTetrominoComponentFactory::createMovement(Point (&blocks)[4]) {
    return std::make_unique<TetrominoMovement>(blocks);
}

std::unique_ptr<ITetrominoRotator> DefaultTetrominoComponentFactory::createRotator(const std::string& type) {
    return RotatorFactory::createRotator(type);
}