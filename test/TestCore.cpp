#include "catch.hpp"
#include "../Core/Game.h"
#include "../States/GameState.h"

// Dummy GameState để test setState
class DummyState : public GameState {
public:
    DummyState() : GameState() {}
    void handleInput(Game&) override {}
    void draw(Game&) override {}
    void update(Game&) override {}
};

TEST_CASE("Game initializes correctly", "[Game]") {
    Game game;

    SECTION("Default delay is 0.3f") {
        REQUIRE(game.getDelay() == Approx(0.3f));
    }

    SECTION("Setter/getter for delay works") {
        game.setDelay(0.5f);
        REQUIRE(game.getDelay() == Approx(0.5f));
    }

    SECTION("Setter/getter for player name works") {
        game.setPlayerName("Nguyen Van A");
        REQUIRE(game.getPlayerName() == "Nguyen Van A");
    }

    SECTION("All getters return valid references") {
        REQUIRE_NOTHROW(game.getWindow());
        REQUIRE_NOTHROW(game.getResourceManager());
        REQUIRE_NOTHROW(game.getRenderer());
        REQUIRE_NOTHROW(game.getInputHandler());
        REQUIRE_NOTHROW(game.getGameTimer());
        REQUIRE_NOTHROW(game.getField());
        REQUIRE_NOTHROW(game.getTetromino());
        REQUIRE_NOTHROW(game.getNextTetrominoPreview());
        REQUIRE_NOTHROW(game.getScoreManager());
        REQUIRE_NOTHROW(game.getLevelManager());
        REQUIRE_NOTHROW(game.getStateManager());
    }
}

TEST_CASE("Game::setPlayerName and getPlayerName", "[Game]") {
    Game game;
    game.setPlayerName("TestName");
    REQUIRE(game.getPlayerName() == "TestName");
}

// Nếu bạn có hàm setState trong Game, hãy test như sau (nếu không có thì bỏ qua)
TEST_CASE("Game can set state with DummyState", "[Game]") {
    Game game;
    // Nếu Game có hàm setState, hãy mở comment dòng dưới:
    // auto dummy = std::make_unique<DummyState>();
    // REQUIRE_NOTHROW(game.setState(std::move(dummy)));
}
