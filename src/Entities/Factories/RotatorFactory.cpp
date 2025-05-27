#include "RotatorFactory.h"

// Hàm tạo rotator cho một loại khối Tetromino
std::unique_ptr<ITetrominoRotator> RotatorFactory::createRotator(const std::string& type) {
    auto& registry = RotatorFactoryRegistry::getInstance();
    return registry.createRotator(type);
}