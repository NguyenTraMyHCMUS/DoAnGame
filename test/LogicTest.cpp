#include "catch.hpp"
#include "../Logic/ScoreManager.h"
#include "../Logic/LevelManager.h"
#include "../Logic/GameLogic.h"
#include "../Entities/Field.h"
#include "../Entities/Tetromino.h"
#include "../States/NextTetrominoPreview.h"

// Dummy Tetromino: override all pure virtual functions
class DummyTetromino : public Tetromino {
public:
    DummyTetromino() : Tetromino() {}
    void initializeShape() override {}
    std::string getTypeName() const override { return "Dummy"; }
    std::unique_ptr<Tetromino> clone() const override { return std::make_unique<DummyTetromino>(); }
};

// Dummy NextTetrominoPreview: override all pure virtual functions
class DummyPreview : public NextTetrominoPreview {
public:
    DummyPreview() : NextTetrominoPreview() {}
    void generateNext() {}
    std::unique_ptr<Tetromino> getNext() { return std::make_unique<DummyTetromino>(); }
    std::unique_ptr<Tetromino> cloneNext() const { return std::make_unique<DummyTetromino>(); }
    void draw(sf::RenderWindow&, sf::Sprite&) {}
    const Tetromino* getNextTetromino() const { return nullptr; }
    void reset() {}
};

TEST_CASE("ScoreManager hoạt động đúng", "[ScoreManager]") {
    ScoreManager sm;
    REQUIRE(sm.getScore() == 0);

    sm.addScore(100);
    REQUIRE(sm.getScore() == 100);

    int oldHigh = sm.getHighScore();
    sm.addScore(1000);
    sm.submitScore("TestUser");
    REQUIRE(sm.getHighScore() >= oldHigh);

    sm.reset();
    REQUIRE(sm.getScore() == 0);
}

TEST_CASE("LevelManager hoạt động đúng", "[LevelManager]") {
    LevelManager lm;
    REQUIRE(lm.getLevel() == 1);
    REQUIRE(lm.getLinesCleared() == 0);

    lm.addClearedLines(5);
    REQUIRE(lm.getLinesCleared() == 5);

    lm.increaseLevel();
    REQUIRE(lm.getLevel() == 2);

    lm.reset();
    REQUIRE(lm.getLevel() == 1);
    REQUIRE(lm.getLinesCleared() == 0);

    lm.addClearedLines(10);
    lm.resetLinesCleared();
    REQUIRE(lm.getLinesCleared() == 0);
}

TEST_CASE("GameLogic khởi tạo và reset", "[GameLogic]") {
    Field field;
    std::unique_ptr<Tetromino> tetromino = std::make_unique<DummyTetromino>();
    DummyPreview preview;
    ScoreManager scoreManager;
    LevelManager levelManager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, scoreManager, levelManager, delay);

    // Test resetGame không gây lỗi
    logic.resetGame();
}

TEST_CASE("GameLogic update di chuyển ngang", "[GameLogic]") {
    Field field;
    std::unique_ptr<Tetromino> tetromino = std::make_unique<DummyTetromino>();
    DummyPreview preview;
    ScoreManager scoreManager;
    LevelManager levelManager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, scoreManager, levelManager, delay);

    // Di chuyển sang phải
    bool result = logic.moveTetrominoHorizontally(1);
    REQUIRE(result == true);

    // Di chuyển sang trái
    result = logic.moveTetrominoHorizontally(-1);
    REQUIRE(result == true);
}

TEST_CASE("GameLogic update xoay khối", "[GameLogic]") {
    Field field;
    std::unique_ptr<Tetromino> tetromino = std::make_unique<DummyTetromino>();
    DummyPreview preview;
    ScoreManager scoreManager;
    LevelManager levelManager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, scoreManager, levelManager, delay);

    // Xoay khối
    bool result = logic.rotateTetrominoIfPossible(true);
    REQUIRE(result == true);
}
