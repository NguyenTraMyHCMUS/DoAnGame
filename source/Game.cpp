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
            
    tetromino = nextPreview.getNext();       // lấy khối đầu tiên từ preview
    nextPreview.generateNext();              // tạo khối tiếp theo tiếp theo

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
    
            // Kiểm tra nếu khối tiếp theo không thể đặt vào lưới
            nextTetromino->backupState(); // Lưu trạng thái ban đầu của khối tiếp theo
            if (!nextTetromino->isValid(field)) {
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
    
            tetromino = nextPreview.getNext();  // lấy khối tiếp theo làm hiện tại
            nextPreview.generateNext();         // tạo khối tiếp theo mới
        }
        timer = 0;
    }

    dx = 0;
    rotate = false;
    delay = 0.3;
}       
                
void Game::drawInfoBox(sf::RenderWindow& window, sf::Vector2f position, const std::string& title, const std::string& value) {
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

void Game::draw() {
    window.clear(sf::Color::White);
    window.draw(background);
    field.draw(window, s);
    tetromino->draw(window, s);
    nextPreview.draw(window, s); // vẽ khối tiếp theo
    window.draw(frame);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        window.close();
        return;
    }

   

    sf::Vector2f infoStartPos(240, 180); // Ngay dưới khung "Next"
    drawInfoBox(window, infoStartPos, "Level", std::to_string(levelManager.getLevel()));
    drawInfoBox(window, sf::Vector2f(infoStartPos.x, infoStartPos.y + 70), "Score", std::to_string(scoreManager.getScore()));
    drawInfoBox(window, sf::Vector2f(infoStartPos.x, infoStartPos.y + 140), "HighScore", std::to_string(scoreManager.getHighScore()));

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
