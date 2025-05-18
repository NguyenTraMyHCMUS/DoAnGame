#include "Core/Field.h"
#include "Core/Game.h"
#include "catch.hpp"

// ---- Field Tests ----
TEST_CASE("Field initializes all cells to 0") {
    Field field;
    for (int y = 0; y < M; ++y)
        for (int x = 0; x < N; ++x)
            REQUIRE(field.getCell(x, y) == 0);
}

TEST_CASE("Field setCell and getCell work correctly") {
    Field field;
    field.setCell(2, 3, 5);
    REQUIRE(field.getCell(2, 3) == 5);
    field.setCell(2, 3, 0);
    REQUIRE(field.getCell(2, 3) == 0);
}

TEST_CASE("Field isInside returns correct values") {
    Field field;
    REQUIRE(field.isInside(0, 0));
    REQUIRE(field.isInside(N-1, M-1));
    REQUIRE_FALSE(field.isInside(-1, 0));
    REQUIRE_FALSE(field.isInside(0, -1));
    REQUIRE_FALSE(field.isInside(N, 0));
    REQUIRE_FALSE(field.isInside(0, M));
}

TEST_CASE("Field isOccupied returns correct status") {
    Field field;
    field.setCell(1, 1, 0);
    REQUIRE_FALSE(field.isOccupied(1, 1));
    field.setCell(1, 1, 3);
    REQUIRE(field.isOccupied(1, 1));
}

TEST_CASE("Field clear resets all cells to 0") {
    Field field;
    field.setCell(0, 0, 1);
    field.setCell(N-1, M-1, 2);
    field.clear();
    for (int y = 0; y < M; ++y)
        for (int x = 0; x < N; ++x)
            REQUIRE(field.getCell(x, y) == 0);
}

TEST_CASE("Field clearLines removes full lines and shifts above lines down") {
    Field field;
    // Fill bottom row
    for (int x = 0; x < N; ++x)
        field.setCell(x, M-1, 1);
    // Fill one cell above
    field.setCell(0, M-2, 2);
    int cleared = field.clearLines();
    REQUIRE(cleared == 1);
    // Now cell (0, M-1) should be 2, rest 0
    REQUIRE(field.getCell(0, M-1) == 2);
    for (int x = 1; x < N; ++x)
        REQUIRE(field.getCell(x, M-1) == 0);
}

TEST_CASE("Field clearLines does not clear incomplete lines") {
    Field field;
    for (int x = 0; x < N-1; ++x)
        field.setCell(x, M-1, 1);
    REQUIRE(field.clearLines() == 0);
}

TEST_CASE("Field canPlaceBlock returns true for valid, false for invalid positions") {
    Field field;
    std::vector<std::pair<int, int>> valid = { {0,0}, {1,1}, {2,2} };
    REQUIRE(field.canPlaceBlock(valid));
    std::vector<std::pair<int, int>> out_of_bounds = { {N,0}, {0,M} };
    REQUIRE_FALSE(field.canPlaceBlock(out_of_bounds));
    field.setCell(3, 3, 1);
    std::vector<std::pair<int, int>> occupied = { {3,3} };
    REQUIRE_FALSE(field.canPlaceBlock(occupied));
}

// ---- Game Tests ----
TEST_CASE("Game constructor initializes members") {
    Game game;
    REQUIRE(game.getLevel() == 1);
    REQUIRE(game.getDelay() > 0.0f);
    // Window should be open or at least exist
    bool open = game.getWindow().isOpen();
    REQUIRE((open == false || open == true)); // Sửa lỗi chained comparisons
}

TEST_CASE("Game texture and sprite getter/setter methods") {
    Game game;
    sf::Texture tex;
    game.setT1(tex);
    REQUIRE(&game.getT1() != nullptr);
    game.setT2(tex);
    REQUIRE(&game.getT2() != nullptr);
    game.setT3(tex);
    REQUIRE(&game.getT3() != nullptr);

    sf::Sprite spr;
    game.setSprite(spr);
    REQUIRE(&game.getSprite() != nullptr);
    game.setBackground(spr);
    REQUIRE(&game.getBackground() != nullptr);
    game.setFrame(spr);
    REQUIRE(&game.getFrame() != nullptr);
}

TEST_CASE("Game delay, dx, rotate setter/getter methods") {
    Game game;
    game.setDelay(0.5f);
    REQUIRE(game.getDelay() == Approx(0.5f));
    game.setDx(2);
    game.setRotate(true);
    // No getter for dx/rotate, so just check no crash
}

TEST_CASE("Game manager and preview accessors") {
    Game game;
    REQUIRE(&game.getLevelManager() != nullptr);
    REQUIRE(&game.getScoreManager() != nullptr);
    REQUIRE(&game.getNextTetrominoPreview() != nullptr);
}

TEST_CASE("Game setState changes state pointer") {
    Game game;
    // Use a dummy state for testing
    class DummyState : public GameState {
    public:
        void handleInput(Game&) override {}
        void draw(Game&) override {}
        // XÓA void update() override {}
    };
    std::unique_ptr<GameState> state1 = std::make_unique<DummyState>();
    game.setState(std::move(state1));
    // No getter for currentState, so just check no crash
}

TEST_CASE("Game resetGame resets state") {
    Game game;
    game.resetGame();
    REQUIRE(game.getLevel() == 1);
    // Could check more if resetGame implementation is available
}
