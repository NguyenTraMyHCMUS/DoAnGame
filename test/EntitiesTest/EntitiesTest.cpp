#include "catch.hpp"
#include "../../Entities/TetrominoConstants.h"
#include "../../Entities/Point.h"
#include "../../Entities/Field.h"
#include "../../Entities/Tetromino.h"

// Test TetrominoConstants
TEST_CASE("TetrominoConstants values are correct", "[TetrominoConstants]") {
    REQUIRE(TetrominoConstants::DEFAULT_CELL_SIZE == 18);
    REQUIRE(TetrominoConstants::I_COLOR == 1);
    REQUIRE(TetrominoConstants::J_COLOR == 2);
    REQUIRE(TetrominoConstants::L_COLOR == 3);
    REQUIRE(TetrominoConstants::O_COLOR == 4);
    REQUIRE(TetrominoConstants::S_COLOR == 5);
    REQUIRE(TetrominoConstants::T_COLOR == 6);
    REQUIRE(TetrominoConstants::Z_COLOR == 7);
    REQUIRE(TetrominoConstants::DEFAULT_FALL_SPEED == Approx(0.3f));
    REQUIRE(TetrominoConstants::GRID_WIDTH == 10);
    REQUIRE(TetrominoConstants::GRID_HEIGHT == 20);
}

// Test Point
TEST_CASE("Point basic functionality", "[Point]") {
    Point p1;
    REQUIRE(p1.getX() == 0);
    REQUIRE(p1.getY() == 0);

    Point p2(5, 7);
    REQUIRE(p2.getX() == 5);
    REQUIRE(p2.getY() == 7);

    p2.setX(10);
    p2.setY(20);
    REQUIRE(p2.getX() == 10);
    REQUIRE(p2.getY() == 20);
}

// Test Field
TEST_CASE("Field basic operations", "[Field]") {
    Field field;
    REQUIRE(field.getHeight() == 20);
    REQUIRE(field.getWidth() == 10);

    // Test set/get cell
    field.setCell(1, 2, 5);
    REQUIRE(field.getCell(1, 2) == 5);

    // Test isInside
    REQUIRE(field.isInside(0, 0));
    REQUIRE(field.isInside(9, 19));
    REQUIRE_FALSE(field.isInside(-1, 0));
    REQUIRE_FALSE(field.isInside(10, 0));
    REQUIRE_FALSE(field.isInside(0, 20));

    // Test isOccupied
    REQUIRE(field.isOccupied(1, 2));
    REQUIRE_FALSE(field.isOccupied(0, 0));

    // Test clear
    field.clear();
    REQUIRE(field.getCell(1, 2) == 0);

    // Test canPlaceBlock
    std::vector<std::pair<int, int>> blocks = {{0,0}, {1,0}, {2,0}, {3,0}};
    REQUIRE(field.canPlaceBlock(blocks));
}

// Dummy Tetromino for abstract class test
class DummyTetromino : public Tetromino {
public:
    DummyTetromino() : Tetromino() {}
    void initializeShape() override {}
    std::string getTypeName() const override { return "Dummy"; }
    std::unique_ptr<Tetromino> clone() const override { return std::make_unique<DummyTetromino>(); }
};

TEST_CASE("Tetromino base class interface", "[Tetromino]") {
    DummyTetromino tet;
    tet.setCellSize(20);
    REQUIRE(tet.getColor() == 0);
    tet.setColor(5);
    REQUIRE(tet.getColor() == 5);

    // Test getBlocks, getX, getY
    const Point* blocks = tet.getBlocks();
    for (int i = 0; i < 4; ++i) {
        REQUIRE(blocks[i].getX() == tet.getX(i));
        REQUIRE(blocks[i].getY() == tet.getY(i));
    }

    // Test backup/restore state
    tet.backupState();
    tet.restoreState();
}
