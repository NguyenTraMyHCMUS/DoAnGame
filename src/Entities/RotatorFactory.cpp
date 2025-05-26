#include "RotatorFactory.h"

ITetrominoRotator* RotatorFactory::createRotator(const std::string& type) {
    if (type == "I") {
        return new IRotator();
    } 
    else if (type == "J" || type == "L") {
        return new CounterclockwiseRotator();
    }
    else if (type == "S" || type == "Z" || type == "T") {
        return new StandardRotator();
    }
    else if (type == "O") {
        return nullptr; // Khối O không xoay
    }
    return nullptr;
}
