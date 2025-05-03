#include "PlayingState.h"
#include "PausedState.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor
PlayingState::PlayingState(Game& game) : _game(game) {
    sf::Texture tempT1, tempT2, tempT3;

    // Tải texture từ file
    if (!tempT1.loadFromFile("assets/images/tiles.png")) {
        std::cout << "Failed to load tiles.png!" << std::endl;
    }
    if (!tempT2.loadFromFile("assets/images/background.png")) {
        std::cout << "Failed to load background.png!" << std::endl;
    }
    if (!tempT3.loadFromFile("assets/images/frame.png")) {
        std::cout << "Failed to load frame.png!" << std::endl;
    }

    // Tải phông chữ
    if (!_font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cout << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        game.getWindow().close();
        return;
    }

    // Sử dụng setter để lưu texture vào Game
    game.setT1(tempT1);
    game.setT2(tempT2);
    game.setT3(tempT3);

    // Thiết lập sprite
    sf::Sprite tempS, tempBackground, tempFrame;
    tempS.setTexture(game.getT1());
    tempBackground.setTexture(game.getT2());
    tempFrame.setTexture(game.getT3());

    game.setSprite(tempS);
    game.setBackground(tempBackground);
    game.setFrame(tempFrame);

}

// Xử lý đầu vào 
void PlayingState::handleInput(Game& game) {
    sf::Event event;
    // Xử lý sự kiện từ cửa sổ
    while (game.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();
        }

        // Xử lý các phím bấm
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                game.setState(std::make_unique<PausedState>(game)); // Chuyển sang trạng thái tạm dừng
            } 
            else if (event.key.code == sf::Keyboard::Left) {
                game.setDx(-1); // Di chuyển sang trái
            } 
            else if (event.key.code == sf::Keyboard::Right) {
                game.setDx(1); // Di chuyển sang phải
            } 
            else if (event.key.code == sf::Keyboard::Up) {
                game.setRotate(true); // Xoay Tetromino
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) game.setDelay(0.05);
    }
}

// Vẽ hộp thông tin chứa điểm số, level, khối tiếp theo
void PlayingState::drawInfoBox(sf::RenderWindow& window, sf::Vector2f position, const std::string& title, const std::string& value) {
    const float boxWidth = 125.0f;
    const float boxHeight = 60.0f;

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

// Vẽ toàn cảnh trạng thái playing
void PlayingState::draw(Game& game) {
    // Xóa cửa sổ với màu trắng
    game.getWindow().clear(sf::Color::White);

    // Vẽ nền
    game.getWindow().draw(game.getBackground());

    // Vẽ lưới và Tetromino
    game.getField().draw(game.getWindow(), game.getSprite());
    game.getTetromino()->draw(game.getWindow(), game.getSprite());
    game.getNextTetrominoPreview().draw(game.getWindow(), game.getSprite());
  
    // Vẽ khung
    game.getWindow().draw(game.getFrame());

    // Hiển thị thông tin cấp độ, điểm số, và điểm cao
    sf::Vector2f infoStartPos(240, 180); // Ngay dưới khung "Next"
    drawInfoBox(game.getWindow(), infoStartPos, "Level", std::to_string(game.getLevelManager().getLevel()));
    drawInfoBox(game.getWindow(), sf::Vector2f(infoStartPos.x, infoStartPos.y + 70), "Score", std::to_string(game.getScoreManager().getScore()));
    drawInfoBox(game.getWindow(), sf::Vector2f(infoStartPos.x, infoStartPos.y + 140), "HighScore", std::to_string(game.getScoreManager().getHighScore()));

    // Hiển thị cửa sổ
    game.getWindow().display();
}
