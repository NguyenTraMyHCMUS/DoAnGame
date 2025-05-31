#include "catch.hpp"
#include "../States/MainMenuState.h"
#include "../States/PlayingState.h"
#include "../States/PausedState.h"
#include "../States/GameOverState.h"
#include "../States/InstructionsState.h"
#include "../States/PlayerNameState.h"
#include "../Core/Game.h"

// Dummy Game để truyền vào state (nếu cần)
class DummyGame : public Game {
public:
    DummyGame() : Game() {}
};

class DummyState : public GameState {
public:
    void handleInput(Game&) override {}
    void draw(Game&) override {}
    void update(Game&) override {}
};

TEST_CASE("MainMenuState can be constructed and methods called", "[MainMenuState]") {
    DummyGame game;
    MainMenuState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}

TEST_CASE("PlayingState can be constructed and methods called", "[PlayingState]") {
    DummyGame game;
    PlayingState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}

TEST_CASE("PausedState can be constructed and methods called", "[PausedState]") {
    DummyGame game;
    PausedState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}

TEST_CASE("GameOverState can be constructed and methods called", "[GameOverState]") {
    DummyGame game;
    GameOverState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}

TEST_CASE("InstructionsState can be constructed and methods called", "[InstructionsState]") {
    DummyGame game;
    InstructionsState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}

TEST_CASE("PlayerNameState can be constructed and methods called", "[PlayerNameState]") {
    DummyGame game;
    PlayerNameState state(game);
    REQUIRE_NOTHROW(state.handleInput(game));
    REQUIRE_NOTHROW(state.draw(game));
    REQUIRE_NOTHROW(state.update(game));
}
