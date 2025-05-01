#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
private:
    int currentScore;
    int highScore;
    const std::string highScoreFile = "highscore.txt"; // Tên tệp lưu điểm cao nhất

    void loadHighScore(); // Hàm tải điểm cao nhất từ tệp
    void saveHighScore() const; // Hàm lưu điểm cao nhất vào tệp

public:
    ScoreManager();
    ~ScoreManager(); // Lưu điểm cao nhất khi đối tượng bị hủy
    void addScore(int points);
    int getScore() const;
    int getHighScore() const;
    void reset();
};

#endif
