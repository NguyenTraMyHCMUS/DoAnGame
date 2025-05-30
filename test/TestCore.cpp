#include "catch.hpp"
#include "../Core/Game.h"

// Mock dependent classes if needed (if not available, just test simple getter/setter)

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
        REQUIRE_NOTHROW(game.getInputManager());
        REQUIRE_NOTHROW(game.getGameTimer());
        REQUIRE_NOTHROW(game.getField());
        REQUIRE_NOTHROW(game.getTetromino());
        REQUIRE_NOTHROW(game.getNextTetrominoPreview());
        REQUIRE_NOTHROW(game.getScoreManager());
        REQUIRE_NOTHROW(game.getLevelManager());
    }
}

TEST_CASE("Game::setState works", "[Game]") {
    Game game;
    // Create a dummy state for testing
    class DummyState : public GameState {
    public:
        DummyState(Game&) : GameState() {}
        void handleInput(Game&) override {}
        void draw(Game&) override {}
        void update(Game&) override {} // Add this line to implement the pure virtual function
    };
    auto dummy = std::make_unique<DummyState>(game);
    REQUIRE_NOTHROW(game.setState(std::move(dummy)));
}
