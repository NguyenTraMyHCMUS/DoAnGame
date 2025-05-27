#include "PausedState.h"


PausedState::PausedState(Game& game) : _game(game), _selectedIndex(0) {
    //Tải hình ảnh tạm dừng
    if (!_pausedTexture.loadFromFile("assets/images/paused.jpg")) {
        std::cout << "Failed to load paused image!" << std::endl;
        game.getWindow().close();
        return;
    }

    _pausedSprite.setTexture(_pausedTexture);
    _pausedSprite.setPosition(0, 0); // Đặt vị trí hình ảnh tạm dừng

    // Tải phông chữ
    if (!_font.loadFromFile("assets/fonts/Motion.otf")) {
        std::cout << "Failed to load font \"assets/fonts/Motion.otf\". Please ensure the file exists." << std::endl;
        game.getWindow().close();
        return;
    }

    // Thiết lập tiêu đề tạm dừng
    _title.setFont(_font);
    _title.setString("Paused");
    _title.setCharacterSize(50);
    _title.setFillColor(sf::Color(255, 105, 180)); // Màu hồng (Hot Pink)
    _title.setPosition(90, 100); 
    _title.setStyle(sf::Text::Bold);

    // Thiết lập các mục menu
    _menuOptions[0].setFont(_font);
    _menuOptions[0].setString("Continue");
    _menuOptions[0].setCharacterSize(30);
    _menuOptions[0].setFillColor(sf::Color::Yellow); // Mục đầu tiên được chọn mặc định
    _menuOptions[0].setPosition(50, 360); // Đặt bên trái

    _menuOptions[1].setFont(_font);
    _menuOptions[1].setString("Exit");
    _menuOptions[1].setCharacterSize(30);
    _menuOptions[1].setFillColor(sf::Color::White); // Mục chưa được chọn
    _menuOptions[1].setPosition(220, 360); // Đặt bên phải
}

void PausedState::handleInput(Game& game) {
    sf::Event e;
    while (game.getWindow().pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            game.getWindow().close();
        }

        if (e.type == sf::Event::KeyPressed) {
            // Nhấn phím mũi tên trái để di chuyển sang trái
            if (e.key.code == sf::Keyboard::Left) {
                _menuOptions[_selectedIndex].setFillColor(sf::Color::White);
                _selectedIndex = (_selectedIndex - 1 + 2) % 2; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            }
            // Nhấn phím mũi tên phải để di chuyển sang phải
            else if (e.key.code == sf::Keyboard::Right) {
                _menuOptions[_selectedIndex].setFillColor(sf::Color::White);
                _selectedIndex = (_selectedIndex + 1) % 2; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            }
            // Nhấn phím Enter để chọn
            else if (e.key.code == sf::Keyboard::Enter) {
                if (_selectedIndex == 0) {
                    // Tiếp tục trò chơi
                    game.setState(std::make_unique<PlayingState>(game));
                } 
                else if (_selectedIndex == 1) {
                    // Thoát trò chơi
                    game.getWindow().close();
                }
            }
        }
    }
}

void PausedState::draw(Game& game) {
    game.getWindow().clear(sf::Color::Black);

    // Vẽ hình ảnh tạm dừng
    game.getWindow().draw(_pausedSprite);
    
    // Vẽ tiêu đề tạm dừng
    game.getWindow().draw(_title);

    // Vẽ các mục menu
    for (int i = 0; i < 2; ++i) {
        game.getWindow().draw(_menuOptions[i]);
    }

    game.getWindow().display();
}

void PausedState::update(Game& game) {
    // Không cần cập nhật gì trong trạng thái tạm dừng
    // Tất cả xử lý sự kiện và vẽ đã được thực hiện trong handleInput và draw
}
