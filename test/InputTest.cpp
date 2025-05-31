#include "catch.hpp"
#include "../Input/InputManager.h"
#include "../Input/IInputHandler.h"
#include "../Input/InputPlayerName.h"

class DummyInputHandler : public IInputHandler {
    int dx = 0;
    bool rotate = false;
public:
    void handleInput(Game&) override {}
    int getDx() const override { return dx; }
    bool getRotate() const override { return rotate; }
    void reset() override { dx = 0; rotate = false; }
    void setDx(int value) override { dx = value; }
    void setRotate(bool value) override { rotate = value; }
};

// InputManager tests
TEST_CASE("InputManager default values", "[InputManager]") {
    InputManager input_manager;
    REQUIRE(input_manager.getDx() == 0);
    REQUIRE(input_manager.getRotate() == false);
}

TEST_CASE("InputManager set/get dx and rotate", "[InputManager]") {
    InputManager input_manager;
    input_manager.setDx(2);
    input_manager.setRotate(true);
    REQUIRE(input_manager.getDx() == 2);
    REQUIRE(input_manager.getRotate() == true);
}

TEST_CASE("InputManager reset", "[InputManager]") {
    InputManager input_manager;
    input_manager.setDx(5);
    input_manager.setRotate(true);
    input_manager.reset();
    REQUIRE(input_manager.getDx() == 0);
    REQUIRE(input_manager.getRotate() == false);
}

// Có thể test processInput nếu muốn (ví dụ với sự kiện giả lập)
// TEST_CASE("InputManager processInput", "[InputManager]") {
//     InputManager input_manager;
//     sf::Event event;
//     event.type = sf::Event::KeyPressed;
//     event.key.code = sf::Keyboard::Left;
//     input_manager.processInput(event);
//     // Kiểm tra dx thay đổi nếu bạn implement logic
// }

// InputHandler tests (nếu là class riêng biệt)
TEST_CASE("InputHandler default values", "[InputHandler]") {
    DummyInputHandler input_handler;
    REQUIRE(input_handler.getDx() == 0);
    REQUIRE(input_handler.getRotate() == false);
}

TEST_CASE("InputHandler set/get dx and rotate", "[InputHandler]") {
    DummyInputHandler input_handler;
    input_handler.setDx(-1);
    input_handler.setRotate(true);
    REQUIRE(input_handler.getDx() == -1);
    REQUIRE(input_handler.getRotate() == true);
}

TEST_CASE("InputHandler reset", "[InputHandler]") {
    DummyInputHandler input_handler;
    input_handler.setDx(3);
    input_handler.setRotate(true);
    input_handler.reset();
    REQUIRE(input_handler.getDx() == 0);
    REQUIRE(input_handler.getRotate() == false);
}

// PlayerNameInput chỉ test được constructor
TEST_CASE("PlayerNameInput can be constructed", "[PlayerNameInput]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    PlayerNameInput input(window);
    SUCCEED();
}
