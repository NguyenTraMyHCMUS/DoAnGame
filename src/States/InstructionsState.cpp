#include "InstructionsState.h"


InstructionsState::InstructionsState(Game& game) : _game(game) {
    // Tải hình ảnh nền
    if (!_instructionTexture.loadFromFile("assets/images/instruction.jpg")) {
        std::cerr << "Failed to load instructions background!" << std::endl;
        game.getWindow().close();
        return;
    }

    _instructionSprite.setTexture(_instructionTexture);
    _instructionSprite.setPosition(0, 0); // Đặt vị trí hình ảnh nền

    // Tải phông chữ
    if (!_font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        game.getWindow().close();
        return;
    }

    // Thiết lập tiêu đề
    _title.setFont(_font);
    _title.setString(L"Hướng dẫn");
    _title.setCharacterSize(40);
    _title.setFillColor(sf::Color(128, 0, 128));
    _title.setPosition(50, 50);
    _title.setStyle(sf::Text::Bold);

    // Thiết lập nội dung hướng dẫn
    _instructions.setFont(_font);
    _instructions.setString(L"1. Xóa 1 dòng được 10 điểm\n2. Tăng 100 điểm thì tăng 1 level\n3. Xóa x dòng tăng 10*x*x điểm\n4. Level cao tốc độ rơi nhanh\n5. Esc để tạm dừng khi chơi");
    _instructions.setCharacterSize(16);
    _instructions.setFillColor(sf::Color(221, 160, 221));
    _instructions.setPosition(50, 150);

    // Thiết lập tùy chọn quay lại
    _backOption.setFont(_font);
    _backOption.setString(L"Enter để quay lại");
    _backOption.setCharacterSize(20);
    _backOption.setFillColor(sf::Color(173, 216, 230));
    _backOption.setPosition(70, 350);
    _backOption.setStyle(sf::Text::Bold);
}

void InstructionsState::handleInput(Game& game) {
    sf::Event event;
    while (game.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                // Quay lại menu chính
                game.setState(std::make_unique<MainMenuState>(game));
            }
        }
    }
}

void InstructionsState::draw(Game& game) {
    // Xóa 
    game.getWindow().clear(sf::Color::Black);

    // Vẽ hình ảnh nền
    game.getWindow().draw(_instructionSprite);

    // Vẽ tiêu đề, nội dung hướng dẫn và tùy chọn quay lại
    game.getWindow().draw(_title);

    // Ghi nội dung hướng dẫn
    game.getWindow().draw(_instructions);

    // Vẽ tùy chọn quay lại
    game.getWindow().draw(_backOption);

    // Hiển thị cửa sổ
    game.getWindow().display();
}
