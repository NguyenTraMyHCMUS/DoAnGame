#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SFML/Window/Event.hpp>

/**
 * @class InputHandler
 * @brief Xử lý đầu vào từ người chơi
 */
class InputHandler {
private:
    int dx;
    bool rotate;

public:
    InputHandler();
    void processInput(const sf::Event& event);
    void reset();
    
    int getDx() const;
    void setDx(int value);
    
    bool getRotate() const;
    void setRotate(bool value);
};

#endif