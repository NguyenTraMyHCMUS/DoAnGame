#ifndef IGAME_RENDERER_H
#define IGAME_RENDERER_H

#include <string>
#include <vector>

class Field;
class Tetromino;
class NextTetrominoPreview;
class ScoreManager;
class LevelManager;

/**
 * @interface IGameRenderer
 * @brief Interface trừu tượng cho việc vẽ các thành phần của game
 */
class IGameRenderer {
public:
    virtual ~IGameRenderer() = default;

    virtual void clear() = 0;
    virtual void display() = 0;
    virtual void drawBackground() = 0;
    virtual void drawField(const Field& field) = 0;
    virtual void drawTetromino(const Tetromino* tetromino) = 0;
    virtual void drawInfoBox(const std::string& title, const std::string& value, float yPos) = 0;
    virtual void drawNextPreview(const NextTetrominoPreview& preview) = 0;
    virtual void drawStats(const ScoreManager& scoreManager, const LevelManager& levelManager) = 0;
    virtual void drawFrame() = 0;

    /**
     * @brief Cập nhật trạng thái renderer, bao gồm các hiệu ứng
     * @param deltaTime Thời gian từ frame trước
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Khởi tạo hiệu ứng xóa dòng
     * @param lines Danh sách các dòng cần xóa
     */
    virtual void initLineClearEffect(const std::vector<int>& lines) = 0;

    /**
     * @brief Kiểm tra có hiệu ứng xóa dòng đang hoạt động không
     * @return true nếu có hiệu ứng đang chạy
     */
    virtual bool hasActiveLineClearEffect() const = 0;

    /**
     * @brief Lấy danh sách các dòng đang được xóa
     * @return Danh sách dòng đang có hiệu ứng
     */
    virtual std::vector<int> getActiveLinesToClear() const = 0;
};

#endif
