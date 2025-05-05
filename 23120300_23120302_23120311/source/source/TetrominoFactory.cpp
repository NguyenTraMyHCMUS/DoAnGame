#include "TetrominoFactory.h"

std::unique_ptr<Tetromino> TetrominoFactory::createRandomTetromino() {
    int type = rand() % 7; // Chọn ngẫu nhiên một loại khối
    auto tetromino = createTetromino(type);

    if (tetromino) {
        tetromino->setColor(type + 1); // +1 để tránh màu trắng ở index 0
        tetromino->initializeShape();  // Khởi tạo hình dạng khối
    }
    
    return tetromino;
}

std::unique_ptr<Tetromino> TetrominoFactory::createTetromino(int type) {
    switch (type) {
        case 0: return std::make_unique<ITetromino>();
        case 1: return std::make_unique<JTetromino>();
        case 2: return std::make_unique<LTetromino>();
        case 3: return std::make_unique<OTetromino>();
        case 4: return std::make_unique<STetromino>();
        case 5: return std::make_unique<TTetromino>();
        case 6: return std::make_unique<ZTetromino>();
        default: return nullptr;
    }
}
