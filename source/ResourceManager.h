#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class ResourceManager
 * @brief Quản lý tài nguyên đồ họa của trò chơi (Single Responsibility)
 */
class ResourceManager {
private:
    sf::Texture t1, t2, t3;
    sf::Sprite s, background, frame;

public:
    ResourceManager();
    bool loadResources();

    const sf::Texture& getT1() const;
    void setT1(const sf::Texture& texture);

    const sf::Texture& getT2() const;
    void setT2(const sf::Texture& texture);

    const sf::Texture& getT3() const;
    void setT3(const sf::Texture& texture);

    sf::Sprite& getSprite();
    void setSprite(const sf::Sprite& sprite);

    const sf::Sprite& getBackground() const;
    void setBackground(const sf::Sprite& sprite);

    const sf::Sprite& getFrame() const;
    void setFrame(const sf::Sprite& sprite);
};

#endif