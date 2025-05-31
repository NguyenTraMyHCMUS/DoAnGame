#include "catch.hpp"
#include "../../Entities/Configuration/ConfigurationManager.h"
#include "../../Entities/Configuration/ColorMapper.h"

TEST_CASE("ConfigurationManager singleton and int/string set/get", "[ConfigurationManager]") {
    ConfigurationManager& config_manager = ConfigurationManager::getInstance();

    config_manager.setInt("test_int", 123);
    REQUIRE(config_manager.getInt("test_int") == 123);
    REQUIRE(config_manager.getInt("not_exist", 42) == 42);

    config_manager.setString("test_str", "hello");
    REQUIRE(config_manager.getString("test_str") == "hello");
    REQUIRE(config_manager.getString("not_exist", "default") == "default");
}

TEST_CASE("ColorMapper singleton and color mapping", "[ColorMapper]") {
    ColorMapper& color_mapper = ColorMapper::getInstance();

    // Thiết lập và kiểm tra màu cho type "I"
    color_mapper.setColor("I", 5);
    REQUIRE(color_mapper.getColor("I") == 5);
    REQUIRE(color_mapper.hasColor("I"));

    // Kiểm tra type không tồn tại
    REQUIRE_FALSE(color_mapper.hasColor("XYZ"));
}

TEST_CASE("ColorMapper updateFromConfig does not throw", "[ColorMapper]") {
    ColorMapper& color_mapper = ColorMapper::getInstance();
    REQUIRE_NOTHROW(color_mapper.updateFromConfig());
}
