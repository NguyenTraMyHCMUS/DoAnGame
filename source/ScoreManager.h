#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

/**
 * @class ScoreManager
 * @brief Lớp quản lý điểm số của trò chơi.
 * 
 * Lớp này quản lý điểm số hiện tại và điểm cao nhất, bao gồm các phương thức để thêm điểm, lấy điểm, lưu và tải điểm cao nhất.
 */
class ScoreManager {
private:
    int currentScore; /**< Điểm hiện tại của trò chơi */
    int highScore; /**< Điểm cao nhất của trò chơi */
    const std::string highScoreFile = "highscore.txt"; /**< Tên tệp lưu điểm cao nhất */

    /**
     * @brief Tải điểm cao nhất từ tệp.
     * 
     * Phương thức này sẽ đọc điểm cao nhất từ tệp "highscore.txt" và cập nhật giá trị cho biến highScore.
     */
    void loadHighScore();

    /**
     * @brief Lưu điểm cao nhất vào tệp.
     * 
     * Phương thức này lưu giá trị điểm cao nhất hiện tại vào tệp "highscore.txt".
     */
    void saveHighScore() const;

public:
    /**
     * @brief Constructor cho lớp ScoreManager.
     * 
     * Khởi tạo đối tượng ScoreManager và tải điểm cao nhất từ tệp.
     */
    ScoreManager();

    /**
     * @brief Destructor cho lớp ScoreManager.
     * 
     * Phương thức này lưu điểm cao nhất vào tệp khi đối tượng bị hủy.
     */
    ~ScoreManager();

    /**
     * @brief Thêm điểm vào điểm hiện tại.
     * 
     * Phương thức này sẽ thêm một số điểm vào điểm hiện tại của trò chơi.
     * 
     * @param points Số điểm cần thêm vào.
     */
    void addScore(int points);

    /**
     * @brief Lấy điểm hiện tại của trò chơi.
     * 
     * Phương thức này trả về điểm hiện tại của trò chơi.
     * 
     * @return Điểm hiện tại.
     */
    int getScore() const;

    /**
     * @brief Lấy điểm cao nhất của trò chơi.
     * 
     * Phương thức này trả về điểm cao nhất được lưu trong trò chơi.
     * 
     * @return Điểm cao nhất.
     */
    int getHighScore() const;

    /**
     * @brief Đặt lại điểm hiện tại về 0.
     * 
     * Phương thức này sẽ đặt lại điểm hiện tại về 0, nhưng không ảnh hưởng đến điểm cao nhất.
     */
    void reset();
};

#endif
