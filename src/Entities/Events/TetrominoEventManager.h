#ifndef TETROMINO_EVENT_MANAGER_H
#define TETROMINO_EVENT_MANAGER_H

#include <vector>
#include <memory>
#include "../Interface/ITetrominoEventListener.h"

class Tetromino; // Forward declaration

/**
 * @class TetrominoEventManager
 * @brief Quản lý sự kiện (event manager) cho hệ thống Tetromino.
 * 
 * Lớp này giữ danh sách các listener (người nghe sự kiện) đăng ký để nhận các thông báo về
 * trạng thái hoặc hành động của các đối tượng Tetromino.
 * 
 * Sử dụng Weak Pointer để tránh giữ giữ chặt đối tượng listener,
 * giúp tự động loại bỏ listener khi không còn ai giữ shared_ptr tới nó.
 * 
 * Thiết kế Singleton để đảm bảo chỉ có một instance quản lý toàn bộ sự kiện Tetromino.
 */
class TetrominoEventManager {
private:
    std::vector<std::weak_ptr<ITetrominoEventListener>> _listeners; /**< Danh sách các listener dưới dạng weak_ptr */
    
    TetrominoEventManager() = default; // Constructor private để đảm bảo Singleton
    
public:
    /**
     * @brief Lấy thể hiện duy nhất của TetrominoEventManager (Singleton pattern)
     * @return Tham chiếu tới instance duy nhất
     */
    static TetrominoEventManager& getInstance();
    
    /**
     * @brief Thêm listener mới để nhận các sự kiện Tetromino
     * @param listener shared_ptr tới listener cần đăng ký
     */
    void addListener(std::shared_ptr<ITetrominoEventListener> listener);
    
    /**
     * @brief Loại bỏ các listener đã hết hạn (không còn tồn tại)
     * 
     * Giúp làm sạch danh sách listener, tránh giữ các weak_ptr trỏ tới đối tượng đã bị hủy
     */
    void removeExpiredListeners();
    
    /**
     * @brief Thông báo rằng một Tetromino đã được tạo
     * @param tetromino Đối tượng Tetromino mới được tạo
     */
    void notifyCreated(const Tetromino& tetromino);
    
    /**
     * @brief Thông báo rằng một Tetromino đã di chuyển
     * @param tetromino Đối tượng Tetromino di chuyển
     * @param dx Khoảng cách di chuyển theo trục x (có thể âm hoặc dương)
     */
    void notifyMoved(const Tetromino& tetromino, int dx);
    
    /**
     * @brief Thông báo rằng một Tetromino đã quay (rotate)
     * @param tetromino Đối tượng Tetromino đã quay
     */
    void notifyRotated(const Tetromino& tetromino);
    
    /**
     * @brief Thông báo rằng một Tetromino đã rơi xuống vị trí mới
     * @param tetromino Đối tượng Tetromino đã rơi
     */
    void notifyFell(const Tetromino& tetromino);
    
    /**
     * @brief Thông báo rằng một Tetromino đã bị khóa vị trí (locked)
     * @param tetromino Đối tượng Tetromino đã bị khóa
     */
    void notifyLocked(const Tetromino& tetromino);
    
    /**
     * @brief Thông báo rằng một Tetromino đã bị phá hủy (destroyed)
     * @param tetromino Đối tượng Tetromino bị phá hủy
     */
    void notifyDestroyed(const Tetromino& tetromino);
};

#endif
