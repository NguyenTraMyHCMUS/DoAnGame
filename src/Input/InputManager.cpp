#include "InputManager.h"

InputManager::InputManager() : dx(0), rotate(false) {
}

void InputManager::processInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                rotate = true;
                break;
            case sf::Keyboard::Left:
                dx = -1;
                break;
            case sf::Keyboard::Right:
                dx = 1;
                break;
            default:
                break;
        }
    }
}

void InputManager::reset() {
    dx = 0;
    rotate = false;
}

int InputManager::getDx() const {
    return dx;
}

void InputManager::setDx(int value) {
    dx = value;
}

bool InputManager::getRotate() const {
    return rotate;
}

void InputManager::setRotate(bool value) {
    rotate = value;
}