#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>
#include <vector>
#include <utility>
class ScoreManager {
private:
    int _currentScore; /**< Điểm hiện tại của trò chơi */
    int _highScore; /**< Điểm cao nhất của trò chơi */
    const std::string _highScoreFile = "highscore.txt"; /**< Tên tệp lưu điểm cao nhất */
    std::vector<std::pair<std::string, int>> _topScores; /**< Top 3 điểm cao nhất */
    void loadHighScore();
    void saveHighScore() const;

public:
    ScoreManager();
    ~ScoreManager();
    void addScore(int points);
    int getScore() const;
    int getHighScore() const;
    void reset();
    void submitScore(const std::string& name);
    std::vector<std::pair<std::string, int>> getTopScores(int n) const;
};

#endif
