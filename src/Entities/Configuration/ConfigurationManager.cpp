// ConfigurationManager.cpp
#include "ConfigurationManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Static member definition
ConfigurationManager* ConfigurationManager::instance = nullptr;

ConfigurationManager& ConfigurationManager::getInstance() {
    if (!instance) {
        instance = new ConfigurationManager();
    }
    return *instance;
}

bool ConfigurationManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open config file: " << filename << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') continue;
        
        std::istringstream iss(line);
        std::string key, value;
        if (!(iss >> key >> value)) continue;
        
        // Try to parse as int first
        try {
            int intValue = std::stoi(value);
            _intValues[key] = intValue;
        } catch (const std::exception&) {
            // If not int, store as string
            _stringValues[key] = value;
        }
    }
    
    file.close();
    std::cout << "Loaded configuration from: " << filename << std::endl;
    return true;
}

int ConfigurationManager::getInt(const std::string& key, int defaultValue) const {
    auto it = _intValues.find(key);
    return (it != _intValues.end()) ? it->second : defaultValue;
}

std::string ConfigurationManager::getString(const std::string& key, const std::string& defaultValue) const {
    auto it = _stringValues.find(key);
    return (it != _stringValues.end()) ? it->second : defaultValue;
}

void ConfigurationManager::setInt(const std::string& key, int value) {
    _intValues[key] = value;
}

void ConfigurationManager::setString(const std::string& key, const std::string& value) {
    _stringValues[key] = value;
}