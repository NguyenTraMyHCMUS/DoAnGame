#include "catch.hpp"
#include "../Logic/ScoreManager.h"
#include "../Logic/LevelManager.h"
#include "../Logic/GameLogic.h"
#include "../Entities/Field.h"
#include "../Entities/Tetromino.h"
#include "../Entities/NextTetrominoPreview.h"

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
    void generateNext() { }
    std::unique_ptr<Tetromino> getNext() { return std::make_unique<DummyTetromino>(); }
    std::unique_ptr<Tetromino> cloneNext() const { return std::make_unique<DummyTetromino>(); }
    void draw(sf::RenderWindow&, sf::Sprite&) { }
    const Tetromino* getNextTetromino() const { return nullptr; }
    void reset() { }
};

TEST_CASE("ScoreManager hoạt động đúng", "[ScoreManager]") {
    ScoreManager score_manager;
    REQUIRE(score_manager.getScore() == 0);

    score_manager.addScore(100);
    REQUIRE(score_manager.getScore() == 100);

    int old_high = score_manager.getHighScore();
    score_manager.addScore(1000);
    score_manager.submitScore("TestUser");
    REQUIRE(score_manager.getHighScore() >= old_high);

    score_manager.reset();
    REQUIRE(score_manager.getScore() == 0);

    // Test getTopScores trả về vector có size <= 3
    auto top_scores = score_manager.getTopScores(3);
    REQUIRE(top_scores.size() <= 3);
}

TEST_CASE("LevelManager hoạt động đúng", "[LevelManager]") {
    LevelManager level_manager;
    REQUIRE(level_manager.getLevel() == 1);
    REQUIRE(level_manager.getLinesCleared() == 0);

    level_manager.addClearedLines(5);
    REQUIRE(level_manager.getLinesCleared() == 5);

    level_manager.increaseLevel();
    REQUIRE(level_manager.getLevel() == 2);

    level_manager.reset();
    REQUIRE(level_manager.getLevel() == 1);
    REQUIRE(level_manager.getLinesCleared() == 0);

    level_manager.addClearedLines(10);
    level_manager.resetLinesCleared();
    REQUIRE(level_manager.getLinesCleared() == 0);
}

TEST_CASE("GameLogic khởi tạo và reset", "[GameLogic]") {
    Field field;
    std::unique_ptr<Tetromino> tetromino = std::make_unique<DummyTetromino>();
    DummyPreview preview;
    ScoreManager score_manager;
    LevelManager level_manager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, score_manager, level_manager, delay);

    // Test resetGame không gây lỗi
    logic.resetGame();
}

TEST_CASE("GameLogic update di chuyển ngang", "[GameLogic]") {
    Field field;
    std::unique_ptr<Tetromino> tetromino = std::make_unique<DummyTetromino>();
    DummyPreview preview;
    ScoreManager score_manager;
    LevelManager level_manager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, score_manager, level_manager, delay);

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
    ScoreManager score_manager;
    LevelManager level_manager;
    float delay = 0.5f;

    GameLogic logic(field, tetromino, preview, score_manager, level_manager, delay);

    // Xoay khối
    bool result = logic.rotateTetrominoIfPossible(true);
    REQUIRE(result == true);
}
