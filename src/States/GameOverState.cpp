#include "GameOverState.h"

GameOverState::GameOverState(Game& game) : _game(game), _selectedIndex(0) {
    // --- Cập nhật điểm ngay khi vào GameOver ---
    std::string playerName = game.getPlayerName();
    game.getScoreManager().submitScore(playerName);
    
    // Tải hình ảnh Game Over
    if (!_gameOverTexture.loadFromFile("assets/images/end.jpg")) {
        std::cout << "Failed to load Game Over image!" << std::endl;
    }

    _gameOverSprite.setTexture(_gameOverTexture);
    _gameOverSprite.setPosition(0, 0); // Đặt vị trí hình ảnh Game Over

    // Tải phông chữ
    if (!_font.loadFromFile("assets/fonts/Motion.otf")) {
        std::cout << "Failed to load font \"assets/fonts/Motion.otf\". Please ensure the file exists." << std::endl;
        game.getWindow().close();
        return;
    }

    // Thiết lập tiêu đề Game Over
    _title.setFont(_font);
    _title.setString("Game Over");
    _title.setCharacterSize(50);
    _title.setFillColor(sf::Color::Red);
    _title.setPosition(60, 50); // Đặt vị trí tiêu đề Game Over
    _title.setStyle(sf::Text::Bold);

    // Thiết lập các mục menu
    _menuOptions[0].setFont(_font);
    _menuOptions[0].setString("Retry");
    _menuOptions[0].setCharacterSize(40);
    _menuOptions[0].setFillColor(sf::Color::Yellow); // Mục đầu tiên được chọn mặc định
    _menuOptions[0].setPosition(100, 200);
    _menuOptions[0].setStyle(sf::Text::Bold);

    _menuOptions[1].setFont(_font);
    _menuOptions[1].setString("Exit");
    _menuOptions[1].setCharacterSize(40);
    _menuOptions[1].setFillColor(sf::Color::Red);
    _menuOptions[1].setPosition(100, 250);
    _menuOptions[0].setStyle(sf::Text::Bold);

    // Top 3 điểm cao nhất
    const auto& topScores = game.getScoreManager().getTopScores(3);
    sf::Color scoreColor(255, 215, 0); // Gold
    for (int i = 0; i < 3; ++i) {
        _topScoreTexts[i].setFont(_font);
        if (i < topScores.size()) {
            std::string text = std::to_string(i + 1) + ". " + topScores[i].first + " - " + std::to_string(topScores[i].second);
            _topScoreTexts[i].setString(text);
        } else {
            _topScoreTexts[i].setString(std::to_string(i + 1) + ". ---");
        }
        _topScoreTexts[i].setCharacterSize(26);
        _topScoreTexts[i].setFillColor(scoreColor);
        _topScoreTexts[i].setStyle(sf::Text::Bold);
        // Căn giữa từng dòng top score
        sf::FloatRect scoreBounds = _topScoreTexts[i].getLocalBounds();
        _topScoreTexts[i].setOrigin(scoreBounds.left + scoreBounds.width / 2, scoreBounds.top + scoreBounds.height / 2);
        _topScoreTexts[i].setPosition(160, 120 + i * 34);
    }
}

void GameOverState::handleInput(Game& game) {
    sf::Event e;
    // Xử lý sự kiện đầu vào cho trạng thái Game Over
    while (game.getWindow().pollEvent(e)) {
        // Nhấn nút X ở góc trên bên trái để đóng cửa sổ
        if (e.type == sf::Event::Closed) {
            game.getWindow().close();
        }
        
        // Xử lý các phím nhấn
        if (e.type == sf::Event::KeyPressed) {
            // Nhấn phím mũi tên lên để di chuyển lên
            if (e.key.code == sf::Keyboard::Up) {
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Red);
                _selectedIndex = (_selectedIndex - 1 + 2) % 2; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            } 
            // Nhấn phím mũi tên xuống để di chuyển xuống
            else if (e.key.code == sf::Keyboard::Down) {
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Red);
                _selectedIndex = (_selectedIndex + 1) % 2; // Vòng lặp qua các mục menu
                _menuOptions[_selectedIndex].setFillColor(sf::Color::Yellow);
            } 
            // Nhấn Enter để tiến hành lựa chọn
            else if (e.key.code == sf::Keyboard::Enter) {
                // Xử lý lựa chọn
                if (_selectedIndex == 0) {
                    // Chọn Retry
                    game.setState(std::make_unique<PlayingState>(game));
                    game.resetGame(); // Reset game
                } 
                else if (_selectedIndex == 1) {
                    // Chọn Exit
                    game.getWindow().close();
                }
            }
        }
    }
}

void GameOverState::draw(Game& game) {
    // Xóa
    game.getWindow().clear(sf::Color::Black);

    // Vẽ hình ảnh Game Over
    game.getWindow().draw(_gameOverSprite);

    // Vẽ tiêu đề Game Over
    game.getWindow().draw(_title);

    // Vẽ top 3 điểm cao nhất
    for (int i = 0; i < 3; ++i) {
        game.getWindow().draw(_topScoreTexts[i]);
    }
    
    // Vẽ các mục menu
    for (int i = 0; i < 2; ++i) {
        game.getWindow().draw(_menuOptions[i]);
    }

    // Hiển thị tất cả các đối tượng đã vẽ
    game.getWindow().display();
}

void GameOverState::update(Game&) {
    // Không cần cập nhật gì cho màn hình Game Over
}
