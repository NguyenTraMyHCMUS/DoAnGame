#include "catch.hpp"
#include "../../Entities/Configuration/ConfigurationManager.h"
#include "../../Entities/Configuration/ColorMapper.h"

TEST_CASE("ConfigurationManager singleton and int/string set/get", "[ConfigurationManager]") {
    ConfigurationManager& config = ConfigurationManager::getInstance();

    config.setInt("test_int", 123);
    REQUIRE(config.getInt("test_int") == 123);
    REQUIRE(config.getInt("not_exist", 42) == 42);

    config.setString("test_str", "hello");
    REQUIRE(config.getString("test_str") == "hello");
    REQUIRE(config.getString("not_exist", "default") == "default");
}

TEST_CASE("ColorMapper singleton and color mapping", "[ColorMapper]") {
    ColorMapper& mapper = ColorMapper::getInstance();

    // Thiết lập và kiểm tra màu cho type "I"
    mapper.setColor("I", 5);
    REQUIRE(mapper.getColor("I") == 5);
    REQUIRE(mapper.hasColor("I"));

    // Kiểm tra type không tồn tại
    REQUIRE_FALSE(mapper.hasColor("XYZ"));
}

TEST_CASE("ColorMapper updateFromConfig does not throw", "[ColorMapper]") {
    ColorMapper& mapper = ColorMapper::getInstance();
    REQUIRE_NOTHROW(mapper.updateFromConfig());
}
