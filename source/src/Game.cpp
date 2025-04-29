#include "Game.h"

Game::Game() : window(VideoMode(320, 480), "The Game!") {
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
}

void Game::handleInput() {
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed)
            window.close();

        if (e.type == Event::KeyPressed) {
            if (e.key.code == Keyboard::Up) rotate = true;
            else if (e.key.code == Keyboard::Left) dx = -1;
            else if (e.key.code == Keyboard::Right) dx = 1;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
}

void Game::update() {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    tetromino.backupState();
    tetromino.move(dx);
    if (!tetromino.isValid(field)) {
        tetromino.restoreState();
    }

    if (rotate) {
        tetromino.backupState();
        tetromino.rotate();
        if (!tetromino.isValid(field)) {
            tetromino.restoreState();
        }
    }

    if (timer > delay) {
        tetromino.backupState();
        tetromino.fall();
        if (!tetromino.isValid(field)) {
            tetromino.restoreState();
            tetromino.lock(field);
            field.clearLines();
            tetromino = TetrominoFactory::createTetromino(); // Tạo khối mới bằng Factory
        }
        timer = 0;
    }

    dx = 0;
    rotate = false;
    delay = 0.3;
}
void Game::draw() {
    window.clear(Color::White);
    window.draw(background);
    field.draw(window, s);
    tetromino.draw(window, s);
    window.draw(frame);
    window.display();
    scoreManager.draw(window);
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        draw();
    }
}
