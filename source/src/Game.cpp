#include "Game.h"
#include <ctime>

Game::Game()
    : window(sf::VideoMode(320, 480), "Tetris"),
      currentBlock(rand() % 7),
      timer(0), delay(0.3f), colorNum(1) {
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            window.close();
        }

        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Left) {
                currentBlock.move(-1, 0);
                if (!grid.check(currentBlock.getShape())) {
                    currentBlock.move(1, 0); // Hoàn tác nếu không hợp lệ
                }
            } else if (e.key.code == sf::Keyboard::Right) {
                currentBlock.move(1, 0);
                if (!grid.check(currentBlock.getShape())) {
                    currentBlock.move(-1, 0); // Hoàn tác nếu không hợp lệ
                }
            } else if (e.key.code == sf::Keyboard::Up) {
                currentBlock.rotate();
                if (!grid.check(currentBlock.getShape())) {
                    // Không hợp lệ thì không xoay
                    currentBlock.rotate(); // Xoay ngược lại
                    currentBlock.rotate();
                    currentBlock.rotate();
                }
            } else if (e.key.code == sf::Keyboard::Down) {
                delay = 0.05f; // Giảm delay để khối rơi nhanh hơn
            }
        }
        
        if (e.type == sf::Event::KeyReleased) {
            if (e.key.code == sf::Keyboard::Down) {
                delay = 0.3f; // Khôi phục delay ban đầu khi nhả phím
            }
        }
    }
}

void Game::update(float deltaTime) {
    timer += deltaTime;
    if (timer > delay) {
        currentBlock.move(0, 1); // Di chuyển khối xuống
        if (!grid.check(currentBlock.getShape())) {
            currentBlock.move(0, -1); // Hoàn tác nếu không hợp lệ
            grid.placeBlock(currentBlock.getShape(), currentBlock.getColor()); // Đặt khối vào lưới
            grid.clearFullLines(); // Xóa các hàng đầy
            currentBlock = Block(rand() % 7); // Khởi tạo khối mới
        }
        timer = 0;
    }
}

void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    grid.draw(window, s);

    // Vẽ khối hiện tại
    const std::array<Point, 4>& shape = currentBlock.getShape(); // Lấy tham chiếu đến mảng `shape`
    for (const auto& p : shape) {
        s.setTextureRect(sf::IntRect(currentBlock.getColor() * 18, 0, 18, 18));
        s.setPosition(p.x * 18, p.y * 18);
        s.move(28, 31); // Offset
        window.draw(s);
    }

    window.draw(frame);
    window.display();
}
