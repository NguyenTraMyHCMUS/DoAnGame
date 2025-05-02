#include "NextTetrominoPreview.h"

NextTetrominoPreview::NextTetrominoPreview() {
    _cellSize = 18;
    _position = sf::Vector2f(240, 50); // vị trí để vẽ khối tiếp theo
    generateNext();
}

void NextTetrominoPreview::generateNext() {
    _next = TetrominoFactory::createRandomTetromino();
    _next->setCellSize(_cellSize);
}

std::unique_ptr<Tetromino> NextTetrominoPreview::getNext() {
    return std::move(_next); // chuyển giao quyền sở hữu
}
std::unique_ptr<Tetromino> NextTetrominoPreview::cloneNext() const {
    return _next->clone();
}
void NextTetrominoPreview::draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    const float frameSize = 120.0f;
    const float titleHeight = 24.0f;

    // Khung chứa chữ "Next" và khối tiếp theo
    sf::RectangleShape frame(sf::Vector2f(frameSize, frameSize));
    frame.setFillColor(sf::Color::Black);
    frame.setOutlineColor(sf::Color::White);
    frame.setOutlineThickness(2);
    frame.setPosition(_position);
    window.draw(frame);

    // Font và chữ "Next"
    sf::Font font;
    if (font.loadFromFile("assets/fonts/arial.ttf")) {
        sf::Text nextText("Next", font, 20);
        nextText.setFillColor(sf::Color::White);
        nextText.setPosition(_position.x + 8, _position.y + 5); // Bên trái khung, cách lề 8px
        window.draw(nextText);
    }


    // Tính toán vị trí khối tetromino để nó luôn ở bên trái khung
    int minX = _next->getBlocks()[0]._x, maxX = _next->getBlocks()[0]._x;
    int minY = _next->getBlocks()[0]._y, maxY = _next->getBlocks()[0]._y;
    for (int i = 1; i < 4; i++) {
        int x = _next->getBlocks()[i]._x;
        int y = _next->getBlocks()[i]._y;
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }
    float tetrominoWidth = (maxX - minX + 1) * _cellSize;
    float tetrominoHeight = (maxY - minY + 1) * _cellSize;
    float offsetX = _position.x + 8 - minX * _cellSize; // Đặt sát lề trái khung (8px)
    float offsetY = _position.y + (frameSize - tetrominoHeight) / 2 - minY * _cellSize + 10; // +10 tránh đè chữ

    for (int i = 0; i < 4; i++) {
        int x = _next->getBlocks()[i]._x;
        int y = _next->getBlocks()[i]._y;
        sprite.setTextureRect(sf::IntRect(_next->getColor() * _cellSize, 0, _cellSize, _cellSize));
        sprite.setPosition(offsetX + x * _cellSize, offsetY + y * _cellSize);
        window.draw(sprite);
    }
}
