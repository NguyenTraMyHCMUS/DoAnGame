#include "PlayerNameState.h"
#include "PlayingState.h"
#include "../Core/Game.h"

PlayerNameState::PlayerNameState(Game& game) {
    _font.loadFromFile("assets/fonts/Motion.otf");

    // Tiêu đề
    _titleText.setFont(_font);
    _titleText.setString("Input Player Name");
    _titleText.setCharacterSize(32);
    _titleText.setFillColor(sf::Color(255, 105, 180));
    _titleText.setStyle(sf::Text::Bold);
    _titleText.setPosition(40, 60);

    // Hướng dẫn
    _guideText.setFont(_font);
    _guideText.setString("Maximum 16 characters. Enter to confirm.");
    _guideText.setCharacterSize(16);
    _guideText.setFillColor(sf::Color(200, 200, 200));
    _guideText.setPosition(40, 220);

    // Prompt
    _promptText.setFont(_font);
    _promptText.setString("Name:");
    _promptText.setCharacterSize(24);
    _promptText.setFillColor(sf::Color::White);

    // Khung nhập
    float inputBoxWidth = 180.f;
    float inputBoxHeight = 40.f;
    float promptWidth = _promptText.getLocalBounds().width;
    float totalWidth = promptWidth + 10.f + inputBoxWidth; // 10px khoảng cách
    float startX = (320.f - totalWidth) / 2.f;
    float y = 140.f;

    _promptText.setPosition(startX, y);

    _inputBox.setSize(sf::Vector2f(inputBoxWidth, inputBoxHeight));
    _inputBox.setFillColor(sf::Color(30, 30, 30, 220));
    _inputBox.setOutlineColor(sf::Color(255, 105, 180));
    _inputBox.setOutlineThickness(3);
    _inputBox.setPosition(startX + promptWidth + 10.f, y - 4.f); // -4 để cân với text

    // Text nhập
    _inputText.setFont(_font);
    _inputText.setCharacterSize(24);
    _inputText.setFillColor(sf::Color::Yellow);
    _inputText.setPosition(_inputBox.getPosition().x + 8.f, y);
}

void PlayerNameState::handleInput(Game& game) {
    sf::Event event;
    while (game.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();
        }
        if (event.type == sf::Event::TextEntered && !_nameEntered) {
            if (event.text.unicode == '\b') {
                if (!_playerName.empty())
                    _playerName.pop_back();
            } else if ((event.text.unicode == '\r' || event.text.unicode == '\n')) {
                if (!_playerName.empty()) {
                    _nameEntered = true;
                    game.setPlayerName(_playerName); // Sử dụng setter thay vì truy cập trực tiếp
                    game.setState(std::make_unique<PlayingState>(game));
                }
            } else if (_playerName.size() < 16 && event.text.unicode < 128 && event.text.unicode >= 32) {
                _playerName += static_cast<char>(event.text.unicode);
            }
        }
    }
}

void PlayerNameState::update(Game&) {
    // Nhấp nháy con trỏ
    _cursorTimer += 0.03f;
    if (_cursorTimer >= 0.5f) {
        _showCursor = !_showCursor;
        _cursorTimer = 0.f;
    }
}

void PlayerNameState::draw(Game& game) {
    game.getWindow().clear(sf::Color(40, 40, 60));

    game.getWindow().draw(_titleText);
    game.getWindow().draw(_promptText);
    game.getWindow().draw(_inputBox);

    // Hiển thị tên và con trỏ nhấp nháy
    std::string displayName = _playerName;
    if (_showCursor && !_nameEntered) displayName += "|";
    _inputText.setString(displayName);
    game.getWindow().draw(_inputText);

    game.getWindow().draw(_guideText);

    game.getWindow().display();
}
