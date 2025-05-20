#include "GameRenderer.h"
#include <string>

GameRenderer::GameRenderer(sf::RenderWindow& window, ResourceManager& resources)
    : window(window), resources(resources) {
}

void GameRenderer::clear() {
    window.clear(sf::Color::White);
}

void GameRenderer::display() {
    window.display();
}

void GameRenderer::drawBackground() {
    window.draw(resources.getBackground());
}

void GameRenderer::drawField(const Field& field) {
    sf::Sprite& sprite = resources.getSprite();
    
    for (int i = 0; i < field.getHeight(); i++) {
        for (int j = 0; j < field.getWidth(); j++) {
            // Sử dụng phương thức getCell với tham số (x, y) đúng
            int cellValue = field.getCell(j, i);
            if (cellValue == 0) continue;
            
            sprite.setTextureRect(sf::IntRect(cellValue * 18, 0, 18, 18));
            sprite.setPosition(j * 18, i * 18);
            sprite.move(28, 31); // offset
            window.draw(sprite);
        }
    }
}

void GameRenderer::drawTetromino(const Tetromino* tetromino) {
    if (!tetromino) return;
    
    sf::Sprite& sprite = resources.getSprite();
    
    for (int i = 0; i < 4; i++) {
        // Sử dụng phương thức getColor thay vì getColorIndex
        sprite.setTextureRect(sf::IntRect(tetromino->getColor() * 18, 0, 18, 18));
        
        // Sử dụng getX và getY thay vì getPositionX và getPositionY
        int xPos = tetromino->getX(i);
        int yPos = tetromino->getY(i);
        
        sprite.setPosition(xPos * 18, yPos * 18);
        sprite.move(28, 31); // offset
        window.draw(sprite);
    }
}

void GameRenderer::drawNextPreview(const NextTetrominoPreview& preview) {
    // Sử dụng phương thức draw của NextTetrominoPreview
    // Cần cast const away để gọi phương thức draw không phải const
    NextTetrominoPreview& previewNonConst = const_cast<NextTetrominoPreview&>(preview);
    previewNonConst.draw(window, resources.getSprite());
}
void GameRenderer::drawInfoBox(const std::string& title, const std::string& value, float yPos) {
    const float boxWidth = 125.0f;
    const float boxHeight = 60.0f;
    sf::Vector2f position(240, yPos);

    sf::RectangleShape box(sf::Vector2f(boxWidth, boxHeight));
    box.setPosition(position);
    box.setFillColor(sf::Color(0, 0, 0));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2.0f);
    window.draw(box);

    sf::Font font;
    if (font.loadFromFile("assets/fonts/arial.ttf")) {
        // Căn trái tiêu đề
        sf::Text titleText(title, font, 16);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(position.x + 4, position.y + 4);
        window.draw(titleText);

        // Căn trái giá trị
        sf::Text valueText(value, font, 18);
        valueText.setFillColor(sf::Color::Yellow);
        valueText.setPosition(position.x + 8, position.y + boxHeight / 2);
        window.draw(valueText);
    }
}

void GameRenderer::drawStats(const ScoreManager& scoreManager, const LevelManager& levelManager) {
    // Hiển thị cấp độ
    drawInfoBox("Level: ", std::to_string(levelManager.getLevel()), 180);
    
    // Hiển thị điểm số
    drawInfoBox("Score: ", std::to_string(scoreManager.getScore()), 250);
    
    // Hiển thị điểm cao
    drawInfoBox("HighScore: ", std::to_string(scoreManager.getHighScore()), 320);
}

void GameRenderer::drawFrame() {
    window.draw(resources.getFrame());
}