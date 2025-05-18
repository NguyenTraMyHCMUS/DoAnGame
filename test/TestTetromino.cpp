#include "Tetromino/TetrominoFactory.h"
#include "Core/Field.h"
#include "catch.hpp"

TEST_CASE("TetrominoFactory tạo đủ 7 loại khối", "[TetrominoFactory]") {
    for (int type = 0; type < 7; ++type) {
        auto tet = TetrominoFactory::createTetromino(type);
        REQUIRE(tet != nullptr);
    }
}

TEST_CASE("Tetromino: set/get color", "[Tetromino]") {
    auto tet = TetrominoFactory::createTetromino(0);
    tet->setColor(4);
    REQUIRE(tet->getColor() == 4);
}

TEST_CASE("Tetromino: backup và restore trạng thái", "[Tetromino]") {
    auto tet = TetrominoFactory::createTetromino(0);
    const Point* before = tet->getBlocks();
    tet->backupState();
    tet->move(2);
    tet->restoreState();
    const Point* after = tet->getBlocks();
    for (int i = 0; i < 4; ++i) {
        REQUIRE(before[i]._x == after[i]._x);
        REQUIRE(before[i]._y == after[i]._y);
    }
}

TEST_CASE("Tetromino: move và fall", "[Tetromino]") {
    auto tet = TetrominoFactory::createTetromino(0);
    int old_x = tet->getBlocks()[0]._x;
    tet->move(1);
    REQUIRE(tet->getBlocks()[0]._x == old_x + 1);

    int old_y = tet->getBlocks()[0]._y;
    tet->fall();
    REQUIRE(tet->getBlocks()[0]._y == old_y + 1);
}

TEST_CASE("Tetromino: clone tạo ra bản sao độc lập", "[Tetromino]") {
    auto tet = TetrominoFactory::createTetromino(0);
    tet->move(1);
    auto clone = tet->clone();
    for (int i = 0; i < 4; ++i) {
        REQUIRE(tet->getBlocks()[i]._x == clone->getBlocks()[i]._x);
        REQUIRE(tet->getBlocks()[i]._y == clone->getBlocks()[i]._y);
    }
}

TEST_CASE("Tetromino: kiểm tra hợp lệ trên Field", "[Tetromino]") {
    Field field;
    auto tet = TetrominoFactory::createTetromino(0);
    REQUIRE(tet->isValid(field));
    // Đặt một ô bị chiếm
    field.setCell(tet->getBlocks()[0]._x, tet->getBlocks()[0]._y, 1);
    REQUIRE_FALSE(tet->isValid(field));
}

TEST_CASE("Tetromino: lock vào Field", "[Tetromino]") {
    Field field;
    auto tet = TetrominoFactory::createTetromino(0);
    tet->lock(field);
    for (int i = 0; i < 4; ++i) {
        REQUIRE(field.isOccupied(tet->getBlocks()[i]._x, tet->getBlocks()[i]._y));
    }
}

TEST_CASE("TetrominoFactory: tạo khối ngẫu nhiên", "[TetrominoFactory]") {
    auto tet = TetrominoFactory::createRandomTetromino();
    REQUIRE(tet != nullptr);
}
