#include "MainMenuState.h"
#include "PlayingState.h"
#include "InstructionsState.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

MainMenuState::MainMenuState(Game& game) : _game(game), _selectedIndex(0) { 
    // Tải hình ảnh nền menu
    if (!_menuBackgroundTexture.loadFromFile("assets/images/menu2.jpg")) {
        std::cerr << "Failed to load menu background image!" << std::endl;
    }
    _menuBackgroundSprite.setTexture(_menuBackgroundTexture);
    _menuBackgroundSprite.setPosition(0, 0); 

    // Tải hình ảnh khung nút
    if (!_buttonTexture.loadFromFile("assets/images/khung2.jpg")) {
        std::cerr << "Failed to load button background image!" << std::endl;
    }

    // Tạo sprite cho các nút
    _buttonSprites[0].setTexture(_buttonTexture);
    _buttonSprites[0].setPosition(95, 200); // Vị trí nút "Start"

    _buttonSprites[1].setTexture(_buttonTexture);
    _buttonSprites[1].setPosition(95, 260); // Vị trí nút "Instructions"

    _buttonSprites[2].setTexture(_buttonTexture);
    _buttonSprites[2].setPosition(95, 320); // Vị trí nút "Exit"

    // Tải phông chữ cho tiêu đề
    if (!_fontTitle.loadFromFile("assets/fonts/Alivia.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        game.getWindow().close();
        return;
    }

    // Tải phông chữ cho menu 
    if (!_font.loadFromFile("assets/fonts/Motion.otf")) {
        std::cout << "Failed to load font!" << std::endl;
        game.getWindow().close();
        return;
    }

    // Tải phông chữ cho welcome
    if (!_fontWelcome.loadFromFile("assets/fonts/welcome.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        game.getWindow().close();
        return;
    }

    // Thiết lập tiêu đề menu
    _title.setFont(_fontTitle);
    _title.setString("Tetris Game");
    _title.setCharacterSize(40);
    _title.setFillColor(sf::Color(255, 105, 180)); // Màu hồng (Hot Pink)
    _title.setPosition(20, 50);
    _title.setStyle(sf::Text::Bold);

    // Thiết lập welcome
    _welcome.setFont(_fontWelcome);
    _welcome.setString("Welcome to us");
    _welcome.setCharacterSize(20);
    _welcome.setFillColor(sf::Color(255, 192, 203));
    _welcome.setPosition(100, 110);

    // Thiết lập các mục menu
    _menuOptions[0].setFont(_font);
    _menuOptions[0].setString("Start");
    _menuOptions[0].setCharacterSize(30);
    _menuOptions[0].setFillColor(sf::Color::Yellow);
    _menuOptions[0].setPosition(125, 200); // Căn giữa với khung

    _menuOptions[1].setFont(_font);
    _menuOptions[1].setString("Instruction");
    _menuOptions[1].setCharacterSize(30);
    _menuOptions[1].setFillColor(sf::Color::White);
    _menuOptions[1].setPosition(100, 260); // Căn giữa với khung

    _menuOptions[2].setFont(_font);
    _menuOptions[2].setString("Exit");
    _menuOptions[2].setCharacterSize(30);
    _menuOptions[2].setFillColor(sf::Color::White);
    _menuOptions[2].setPosition(135, 320); // Căn giữa với khung
}

void MainMenuState::handleInput(Game& game) {
    sf::Event event;

    while (game.getWindow().pollEvent(event)) {
        // Nhấn nút X ở góc trên bên trái để đóng cửa sổ
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                // Di chuyển lên
                _menuOptions[_selectedIndex].setFillColor(sf::Color::White);
                _selectedIndex = (_selectedIndex - 1 + 3) % 3; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            } 
            else if (event.key.code == sf::Keyboard::Down) {
                // Di chuyển xuống
                _menuOptions[_selectedIndex].setFillColor(sf::Color::White);
                _selectedIndex = (_selectedIndex + 1) % 3; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            } 
            // Nhấn phím Enter để chọn
            else if (event.key.code == sf::Keyboard::Enter) {
                // Xử lý lựa chọn
                if (_selectedIndex == 0) {
                    // Bắt đầu trò chơi
                    game.setState(std::make_unique<PlayingState>(game));
                } 
                else if (_selectedIndex == 1) {
                    // Mở cửa sổ hướng dẫn
                    game.setState(std::make_unique<InstructionsState>(game));
                } 
                else if (_selectedIndex == 2) {
                    // Thoát trò chơi
                    game.getWindow().close();
                }
            }
        }
    }
}

void MainMenuState::draw(Game& game) {
    // Xóa
    game.getWindow().clear(sf::Color::Black);

    // Vẽ hình ảnh nền menu
    game.getWindow().draw(_menuBackgroundSprite);

    // Vẽ tiêu đề menu
    game.getWindow().draw(_title);

    // Vẽ welcome
    game.getWindow().draw(_welcome);

    // Vẽ các mục menu
    for (int i = 0; i < 3; ++i) {
        game.getWindow().draw(_buttonSprites[i]); // Vẽ khung nút
        game.getWindow().draw(_menuOptions[i]);
    }

    // Hiển thị tất cả các đối tượng đã vẽ
    game.getWindow().display();
}

