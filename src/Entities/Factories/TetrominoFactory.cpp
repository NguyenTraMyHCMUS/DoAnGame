#include "TetrominoFactory.h"
#include "../Registries/TetrominoFactoryRegistry.h"
#include "../Registries/TetrominoTypeRegistry.h"
#include "../Registries/TetrominoTypeInfo.h"
#include <random>
#include <vector>

// Hàm tạo Tetromino theo loại (ID)
std::unique_ptr<Tetromino> TetrominoFactory::createTetromino(int type) {
    if (!isValidType(type)) {
        return nullptr;
    }

    auto& registry = TetrominoFactoryRegistry::getInstance();
    return registry.createTetromino(type);
}

// Hàm tạo Tetromino theo tên
std::unique_ptr<Tetromino> TetrominoFactory::createTetromino(const std::string& name) {
    if (!isValidName(name)) {
        return nullptr;
    }

    auto& registry = TetrominoFactoryRegistry::getInstance();
    return registry.createTetromino(name);
}

std::unique_ptr<Tetromino> TetrominoFactory::createTetrominoWithMetadata(int type) {
    auto tetromino = createTetromino(type);
    if (!tetromino) return nullptr;
    
    auto typeInfo = getTypeInfo(type);
    if (typeInfo) {
        tetromino->setColor(typeInfo->defaultColor);
        // Có thể apply thêm metadata khác
    }
    
    return tetromino;
}

std::unique_ptr<Tetromino> TetrominoFactory::createTetrominoWithMetadata(const std::string& name) {
    auto typeInfo = getTypeInfo(name);
    if (!typeInfo) return nullptr;
    
    return createTetrominoWithMetadata(typeInfo->id);
}

// Hàm tạo Tetromino ngẫu nhiên
std::unique_ptr<Tetromino> TetrominoFactory::createRandomTetromino() {
    auto allTypes = getAllTypeInfo();
    if (allTypes.empty()) return nullptr;
    
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, allTypes.size() - 1);
    
    int randomIndex = dist(gen);
    return createTetrominoWithMetadata(allTypes[randomIndex].id);
}

const TetrominoTypeInfo* TetrominoFactory::getTypeInfo(int type) {
    return TetrominoTypeRegistry::getTypeInfo(type);
}

const TetrominoTypeInfo* TetrominoFactory::getTypeInfo(const std::string& name) {
    return TetrominoTypeRegistry::getTypeInfo(name);
}

std::vector<TetrominoTypeInfo> TetrominoFactory::getAllTypeInfo() {
    return TetrominoTypeRegistry::getAllTypes();
}

bool TetrominoFactory::isValidType(int type) {
    return TetrominoTypeRegistry::isValidType(type);
}

bool TetrominoFactory::isValidName(const std::string& name) {
    return TetrominoTypeRegistry::isValidType(name);
}

size_t TetrominoFactory::getAvailableTypeCount() {
    return getAllTypeInfo().size();
}
