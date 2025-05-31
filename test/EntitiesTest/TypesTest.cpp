#include "catch.hpp"
#include "../../Entities/Types/ITetromino.h"
#include "../../Entities/Types/JTetromino.h"
#include "../../Entities/Types/LTetromino.h"
#include "../../Entities/Types/OTetromino.h"
#include "../../Entities/Types/STetromino.h"
#include "../../Entities/Types/TTetromino.h"
#include "../../Entities/Types/ZTetromino.h"

TEST_CASE("ITetromino basic functionality", "[ITetromino]") {
    ITetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "I");
}

TEST_CASE("JTetromino basic functionality", "[JTetromino]") {
    JTetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "J");
}

TEST_CASE("LTetromino basic functionality", "[LTetromino]") {
    LTetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "L");
}

TEST_CASE("OTetromino basic functionality", "[OTetromino]") {
    OTetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "O");
}

TEST_CASE("STetromino basic functionality", "[STetromino]") {
    STetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "S");
}

TEST_CASE("TTetromino basic functionality", "[TTetromino]") {
    TTetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "T");
}

TEST_CASE("ZTetromino basic functionality", "[ZTetromino]") {
    ZTetromino tetromino;
    REQUIRE_NOTHROW(tetromino.initializeShape());
    REQUIRE_NOTHROW(tetromino.rotate());
    auto clone = tetromino.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == tetromino.getTypeName());
    REQUIRE(tetromino.getTypeName() == "Z");
}
