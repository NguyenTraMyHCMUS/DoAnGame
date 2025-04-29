#include <iostream>
#include "Game.h"
#include "TetrominoFactory.h"
using namespace sf;

Game::Game() : window(VideoMode(320, 480), "Tetris") {
   t1.loadFromFile("assets/images/tiles.png");
    t2.loadFromFile("assets/images/background.png");
    t3.loadFromFile("assets/images/frame.png");
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
    tetromino = TetrominoFactory::createRandomTetromino();

    // Tải hình ảnh menu
    if (!menuBackgroundTexture.loadFromFile("assets/images/menu.jpg")) {
        std::cerr << "Failed to load menu background image!" << std::endl;
    }

    menuBackgroundSprite.setTexture(menuBackgroundTexture);
    menuBackgroundSprite.setPosition(0, 0); // Đặt vị trí hình ảnh menu

    // Tải hình ảnh Game Over
    if (!gameOverTexture.loadFromFile("assets/images/end.jpg")) {
        std::cerr << "Failed to load Game Over image!" << std::endl;
    }

    gameOverSprite.setTexture(gameOverTexture);
    gameOverSprite.setPosition(0, 0); // Đặt vị trí hình ảnh Game Over
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

            score += cleared * 100; // Cộng điểm cho mỗi dòng đã xóa

            // Tăng cấp độ sau mỗi 10 dòng xóa
            if (linesCleared >= level * 2) { // Mỗi cấp độ yêu cầu xóa 2 dòng
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
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
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
        if (state == GameState::MainMenu) {
            handleMainMenuInput();
            drawMainMenu();
        } else if (state == GameState::Playing) {
            handleInput();
            update();
            draw();

            if (isGameOver) {
                state = GameState::GameOver; // Chuyển sang trạng thái kết thúc
            }
        } else if (state == GameState::GameOver) {
            handleGameOverInput();
            drawGameOverScreen();
        }
    }
}

void Game::drawMainMenu() {
    window.clear(sf::Color::Black);

    // Vẽ hình ảnh menu
    window.draw(menuBackgroundSprite);

    // Chọn phông chữ cho menu
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        window.close();
        return;
    }

    // Tiêu đề
    sf::Text title("TETRIS", font, 50);
    title.setFillColor(sf::Color::Yellow);
    title.setStyle(sf::Text::Bold);
    title.setPosition(80, 220);
    window.draw(title);

    // Tùy chọn Start Game
    sf::Text startText("Start Game", font, 30);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(100, 300);
    window.draw(startText);

    // Tùy chọn Exit
    sf::Text exitText("Exit", font, 30);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(100, 340);
    window.draw(exitText);


    window.display();
}

void Game::handleMainMenuInput() {
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            window.close();
        }

        if (e.type == Event::KeyPressed) {
            if (e.key.code == Keyboard::Enter) {
                state = GameState::Playing; // Chuyển sang trạng thái chơi game
            } 
            else if (e.key.code == Keyboard::Escape) {
                window.close(); // Thoát trò chơi
            }
        }
    }
}

void Game::drawGameOverScreen() {
    window.clear(sf::Color::Black);

    // Vẽ hình ảnh Game Over
    window.draw(gameOverSprite);

    // Chọn phông chữ cho Game Over
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        window.close();
        return;
    }

    // Thông báo Game Over
    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(40, 100);
    window.draw(gameOverText);

    // Tùy chọn chơi lại
    sf::Text retryText("Enter to Retry", font, 30);
    retryText.setFillColor(sf::Color::Red);
    retryText.setPosition(50, 200);
    window.draw(retryText);

    // Tùy chọn thoát
    sf::Text exitText("Escape to Exit", font, 30);
    exitText.setFillColor(sf::Color::Red);
    exitText.setPosition(50, 250);
    window.draw(exitText);

    window.display();
}

void Game::handleGameOverInput() {
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            window.close();
        }

        if (e.type == Event::KeyPressed) {
            if (e.key.code == Keyboard::Enter) {
                state = GameState::Playing; // Chuyển sang trạng thái chơi game
                resetGame(); // Đặt lại trò chơi
            } else if (e.key.code == Keyboard::Escape) {
                window.close(); // Thoát trò chơi
            }
        }
    }
}

void Game::resetGame() {
    isGameOver = false;
    score = 0;
    level = 1;
    linesCleared = 0;
    delay = 0.3;
    timer = 0;
    dx = 0;
    rotate = false;
    tetromino = TetrominoFactory::createRandomTetromino();
    field.clear(); // Xóa lưới
}
