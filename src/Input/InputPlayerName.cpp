#include "InputPlayerName.h"

PlayerNameInput::PlayerNameInput(sf::RenderWindow& win) : window(win), playerName("") {
    font.loadFromFile("assets/arial.ttf");

    promptText.setFont(font);
    promptText.setString("Nhap ten nguoi choi:");
    promptText.setCharacterSize(28);
    promptText.setFillColor(sf::Color::White);
    promptText.setPosition(30, 120);

    inputText.setFont(font);
    inputText.setCharacterSize(28);
    inputText.setFillColor(sf::Color::Yellow);
    inputText.setPosition(30, 180);
}

std::string PlayerNameInput::getPlayerName() {
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Backspace
                    if (!playerName.empty())
                        playerName.pop_back();
                } else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Enter
                    if (!playerName.empty())
                        return playerName;
                } else if (playerName.size() < 16 && event.text.unicode < 128 && event.text.unicode >= 32) {
                    playerName += static_cast<char>(event.text.unicode);
                }
            }
        }
        inputText.setString(playerName + "|");

        window.clear(sf::Color(30,30,30));
        window.draw(promptText);
        window.draw(inputText);
        window.display();
    }
    return playerName;
}
