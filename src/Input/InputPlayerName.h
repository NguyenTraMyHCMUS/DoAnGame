#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PlayerNameInput {
public:
    PlayerNameInput(sf::RenderWindow& window);
    std::string getPlayerName();

private:
    sf::RenderWindow& window;
    std::string playerName;
    sf::Font font;
    sf::Text promptText;
    sf::Text inputText;
};
