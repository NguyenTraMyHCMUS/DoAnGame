#ifndef COLOR_MAPPER_H
#define COLOR_MAPPER_H

#include <string>
#include <map>
#include "../Interface/IColorMapper.h"

/**
 * @class ColorMapper
 * @brief Maps Tetromino types to colors using configuration
 */
class ColorMapper : public IColorMapper {
private:
    std::map<std::string, int> _typeToColor;
    bool _initialized;
    
    void loadColors();
    
    ColorMapper();
public:
    /**
     * @brief Get color for Tetromino type
     * @param type Type name ("I", "J", "L", "O", "S", "T", "Z")
     * @return Color index for texture mapping
     */
    static ColorMapper& getInstance();

    int getColor(const std::string& type) const override;
    
    /**
     * @brief Check if type has valid color mapping
     */
    bool hasColor(const std::string& type) const override;
    
    /**
     * @brief Update color mapping (for future config file support)
     */
    void setColor(const std::string& type, int color) override;

    /**
     * @brief Update color mapping from configuration
     * 
     * This method will read the configuration file and update the color mappings.
     * It should be called at the start of the application to ensure colors are set correctly.
     */
    void updateFromConfig() override;
};

#endif