#include "TetrominoRenderer.h"
#include "GameFieldRenderingStrategy.h"

// Hàm khởi tạo của lớp TetrominoRenderer
TetrominoRenderer::TetrominoRenderer(const Point (&blocks)[4], int cellSize, std::unique_ptr<IRenderingStrategy> strategy) : _blocks(blocks) {
    _cellSize = cellSize;
    if (!strategy) {
            _strategy = std::make_unique<GameFieldRenderingStrategy>();
    } else {
        _strategy = std::move(strategy);
    }
}

// Hàm khởi tạo mặc định của lớp TetrominoRenderer
TetrominoRenderer::TetrominoRenderer(const Point (&blocks)[4]) : _blocks(blocks) { 
    _cellSize = 18;
    _strategy = std::make_unique<GameFieldRenderingStrategy>();
}

// Hàm vẽ khối Tetromino lên cửa sổ
void TetrominoRenderer::draw(RenderWindow& window, Sprite& sprite, int color) const {
    for (int i = 0; i < 4; ++i) {
        // Sử dụng Strategy Pattern để vẽ từng ô của khối Tetris
        _strategy->render(window, sprite, _blocks[i], _cellSize, color);
    }
}

// Hàm đặt kích thước cho mỗi ô
void TetrominoRenderer::setCellSize(int size){
    _cellSize = size;
}

// Hàm lấy kích thước của mỗi ô
int TetrominoRenderer::getCellSize() const {
    return _cellSize;
}

// Hàm thiết lập chiến lược vẽ cho TetrominoRenderer
void TetrominoRenderer::setRenderingStrategy(std::unique_ptr<IRenderingStrategy> strategy) {
    if (strategy) {  
        _strategy = std::move(strategy);
    }
}
