#include "Game.h"
#include <iostream>
#include "Game.h"
#include "TetrominoFactory.h"
using namespace sf;
Game::Game() : window(VideoMode(320, 480), "Tetris") {
   t1.loadFromFile("source/images/tiles.png");
    t2.loadFromFile("source/images/background.png");
    t3.loadFromFile("source/images/frame.png");
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
    tetromino = TetrominoFactory::createRandomTetromino();
}

void Game::handleInput() {
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            window.close();
        }

        if (e.type == Event::KeyPressed) {
            if (e.key.code == Keyboard::Up) rotate = true;
            else if (e.key.code == Keyboard::Left) dx = -1;
            else if (e.key.code == Keyboard::Right) dx = 1;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
}

void Game::update() {
    if (isGameOver) return; // Nếu trò chơi đã kết thúc, không cập nhật nữa

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    tetromino->backupState();
    tetromino->move(dx);
    if (!tetromino->isValid(field)) {
        tetromino->restoreState();
    }

    if (rotate) {
        tetromino->backupState();
        tetromino->rotate();
        if (!tetromino->isValid(field)) {
            tetromino->restoreState();
        }
    }

    if (timer > delay) {
        tetromino->backupState();
        tetromino->fall();
        if (!tetromino->isValid(field)) {
            tetromino->restoreState();
            tetromino->lock(field);

            int cleared = field.clearLines(); // Xóa các dòng và trả về số dòng đã xóa
            linesCleared += cleared;

            // Tăng cấp độ sau mỗi 10 dòng xóa
            if (linesCleared >= level * 10) {
                level++;
                delay = std::max(0.1f, delay - 0.05f); // Giảm delay để tăng tốc độ, tối thiểu là 0.1
            }

            if (field.isTopReached()) { // Kiểm tra nếu đỉnh của lưới đã bị chiếm
                isGameOver = true; // Đặt trạng thái kết thúc trò chơi
                return;
            }
            tetromino = TetrominoFactory::createRandomTetromino();
        }
        timer = 0;
    }

    dx = 0;
    rotate = false;
    delay = 0.3;
}

void Game::draw() {
    window.clear(sf::Color::White);
    window.draw(background);
    field.draw(window, s);
    tetromino->draw(window, s);
    window.draw(frame);

    // Nền cho cấp độ
    sf::RectangleShape levelBackground(sf::Vector2f(150, 40)); // Kích thước hình chữ nhật
    levelBackground.setFillColor(sf::Color(0, 0, 0, 150)); // Màu đen với độ trong suốt
    levelBackground.setPosition(5, 5); // Vị trí hiển thị
    window.draw(levelBackground);

    // Hiển thị cấp độ
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        window.close();
        return;
    }

    sf::Text levelText("Level: " + std::to_string(level), font, 25); // Tăng kích thước chữ
    levelText.setFillColor(sf::Color::Yellow); // Đổi màu chữ thành vàng
    levelText.setStyle(sf::Text::Bold); // Làm chữ đậm
    levelText.setOutlineColor(sf::Color::Black); // Thêm viền đen
    levelText.setOutlineThickness(2); // Độ dày viền
    levelText.setPosition(10, 10); // Vị trí hiển thị
    window.draw(levelText);

    if (isGameOver) {
        // Hiển thị thông báo kết thúc trò chơi
        sf::Text gameOverText("Game Over", font, 30);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setStyle(sf::Text::Bold);
        gameOverText.setOutlineColor(sf::Color::Black);
        gameOverText.setOutlineThickness(2);
        gameOverText.setPosition(80, 200);
        window.draw(gameOverText);
    }

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        draw();

        if (isGameOver) {
            // Thoát vòng lặp nếu trò chơi kết thúc
            break;
        }
    }
}
