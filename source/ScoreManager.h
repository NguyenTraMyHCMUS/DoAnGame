#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <vector>
#include <functional>

class ScoreManager {
private:
    int score = 0;
    std::vector<std::function<void(int)>> observers; // Danh sách các observer

public:
    void addObserver(const std::function<void(int)>& observer);
    void notifyObservers();
    void addScore(int points);
    int getScore() const;
};

#endif
