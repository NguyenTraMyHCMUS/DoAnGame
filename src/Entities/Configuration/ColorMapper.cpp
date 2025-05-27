// ColorMapper.cpp
#include "ColorMapper.h"
#include "ConfigurationManager.h"
#include "../TetrominoConstants.h"

ColorMapper& ColorMapper::getInstance() {
    static ColorMapper instance;
    return instance;
}

ColorMapper::ColorMapper() : _initialized(false) {
    loadColors();  
}

void ColorMapper::loadColors() {
    auto& config = ConfigurationManager::getInstance();
    
    // Load from config or use defaults
    _typeToColor["I"] = config.getInt("i_color", TetrominoConstants::I_COLOR);
    _typeToColor["J"] = config.getInt("j_color", TetrominoConstants::J_COLOR);
    _typeToColor["L"] = config.getInt("l_color", TetrominoConstants::L_COLOR);
    _typeToColor["O"] = config.getInt("o_color", TetrominoConstants::O_COLOR);
    _typeToColor["S"] = config.getInt("s_color", TetrominoConstants::S_COLOR);
    _typeToColor["T"] = config.getInt("t_color", TetrominoConstants::T_COLOR);
    _typeToColor["Z"] = config.getInt("z_color", TetrominoConstants::Z_COLOR);
    
    _initialized = true;
}

int ColorMapper::getColor(const std::string& type) const {
    auto it = _typeToColor.find(type);
    return (it != _typeToColor.end()) ? it->second : TetrominoConstants::I_COLOR;
}

bool ColorMapper::hasColor(const std::string& type) const {
    return _typeToColor.find(type) != _typeToColor.end();
}

void ColorMapper::setColor(const std::string& type, int color) {
    _typeToColor[type] = color;
}

void ColorMapper::updateFromConfig() {
    _typeToColor.clear();
    loadColors();
}

