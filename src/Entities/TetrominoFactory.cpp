#include "TetrominoFactory.h"
#include "RotatorFactory.h"

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
    std::unique_ptr<Tetromino> tetromino;
    std::string rotatorType;

    // Tạo đúng loại tetromino dựa vào type
    switch (type) {
        case 0: 
            tetromino = std::make_unique<ITetromino>();
            rotatorType = "I";
            break;
        case 1: 
            tetromino = std::make_unique<JTetromino>();
            rotatorType = "J";
            break;
        case 2: 
            tetromino = std::make_unique<LTetromino>();
            rotatorType = "L";
            break;
        case 3: 
            tetromino = std::make_unique<OTetromino>();
            rotatorType = "O";
            break;
        case 4: 
            tetromino = std::make_unique<STetromino>();
            rotatorType = "S";
            break;
        case 5: 
            tetromino = std::make_unique<TTetromino>();
            rotatorType = "T";
            break;
        case 6: 
            tetromino = std::make_unique<ZTetromino>();
            rotatorType = "Z";
            break;
        default: 
            return nullptr;
    }
    
    // Gán rotator phù hợp
    if (rotatorType != "O") {  // Khối O không cần rotator
        tetromino->setRotator(RotatorFactory::createRotator(rotatorType));
    }
    
    return tetromino;
}
