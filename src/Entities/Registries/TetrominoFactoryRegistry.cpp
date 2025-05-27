#include "TetrominoFactoryRegistry.h"

// Singleton instance
TetrominoFactoryRegistry& TetrominoFactoryRegistry::getInstance() {
    static TetrominoFactoryRegistry instance;
    return instance;
}

// Xóa copy constructor và assignment operator để đảm bảo singleton
void TetrominoFactoryRegistry::registerFactory(int id, const std::string& name, std::function<std::unique_ptr<Tetromino>()> factory) {
    _factories[id] = factory;
    _nameToId[name] = id;
}

// Hàm tạo Tetromino theo ID
std::unique_ptr<Tetromino> TetrominoFactoryRegistry::createTetromino(int id) {
    auto it = _factories.find(id);
    return (it != _factories.end()) ? it->second() : nullptr;
}

// Hàm tạo Tetromino theo tên
std::unique_ptr<Tetromino> TetrominoFactoryRegistry::createTetromino(const std::string& name) {
    auto nameIt = _nameToId.find(name);
    if (nameIt != _nameToId.end()) {
        return createTetromino(nameIt->second);
    }
    return nullptr;
}

// Hàm lấy danh sách các ID có sẵn
std::vector<int> TetrominoFactoryRegistry::getAvailableIds() const {
    std::vector<int> ids;
    ids.reserve(_factories.size());
    for (const auto& pair : _factories) {
        ids.push_back(pair.first);
    }
    std::sort(ids.begin(), ids.end());
    return ids;
}

// Hàm lấy danh sách tên có sẵn
std::vector<std::string> TetrominoFactoryRegistry::getAvailableNames() const {
    std::vector<std::string> names;
    names.reserve(_nameToId.size());
    for (const auto& pair : _nameToId) {
        names.push_back(pair.first);
    }
    std::sort(names.begin(), names.end());
    return names;
}

// Hàm lấy số lượng factory đã đăng ký
size_t TetrominoFactoryRegistry::getFactoryCount() const {
    return _factories.size();
}

// Hàm kiểm tra xem ID có tồn tại trong registry không
bool TetrominoFactoryRegistry::hasId(int id) const {
    return _factories.find(id) != _factories.end();
}

// Hàm kiểm tra xem tên có tồn tại trong registry không
bool TetrominoFactoryRegistry::hasName(const std::string& name) const {
    return _nameToId.find(name) != _nameToId.end();
}
