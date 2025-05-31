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
    InputManager im;
    REQUIRE(im.getDx() == 0);
    REQUIRE(im.getRotate() == false);
}

TEST_CASE("InputManager set/get dx and rotate", "[InputManager]") {
    InputManager im;
    im.setDx(2);
    im.setRotate(true);
    REQUIRE(im.getDx() == 2);
    REQUIRE(im.getRotate() == true);
}

TEST_CASE("InputManager reset", "[InputManager]") {
    InputManager im;
    im.setDx(5);
    im.setRotate(true);
    im.reset();
    REQUIRE(im.getDx() == 0);
    REQUIRE(im.getRotate() == false);
}

// Có thể test processInput nếu muốn (ví dụ với sự kiện giả lập)
// TEST_CASE("InputManager processInput", "[InputManager]") {
//     InputManager im;
//     sf::Event event;
//     event.type = sf::Event::KeyPressed;
//     event.key.code = sf::Keyboard::Left;
//     im.processInput(event);
//     // Kiểm tra dx thay đổi nếu bạn implement logic
// }

// InputHandler tests (nếu là class riêng biệt)
TEST_CASE("InputHandler default values", "[InputHandler]") {
    DummyInputHandler ih;
    REQUIRE(ih.getDx() == 0);
    REQUIRE(ih.getRotate() == false);
}

TEST_CASE("InputHandler set/get dx and rotate", "[InputHandler]") {
    DummyInputHandler ih;
    ih.setDx(-1);
    ih.setRotate(true);
    REQUIRE(ih.getDx() == -1);
    REQUIRE(ih.getRotate() == true);
}

TEST_CASE("InputHandler reset", "[InputHandler]") {
    DummyInputHandler ih;
    ih.setDx(3);
    ih.setRotate(true);
    ih.reset();
    REQUIRE(ih.getDx() == 0);
    REQUIRE(ih.getRotate() == false);
}

// PlayerNameInput chỉ test được constructor
TEST_CASE("PlayerNameInput can be constructed", "[PlayerNameInput]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    PlayerNameInput input(window);
    SUCCEED();
}
