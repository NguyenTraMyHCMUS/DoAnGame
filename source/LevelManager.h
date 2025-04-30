#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager {
private:
    int currentLevel;
    int linesCleared;

public:
    LevelManager();
    void increaseLevel();
    void addClearedLines(int lines);
    int getLevel() const;
    int getLinesCleared() const;
    void reset();
};

#endif
