#include "catch.hpp"
#include "../Input/InputManager.h"
#include "../Input/InputHandler.h"
#include "../Input/InputPlayerName.h"

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

// InputHandler tests
TEST_CASE("InputHandler default values", "[InputHandler]") {
    InputHandler ih;
    REQUIRE(ih.getDx() == 0);
    REQUIRE(ih.getRotate() == false);
}

TEST_CASE("InputHandler set/get dx and rotate", "[InputHandler]") {
    InputHandler ih;
    ih.setDx(-1);
    ih.setRotate(true);
    REQUIRE(ih.getDx() == -1);
    REQUIRE(ih.getRotate() == true);
}

TEST_CASE("InputHandler reset", "[InputHandler]") {
    InputHandler ih;
    ih.setDx(3);
    ih.setRotate(true);
    ih.reset();
    REQUIRE(ih.getDx() == 0);
    REQUIRE(ih.getRotate() == false);
}

// PlayerNameInput: Chỉ test được constructor và interface vì phụ thuộc vào window thực
TEST_CASE("PlayerNameInput can be constructed", "[PlayerNameInput]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    PlayerNameInput input(window);
    SUCCEED();
}
