#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
    // Constructor
}

bool ResourceManager::loadResources() {
    bool success = true;
    
    if (!t1.loadFromFile("assets/images/tiles.png")) {
        std::cerr << "Failed to load tiles.png" << std::endl;
        success = false;
    }
    
    if (!t2.loadFromFile("assets/images/background.png")) {
        std::cerr << "Failed to load background.png" << std::endl;
        success = false;
    }
    
    if (!t3.loadFromFile("assets/images/frame.png")) {
        std::cerr << "Failed to load frame.png" << std::endl;
        success = false;
    }
    
    s.setTexture(t1);
    background.setTexture(t2);
    frame.setTexture(t3);
    
    return success;
}

const sf::Texture& ResourceManager::getT1() const {
    return t1;
}

void ResourceManager::setT1(const sf::Texture& texture) {
    t1 = texture;
}

const sf::Texture& ResourceManager::getT2() const {
    return t2;
}

void ResourceManager::setT2(const sf::Texture& texture) {
    t2 = texture;
}

const sf::Texture& ResourceManager::getT3() const {
    return t3;
}

void ResourceManager::setT3(const sf::Texture& texture) {
    t3 = texture;
}

sf::Sprite& ResourceManager::getSprite() {
    return s;
}

void ResourceManager::setSprite(const sf::Sprite& sprite) {
    s = sprite;
}

const sf::Sprite& ResourceManager::getBackground() const {
    return background;
}

void ResourceManager::setBackground(const sf::Sprite& sprite) {
    background = sprite;
}

const sf::Sprite& ResourceManager::getFrame() const {
    return frame;
}

void ResourceManager::setFrame(const sf::Sprite& sprite) {
    frame = sprite;
}