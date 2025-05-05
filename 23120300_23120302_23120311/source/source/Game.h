#ifndef GAME_H
#define GAME_H

/**
 * @file Game.h
 * @brief Định nghĩa lớp Game điều khiển logic chính của trò chơi Tetris.
 * @author [Tên nhóm hoặc sinh viên]
 * @date [Ngày tạo]
 */

#include "Field.h"
#include "TetrominoFactory.h"
#include "GameState.h"
#include "LevelManager.h"
#include "ScoreManager.h"
#include "NextTetrominoPreview.h"

using namespace sf;

/**
 * @class Game
 * @brief Lớp chính điều khiển trò chơi Tetris: xử lý vòng lặp game, vẽ, quản lý trạng thái.
 *
 * Chứa các đối tượng chính như Field, Tetromino, GameState, ScoreManager, LevelManager.
 * Xử lý đầu vào, cập nhật trạng thái và vẽ màn hình.
 */
class Game {
private:
    RenderWindow window;               /**< Cửa sổ game */
    Texture t1, t2, t3;                /**< Các texture cho sprite */
    Sprite s, background, frame;      /**< Các sprite chính */
    Field field;                      /**< Lưới trò chơi */
    Clock clock;                      /**< Đồng hồ thời gian */
    float timer = 0;                  /**< Bộ đếm thời gian cập nhật */
    float delay = 0.3;                /**< Thời gian trễ giữa các bước rơi */
    int dx = 0;                       /**< Độ dịch ngang của khối */
    bool rotate = false;             /**< Cờ xoay khối */
    int score = 0;                    /**< Điểm số hiện tại */
    int level = 1;                    /**< Cấp độ hiện tại */
    int linesCleared = 0;            /**< Số dòng đã xóa */

    std::unique_ptr<Tetromino> tetromino;           /**< Con trỏ thông minh quản lý khối hiện tại */
    std::unique_ptr<GameState> currentState;        /**< Trạng thái trò chơi hiện tại */

    NextTetrominoPreview nextPreview; /**< Hiển thị khối tiếp theo */
    ScoreManager scoreManager;        /**< Quản lý điểm số */
    LevelManager levelManager;        /**< Quản lý cấp độ */

public:
    /** @brief Constructor mặc định */
    Game();

    /** @brief Cập nhật logic game theo thời gian */
    void update();

    /** @brief Chạy vòng lặp chính của trò chơi */
    void run();

    /** @brief Trả về texture t1 */
    const Texture& getT1() const;

    /** @brief Gán texture t1 */
    void setT1(const Texture& texture);

    /** @brief Trả về texture t2 */
    const Texture& getT2() const;

    /** @brief Gán texture t2 */
    void setT2(const Texture& texture);

    /** @brief Trả về texture t3 */
    const Texture& getT3() const;

    /** @brief Gán texture t3 */
    void setT3(const Texture& texture);

    /** @brief Trả về sprite s */
    Sprite& getSprite();

    /** @brief Gán sprite s */
    void setSprite(const Sprite& sprite);

    /** @brief Trả về sprite background */
    const Sprite& getBackground() const;

    /** @brief Gán sprite background */
    void setBackground(const Sprite& sprite);

    /** @brief Trả về sprite frame */
    const Sprite& getFrame() const;

    /** @brief Gán sprite frame */
    void setFrame(const Sprite& sprite);

    /** @brief Thiết lập độ trễ rơi khối */
    void setDelay(float value);

    /** @brief Lấy độ trễ rơi khối */
    float getDelay() const;

    /** @brief Thiết lập độ dịch ngang dx */
    void setDx(int dx);

    /** @brief Thiết lập cờ xoay khối */
    void setRotate(bool rotate);

    /** @brief Truy cập đối tượng hiển thị khối tiếp theo */
    NextTetrominoPreview& getNextTetrominoPreview();

    /** @brief Truy cập đối tượng quản lý cấp độ */
    LevelManager& getLevelManager();

    /** @brief Truy cập đối tượng quản lý điểm số */
    ScoreManager& getScoreManager();

    /** @brief Trả về cửa sổ game */
    RenderWindow& getWindow();

    /** @brief Truy cập lưới hiện tại */
    Field& getField();

    /** @brief Trả về con trỏ tới Tetromino hiện tại */
    std::unique_ptr<Tetromino>& getTetromino();

    /** @brief Trả về cấp độ hiện tại */
    int getLevel() const;

    /** @brief Đổi trạng thái trò chơi (State Pattern) */
    void setState(std::unique_ptr<GameState> newState);

    /** @brief Reset trò chơi về trạng thái ban đầu */
    void resetGame();
};

#endif
