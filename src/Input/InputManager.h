#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Window/Event.hpp>

/**
 * @class InputManager
 * @brief Quản lý và xử lý đầu vào từ người dùng (Single Responsibility)
 */
class InputManager {
private:
    int dx;
    bool rotate;

public:
    InputManager();
    void processInput(const sf::Event& event);
    void reset();
    
    int getDx() const;
    bool getRotate() const;
    
    void setDx(int value);
    void setRotate(bool value);
};

#endif