#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

class ScoreManager {
private:
    int currentScore;
    int highScore;

public:
    ScoreManager();
    void addScore(int points);
    int getScore() const;
    int getHighScore() const;
    void reset();
};

#endif
