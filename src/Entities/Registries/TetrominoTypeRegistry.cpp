#include "TetrominoTypeRegistry.h"
#include "../TetrominoConstants.h"
#include <algorithm>

std::map<int, TetrominoTypeInfo> TetrominoTypeRegistry::_typeInfo;
std::map<std::string, int> TetrominoTypeRegistry::_nameToId;
bool TetrominoTypeRegistry::_initialized = false;

void TetrominoTypeRegistry::initialize() {
    if (_initialized) return;
    
    // Register all Tetromino types
    registerType({0, "I", "Long straight piece", TetrominoConstants::I_COLOR, true, "I"});
    registerType({1, "J", "Blue ricky piece", TetrominoConstants::J_COLOR, true, "J"});
    registerType({2, "L", "Orange ricky piece", TetrominoConstants::L_COLOR, true, "L"});
    registerType({3, "O", "Square piece", TetrominoConstants::O_COLOR, false, "O"});
    registerType({4, "S", "Green zigzag piece", TetrominoConstants::S_COLOR, true, "S"});
    registerType({5, "T", "Purple T piece", TetrominoConstants::T_COLOR, true, "T"});
    registerType({6, "Z", "Red zigzag piece", TetrominoConstants::Z_COLOR, true, "Z"});
    
    _initialized = true;
}

void TetrominoTypeRegistry::registerType(const TetrominoTypeInfo& info) {
    _typeInfo[info.id] = info;
    _nameToId[info.name] = info.id;
}

const TetrominoTypeInfo* TetrominoTypeRegistry::getTypeInfo(int id) {
    initialize();
    auto it = _typeInfo.find(id);
    return (it != _typeInfo.end()) ? &it->second : nullptr;
}

const TetrominoTypeInfo* TetrominoTypeRegistry::getTypeInfo(const std::string& name) {
    initialize();
    auto nameIt = _nameToId.find(name);
    if (nameIt != _nameToId.end()) {
        return getTypeInfo(nameIt->second);
    }
    return nullptr;
}

bool TetrominoTypeRegistry::isValidType(int id) {
    initialize();
    return _typeInfo.find(id) != _typeInfo.end();
}

bool TetrominoTypeRegistry::isValidType(const std::string& name) {
    initialize();
    return _nameToId.find(name) != _nameToId.end();
}

std::vector<TetrominoTypeInfo> TetrominoTypeRegistry::getAllTypes() {
    initialize();
    std::vector<TetrominoTypeInfo> result;
    for (const auto& pair : _typeInfo) {
        result.push_back(pair.second);
    }
    return result;
}