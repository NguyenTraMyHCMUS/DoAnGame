#include "InputHandler.h"

InputHandler::InputHandler() : dx(0), rotate(false) {}

void InputHandler::processInput(const sf::Event& event) {
    // Dummy implementation for test
}

void InputHandler::reset() {
    dx = 0;
    rotate = false;
}

int InputHandler::getDx() const {
    return dx;
}

void InputHandler::setDx(int value) {
    dx = value;
}

bool InputHandler::getRotate() const {
    return rotate;
}

void InputHandler::setRotate(bool value) {
    rotate = value;
}
