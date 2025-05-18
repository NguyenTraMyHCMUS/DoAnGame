#include "catch.hpp"
#include "States/LevelManager.h"
#include "Utils/ScoreManager.h"

TEST_CASE("ScoreManager nang cao") {
    std::remove("highscore.txt");

    SECTION("Khong tang high score neu thap hon") {
        ScoreManager sm;
        sm.addScore(200);
        sm.reset();
        sm.addScore(50);
        REQUIRE(sm.getHighScore() == 200);
    }

    SECTION("High score luu ra file va doc lai dung") {
        {
            ScoreManager sm;
            sm.addScore(321);
            // sm sẽ tự lưu khi ra khỏi scope
        }
        ScoreManager sm2;
        REQUIRE(sm2.getHighScore() >= 321);
    }
}
