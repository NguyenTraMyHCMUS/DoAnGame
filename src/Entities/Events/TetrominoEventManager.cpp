#include "TetrominoEventManager.h"
#include "../Tetromino.h"
#include <algorithm>

TetrominoEventManager& TetrominoEventManager::getInstance() {
    static TetrominoEventManager instance;
    return instance;
}

void TetrominoEventManager::addListener(std::shared_ptr<ITetrominoEventListener> listener) {
    _listeners.push_back(listener);
}

void TetrominoEventManager::removeExpiredListeners() {
    _listeners.erase(
        std::remove_if(_listeners.begin(), _listeners.end(),
                      [](const std::weak_ptr<ITetrominoEventListener>& wp) {
                          return wp.expired();
                      }),
        _listeners.end());
}

void TetrominoEventManager::notifyCreated(const Tetromino& tetromino) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoCreated(tetromino);
        }
    }
}

// ✅ Implementation của method bị missing
void TetrominoEventManager::notifyMoved(const Tetromino& tetromino, int dx) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoMoved(tetromino, dx);
        }
    }
}

// ✅ Implementation của method bị missing
void TetrominoEventManager::notifyRotated(const Tetromino& tetromino) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoRotated(tetromino);
        }
    }
}

// ✅ Implementation của method bị missing
void TetrominoEventManager::notifyFell(const Tetromino& tetromino) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoFell(tetromino);
        }
    }
}

// ✅ Implementation của method bị missing
void TetrominoEventManager::notifyLocked(const Tetromino& tetromino) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoLocked(tetromino);
        }
    }
}

void TetrominoEventManager::notifyDestroyed(const Tetromino& tetromino) {
    removeExpiredListeners();
    for (auto& weakListener : _listeners) {
        if (auto listener = weakListener.lock()) {
            listener->onTetrominoDestroyed(tetromino);
        }
    }
}