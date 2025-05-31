#include "catch.hpp"
#include "../../Entities/Types/ITetromino.h"
#include "../../Entities/Types/JTetromino.h"
#include "../../Entities/Types/LTetromino.h"
#include "../../Entities/Types/OTetromino.h"
#include "../../Entities/Types/STetromino.h"
#include "../../Entities/Types/TTetromino.h"
#include "../../Entities/Types/ZTetromino.h"

TEST_CASE("ITetromino basic functionality", "[ITetromino]") {
    ITetromino i;
    REQUIRE_NOTHROW(i.initializeShape());
    REQUIRE_NOTHROW(i.rotate());
    auto clone = i.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == i.getTypeName());
    REQUIRE(i.getTypeName() == "I");
}

TEST_CASE("JTetromino basic functionality", "[JTetromino]") {
    JTetromino j;
    REQUIRE_NOTHROW(j.initializeShape());
    REQUIRE_NOTHROW(j.rotate());
    auto clone = j.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == j.getTypeName());
    REQUIRE(j.getTypeName() == "J");
}

TEST_CASE("LTetromino basic functionality", "[LTetromino]") {
    LTetromino l;
    REQUIRE_NOTHROW(l.initializeShape());
    REQUIRE_NOTHROW(l.rotate());
    auto clone = l.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == l.getTypeName());
    REQUIRE(l.getTypeName() == "L");
}

TEST_CASE("OTetromino basic functionality", "[OTetromino]") {
    OTetromino o;
    REQUIRE_NOTHROW(o.initializeShape());
    REQUIRE_NOTHROW(o.rotate());
    auto clone = o.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == o.getTypeName());
    REQUIRE(o.getTypeName() == "O");
}

TEST_CASE("STetromino basic functionality", "[STetromino]") {
    STetromino s;
    REQUIRE_NOTHROW(s.initializeShape());
    REQUIRE_NOTHROW(s.rotate());
    auto clone = s.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == s.getTypeName());
    REQUIRE(s.getTypeName() == "S");
}

TEST_CASE("TTetromino basic functionality", "[TTetromino]") {
    TTetromino t;
    REQUIRE_NOTHROW(t.initializeShape());
    REQUIRE_NOTHROW(t.rotate());
    auto clone = t.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == t.getTypeName());
    REQUIRE(t.getTypeName() == "T");
}

TEST_CASE("ZTetromino basic functionality", "[ZTetromino]") {
    ZTetromino z;
    REQUIRE_NOTHROW(z.initializeShape());
    REQUIRE_NOTHROW(z.rotate());
    auto clone = z.clone();
    REQUIRE(clone != nullptr);
    REQUIRE(clone->getTypeName() == z.getTypeName());
    REQUIRE(z.getTypeName() == "Z");
}
