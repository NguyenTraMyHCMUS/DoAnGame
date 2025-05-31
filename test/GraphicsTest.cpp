#include "catch.hpp"
#include <SFML/Graphics.hpp>
#include "../Graphics/ResourceManager.h"
#include "../Graphics/GameRenderer.h"

// Dummy classes cho test
class DummyField : public Field { public: DummyField() : Field() {} };
class DummyTetromino : public Tetromino {
public:
    DummyTetromino() : Tetromino() {}
    void initializeShape() override {}
    std::string getTypeName() const override { return "Dummy"; }
    std::unique_ptr<Tetromino> clone() const override { return std::make_unique<DummyTetromino>(*this); }
};
class DummyScoreManager : public ScoreManager { public: DummyScoreManager() : ScoreManager() {} };
class DummyLevelManager : public LevelManager { public: DummyLevelManager() : LevelManager() {} };
class DummyNextPreview : public NextTetrominoPreview { public: DummyNextPreview() : NextTetrominoPreview() {} };

// ResourceManager tests
TEST_CASE("ResourceManager loads resources", "[ResourceManager]") {
    ResourceManager rm;
    // Nếu loadResources() chưa implement, có thể bỏ qua hoặc sửa lại test này
    REQUIRE(rm.loadResources() == true);
}

TEST_CASE("ResourceManager texture setters/getters", "[ResourceManager]") {
    ResourceManager rm;
    sf::Texture tex;
    rm.setT1(tex);
    REQUIRE_NOTHROW(rm.getT1());
    rm.setT2(tex);
    REQUIRE_NOTHROW(rm.getT2());
    rm.setT3(tex);
    REQUIRE_NOTHROW(rm.getT3());
}

TEST_CASE("ResourceManager sprite setters/getters", "[ResourceManager]") {
    ResourceManager rm;
    sf::Sprite sprite;
    rm.setSprite(sprite);
    REQUIRE_NOTHROW(rm.getSprite());
    rm.setBackground(sprite);
    REQUIRE_NOTHROW(rm.getBackground());
    rm.setFrame(sprite);
    REQUIRE_NOTHROW(rm.getFrame());
}

// GameRenderer tests
TEST_CASE("GameRenderer can be constructed and destructed", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(50, 50), "Test");
    ResourceManager rm;
    REQUIRE_NOTHROW(GameRenderer(window, rm));
}

TEST_CASE("GameRenderer draw functions", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    ResourceManager rm;
    GameRenderer renderer(window, rm);

    DummyField field;
    DummyTetromino tetromino;
    DummyNextPreview preview;
    DummyScoreManager score;
    DummyLevelManager level;

    renderer.drawBackground();
    renderer.drawField(field);
    renderer.drawTetromino(&tetromino);
    renderer.drawInfoBox("Score", "1000", 10.0f);
    renderer.drawNextPreview(preview);
    renderer.drawStats(score, level);
    renderer.drawFrame();
    SUCCEED();
}

TEST_CASE("GameRenderer clear and display", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    ResourceManager rm;
    GameRenderer renderer(window, rm);
    renderer.clear();
    renderer.display();
    SUCCEED();
}
