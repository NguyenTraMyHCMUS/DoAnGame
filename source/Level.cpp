#include "Level.h"

void Level::addObserver(const std::function<void(int)>& observer) {
    observers.push_back(observer);
}

void Level::notifyObservers() {
    for (const auto& observer : observers) {
        observer(level);
    }
}

void Level::increaseLevel() {
    level++;
    notifyObservers();
}

int Level::getLevel() const {
    return level;
}
