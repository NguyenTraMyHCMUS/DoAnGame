#include "catch.hpp"
#include "../../Entities/Factories/TetrominoFactory.h"
#include "../../Entities/Factories/RotatorFactory.h"
#include "../../Entities/Factories/DefaultTetrominoComponentFactory.h"
#include "../../Entities/Point.h"

TEST_CASE("TetrominoFactory createTetromino by id and name", "[TetrominoFactory]") {
    
    for (int i = 0; i < TetrominoFactory::getAvailableTypeCount(); ++i) {
        auto tet = TetrominoFactory::createTetromino(i);
        REQUIRE(tet != nullptr);
        REQUIRE(TetrominoFactory::isValidType(i));
    }
    REQUIRE_FALSE(TetrominoFactory::isValidType(-1));
    REQUIRE_FALSE(TetrominoFactory::isValidType(100));

    std::vector<std::string> names = {"I", "J", "L", "O", "S", "T", "Z"};
    for (const auto& name : names) {
        auto tet = TetrominoFactory::createTetromino(name);
        REQUIRE(tet != nullptr);
        REQUIRE(TetrominoFactory::isValidName(name));
    }
    REQUIRE_FALSE(TetrominoFactory::isValidName("X"));
}

TEST_CASE("TetrominoFactory createRandomTetromino", "[TetrominoFactory]") {
    auto tet = TetrominoFactory::createRandomTetromino();
    REQUIRE(tet != nullptr);
}

TEST_CASE("TetrominoFactory getTypeInfo and getAllTypeInfo", "[TetrominoFactory]") {
    auto infos = TetrominoFactory::getAllTypeInfo();
    REQUIRE(!infos.empty());
    for (size_t i = 0; i < infos.size(); ++i) {
        auto info = TetrominoFactory::getTypeInfo(static_cast<int>(i));
        REQUIRE(info != nullptr);
        auto infoByName = TetrominoFactory::getTypeInfo(infos[i].name);
        REQUIRE(infoByName != nullptr);
    }
    REQUIRE(TetrominoFactory::getTypeInfo(-1) == nullptr);
    REQUIRE(TetrominoFactory::getTypeInfo("X") == nullptr);
}

TEST_CASE("TetrominoFactory createTetrominoWithMetadata", "[TetrominoFactory]") {
    auto tet = TetrominoFactory::createTetrominoWithMetadata(0);
    REQUIRE(tet != nullptr);
    tet = TetrominoFactory::createTetrominoWithMetadata("I");
    REQUIRE(tet != nullptr);
}

TEST_CASE("RotatorFactory createRotator returns not null for valid types", "[RotatorFactory]") {
    std::vector<std::string> names = {"I", "J", "L", "S", "T", "Z"};
    for (const auto& name : names) {
        auto rot = RotatorFactory::createRotator(name);
        INFO("Type: " << name);
        REQUIRE(rot != nullptr);
    }
    // O không cần rotator, phải trả về nullptr
    auto rotO = RotatorFactory::createRotator("O");
    REQUIRE(rotO == nullptr);

    auto rot = RotatorFactory::createRotator("X");
    REQUIRE(rot == nullptr);
}

TEST_CASE("DefaultTetrominoComponentFactory create all components", "[DefaultTetrominoComponentFactory]") {
    DefaultTetrominoComponentFactory factory;
    Point blocks[4] = { {0,0}, {1,0}, {2,0}, {3,0} };

    auto validator = factory.createValidator(blocks);
    REQUIRE(validator != nullptr);

    auto renderer = factory.createRenderer(blocks, 18);
    REQUIRE(renderer != nullptr);

    auto locker = factory.createLocker(blocks);
    REQUIRE(locker != nullptr);

    auto state = factory.createState(blocks);
    REQUIRE(state != nullptr);

    auto movement = factory.createMovement(blocks);
    REQUIRE(movement != nullptr);

    auto rotator = factory.createRotator("I");
    REQUIRE(rotator != nullptr);
}
