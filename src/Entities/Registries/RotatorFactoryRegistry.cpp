#include "RotatorFactoryRegistry.h"

// Hàm khởi tạo singleton
RotatorFactoryRegistry& RotatorFactoryRegistry::getInstance() {
    static RotatorFactoryRegistry instance;
    return instance;
}

// Hàm đăng ký rotator
void RotatorFactoryRegistry::registerRotator(const std::string& type, std::function<std::unique_ptr<ITetrominoRotator>()> factory) {
    _factories[type] = factory;
}

// Hàm tạo rotator theo loại
std::unique_ptr<ITetrominoRotator> RotatorFactoryRegistry::createRotator(const std::string& type) {
    auto it = _factories.find(type);
    return (it != _factories.end()) ? it->second() : nullptr;
}