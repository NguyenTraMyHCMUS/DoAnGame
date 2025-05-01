#include <iostream>
#include "Game.h"
#include "TetrominoFactory.h"
using namespace sf;

Game::Game() : window(VideoMode(320, 480), "Tetris"), 
            nextTetrominoDisplay(sf::Vector2f(300, 100), 18) // Khởi tạo đối tượng hiển thị khối tiếp theo
{
   t1.loadFromFile("assets/images/tiles.png");
    t2.loadFromFile("assets/images/background.png");
    t3.loadFromFile("assets/images/frame.png");
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
    tetromino = TetrominoFactory::createRandomTetromino();

   //Khối tiếp theo
    nextTetromino = TetrominoFactory::createRandomTetromino(); // Tạo khối tiếp theo đầu tiên
    tetromino = std::move(nextTetromino);// Đặt khối hiện tại là khối tiếp theo
    nextTetromino = TetrominoFactory::createRandomTetromino(); // Tạo khối tiếp theo mới

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
   if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        isGameOver = true; // Đặt trạng thái kết thúc trò chơi
    }
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

            // Kiểm tra nếu khối bị đè theo cột hoặc hàng
            if (field.isColumnOverloaded({})) {
                isGameOver = true; // Đặt trạng thái kết thúc trò chơi
                return;
            }

            int cleared = field.clearLines(); // Xóa các dòng và trả về số dòng đã xóa
            if (cleared > 0) {
                int points = cleared * 10 * cleared;
                scoreManager.addScore(points);
                levelManager.addClearedLines(cleared);

                if (scoreManager.getScore() >= levelManager.getLevel() * 50) {
                    levelManager.increaseLevel();
                }
            }


            if (field.isTopReached()) { // Kiểm tra nếu đỉnh của lưới đã bị chiếm
                isGameOver = true; // Đặt trạng thái kết thúc trò chơi
                return;
            }
           // khối tiếp theo
            tetromino = std::move(nextTetromino);// Đặt khối hiện tại là khối tiếp theo
            nextTetromino = TetrominoFactory::createRandomTetromino();// Tạo khối tiếp theo mới
            tetromino->setColor(nextTetromino->getColor());// khối hiện tại của lần tiếp theo giống màu khối tiếp thao của lần hiện tiền
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

    // Hiển thị khối tiếp theo
    if (nextTetromino) {
        nextTetrominoDisplay.draw(window, *nextTetromino);
    }
   
    // Nền cho cấp độ
    sf::RectangleShape levelBackground(sf::Vector2f(150, 40));
    levelBackground.setFillColor(sf::Color(0, 0, 0, 150));
    levelBackground.setPosition(225, 50);
    window.draw(levelBackground);

    // Hiển thị cấp độ
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        window.close();
        return;
    }

    sf::Text levelText("Level: " + std::to_string(levelManager.getLevel()), font, 18);
    levelText.setFillColor(sf::Color::Yellow);
    levelText.setStyle(sf::Text::Bold);
    levelText.setOutlineColor(sf::Color::Black);
    levelText.setOutlineThickness(2);
    levelText.setPosition(230, 55);
    window.draw(levelText);

    // Nền cho điểm số
    sf::RectangleShape scoreBackground(sf::Vector2f(150, 40));
    scoreBackground.setFillColor(sf::Color(0, 0, 0, 150));
    scoreBackground.setPosition(225, 90);
    window.draw(scoreBackground);

    // Hiển thị điểm số
    sf::Text scoreText("Score: " + std::to_string(scoreManager.getScore()), font, 18);
    scoreText.setFillColor(sf::Color::Cyan);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(2);
    scoreText.setPosition(230, 95);
    window.draw(scoreText);
   
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
    scoreManager.reset();
    levelManager.reset();
    delay = 0.3;
    timer = 0;
    dx = 0;
    rotate = false;
    tetromino = TetrominoFactory::createRandomTetromino();
    field.clear(); // Xóa lưới
}
