#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <functional>

class Level {
private:
    int level = 1;
    std::vector<std::function<void(int)>> observers; // Danh sách các observer

public:
    void addObserver(const std::function<void(int)>& observer);
    void notifyObservers();
    void increaseLevel();
    int getLevel() const;
};

#endif
