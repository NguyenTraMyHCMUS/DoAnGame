#include "NextTetrominoDisplay.h"

NextTetrominoDisplay::NextTetrominoDisplay(sf::Vector2f pos, int size)
    : position(pos), cellSize(size) {
    // Đặt vị trí hợp lý để không bị che
    position = sf::Vector2f(240, 50); // Góc trên bên phải, điều chỉnh theo kích thước cửa sổ
}

// void NextTetrominoDisplay::draw(sf::RenderWindow &window, const Tetromino &nextTetromino) {
//     // Mảng màu sắc
//     sf::Color colors[] = {
//         sf::Color::White, sf::Color::Cyan, sf::Color::Blue,
//         sf::Color(255, 165, 0), sf::Color::Yellow,
//         sf::Color::Green, sf::Color::Red, sf::Color::Magenta
//     };

//     // Khung chứa khối tiếp theo
//     const float frameSize = 120.0f;
//     sf::RectangleShape frame(sf::Vector2f(frameSize, frameSize));
//     frame.setFillColor(sf::Color(40, 60, 150)); // Xanh đậm
//     frame.setOutlineColor(sf::Color(100, 100, 200));
//     frame.setOutlineThickness(2);
//     frame.setPosition(position.x, position.y + 40); // Bên phải và dưới tiêu đề
//     window.draw(frame);

//     // Hiển thị tiêu đề "Next"
//     sf::Font font;
//     if (font.loadFromFile("assets/fonts/arial.ttf")) {
//         sf::Text nextText("Next", font, 24);
//         nextText.setFillColor(sf::Color::White);
//         nextText.setPosition(position.x + 25, position.y + 35); // Canh giữa trên khung
//         window.draw(nextText);
//     }

//     // Căn giữa khối Tetromino trong khung
//     auto blocks = nextTetromino.getBlocks();
//     int minX = blocks[0]._x, maxX = blocks[0]._x;
//     int minY = blocks[0]._y, maxY = blocks[0]._y;
//     for (const auto& block : blocks) {
//         minX = std::min(minX, block._x);
//         maxX = std::max(maxX, block._x);
//         minY = std::min(minY, block._y);
//         maxY = std::max(maxY, block._y);
//     }

//     float offsetX = (frameSize - (maxX - minX + 1) * cellSize) / 2;
//     float offsetY = (frameSize - (maxY - minY + 1) * cellSize) / 2;

//     // Vẽ từng ô của Tetromino
//     for (const auto &block : blocks) {
//         sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
//         blockShape.setFillColor(colors[nextTetromino.getColor()]);
//         blockShape.setOutlineColor(sf::Color::Black);
//         blockShape.setOutlineThickness(1);
//         blockShape.setPosition(
//             position.x + offsetX + (block._x - minX) * cellSize,
//             position.y + 40 + offsetY + (block._y - minY) * cellSize
//         );
//         window.draw(blockShape);
//     }
// }

void NextTetrominoDisplay::draw(sf::RenderWindow &window, const Tetromino &nextTetromino) {
    // Mảng màu sắc
    sf::Color colors[] = {
        sf::Color::White, sf::Color::Cyan, sf::Color::Blue,
        sf::Color(255, 165, 0), sf::Color::Yellow,
        sf::Color::Green, sf::Color::Red, sf::Color::Magenta
    };

    const float frameSize = 120.0f;
    const float titleHeight = 24.0f;

    // Khung xanh đậm chứa chữ và khối tiếp theo
    sf::RectangleShape frame(sf::Vector2f(frameSize, frameSize)); // Kích thước khung
    frame.setFillColor(sf::Color(40, 60, 150)); // Màu nền khung
    frame.setOutlineColor(sf::Color::White); // Màu viền khung
    frame.setOutlineThickness(2); // Độ dày viền khung
    frame.setPosition(position); // Vị trí khung
    window.draw(frame); // Vẽ khung

    // Tải font và vẽ chữ "Next" bên trong khung
    sf::Font font;
    if (font.loadFromFile("assets/fonts/arial.ttf")) {
        sf::Text nextText("Next", font, 20);
        nextText.setFillColor(sf::Color::White);

        // Căn giữa chữ "Next" theo chiều ngang trong khung
        sf::FloatRect textBounds = nextText.getLocalBounds();
        nextText.setPosition(
            position.x + (frameSize - textBounds.width) / 2 - textBounds.left,
            position.y + 5 // cách trên một chút
        );
        window.draw(nextText);
    }

    // Lấy block Tetromino để vẽ
    auto blocks = nextTetromino.getBlocks();
    int minX = blocks[0]._x, maxX = blocks[0]._x;
    int minY = blocks[0]._y, maxY = blocks[0]._y;
    for (const auto& block : blocks) {
        minX = std::min(minX, block._x);
        maxX = std::max(maxX, block._x);
        minY = std::min(minY, block._y);
        maxY = std::max(maxY, block._y);
    }

    // Căn giữa khối Tetromino bên trong khung (bên dưới dòng chữ)
    float availableHeight = frameSize - titleHeight - 10; // trừ đi chiều cao chữ
    float offsetX = (frameSize - (maxX - minX + 1) * cellSize) / 2;
    float offsetY = titleHeight + (availableHeight - (maxY - minY + 1) * cellSize) / 2;

    for (const auto &block : blocks) {
        sf::RectangleShape blockShape(sf::Vector2f(cellSize, cellSize));
        blockShape.setFillColor(colors[nextTetromino.getColor()]);
        blockShape.setOutlineColor(sf::Color::Black);
        blockShape.setOutlineThickness(1);
        blockShape.setPosition(
            position.x + offsetX + (block._x - minX) * cellSize,
            position.y + offsetY + (block._y - minY) * cellSize
        );
        window.draw(blockShape);
    }
}
