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
    ResourceManager resource_manager;
    // Nếu loadResources() chưa implement, có thể bỏ qua hoặc sửa lại test này
    REQUIRE(resource_manager.loadResources() == true);
}

TEST_CASE("ResourceManager texture setters/getters", "[ResourceManager]") {
    ResourceManager resource_manager;
    sf::Texture texture;
    resource_manager.setT1(texture);
    REQUIRE_NOTHROW(resource_manager.getT1());
    resource_manager.setT2(texture);
    REQUIRE_NOTHROW(resource_manager.getT2());
    resource_manager.setT3(texture);
    REQUIRE_NOTHROW(resource_manager.getT3());
}

TEST_CASE("ResourceManager sprite setters/getters", "[ResourceManager]") {
    ResourceManager resource_manager;
    sf::Sprite sprite;
    resource_manager.setSprite(sprite);
    REQUIRE_NOTHROW(resource_manager.getSprite());
    resource_manager.setBackground(sprite);
    REQUIRE_NOTHROW(resource_manager.getBackground());
    resource_manager.setFrame(sprite);
    REQUIRE_NOTHROW(resource_manager.getFrame());
}

// GameRenderer tests
TEST_CASE("GameRenderer can be constructed and destructed", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(50, 50), "Test");
    ResourceManager resource_manager;
    REQUIRE_NOTHROW(GameRenderer(window, resource_manager));
}

TEST_CASE("GameRenderer draw functions", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    ResourceManager resource_manager;
    GameRenderer renderer(window, resource_manager);

    DummyField field;
    DummyTetromino tetromino;
    DummyNextPreview preview;
    DummyScoreManager score_manager;
    DummyLevelManager level_manager;

    renderer.drawBackground();
    renderer.drawField(field);
    renderer.drawTetromino(&tetromino);
    renderer.drawInfoBox("Score", "1000", 10.0f);
    renderer.drawNextPreview(preview);
    renderer.drawStats(score_manager, level_manager);
    renderer.drawFrame();
    SUCCEED();
}

TEST_CASE("GameRenderer clear and display", "[GameRenderer]") {
    sf::RenderWindow window(sf::VideoMode(100, 100), "Test");
    ResourceManager resource_manager;
    GameRenderer renderer(window, resource_manager);
    renderer.clear();
    renderer.display();
    SUCCEED();
}
