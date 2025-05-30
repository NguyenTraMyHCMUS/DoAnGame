#include "catch.hpp"
#include "../Time/GameTimer.h"
#include <thread>
#include <chrono>

TEST_CASE("GameTimer initializes with correct delay", "[GameTimer]") {
    GameTimer timer(0.5f);
    REQUIRE(timer.getDelay() == Approx(0.5f));
}

TEST_CASE("GameTimer setDelay and getDelay", "[GameTimer]") {
    GameTimer timer;
    timer.setDelay(1.0f);
    REQUIRE(timer.getDelay() == Approx(1.0f));
}

TEST_CASE("GameTimer restart resets timer", "[GameTimer]") {
    GameTimer timer;
    timer.restart();
    REQUIRE(timer.getTimer() == Approx(0.0f).margin(0.01f));
}

TEST_CASE("GameTimer shouldUpdate returns true after delay", "[GameTimer]") {
    GameTimer timer(0.1f);
    timer.restart();
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
    timer.update();
    REQUIRE(timer.shouldUpdate());
}

TEST_CASE("GameTimer shouldUpdate returns false before delay", "[GameTimer]") {
    GameTimer timer(0.5f);
    timer.restart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.update();
    REQUIRE_FALSE(timer.shouldUpdate());
}
