#ifndef ITETROMINO_EVENT_LISTENER_H
#define ITETROMINO_EVENT_LISTENER_H

class Tetromino; // Khai báo chuyển tiếp

/**
 * @file ITetrominoEventListener.h
 * @brief Định nghĩa interface cho các listener theo dõi sự kiện của Tetromino.
 */

/**
 * @class ITetrominoEventListener
 * @brief Giao diện định nghĩa các phương thức callback khi Tetromino xảy ra sự kiện.
 *
 * Giao diện này cho phép các lớp bên ngoài đăng ký để lắng nghe các thay đổi trong
 * vòng đời hoặc hành vi của Tetromino (tạo, di chuyển, rơi, xoay, khóa, phá hủy).
 *
 * Áp dụng nguyên lý **Observer Pattern** và **DIP** trong SOLID:
 * - Tách biệt logic xử lý sự kiện khỏi lớp Tetromino.
 * - Cho phép dễ dàng mở rộng hành vi mà không thay đổi Tetromino.
 */
class ITetrominoEventListener {
public:
    /**
     * @brief Hàm hủy ảo giúp đảm bảo giải phóng tài nguyên đúng khi hủy qua con trỏ đa hình.
     */
    virtual ~ITetrominoEventListener() = default;

    /**
     * @brief Gọi khi một Tetromino mới được tạo.
     * @param tetromino Đối tượng Tetromino vừa được khởi tạo.
     */
    virtual void onTetrominoCreated(const Tetromino& tetromino) {}

    /**
     * @brief Gọi khi Tetromino di chuyển theo chiều ngang.
     * @param tetromino Tetromino đang di chuyển.
     * @param dx Độ dịch chuyển theo trục x (âm: trái, dương: phải).
     */
    virtual void onTetrominoMoved(const Tetromino& tetromino, int dx) {}

    /**
     * @brief Gọi khi Tetromino được xoay.
     * @param tetromino Tetromino đang bị xoay.
     */
    virtual void onTetrominoRotated(const Tetromino& tetromino) {}

    /**
     * @brief Gọi khi Tetromino rơi xuống (từng bước hoặc tự động).
     * @param tetromino Tetromino đang rơi.
     */
    virtual void onTetrominoFell(const Tetromino& tetromino) {}

    /**
     * @brief Gọi khi Tetromino bị khóa vào lưới.
     * @param tetromino Tetromino vừa bị cố định tại vị trí.
     */
    virtual void onTetrominoLocked(const Tetromino& tetromino) {}

    /**
     * @brief Gọi khi Tetromino bị phá hủy hoặc giải phóng (ví dụ: khi hàng được xóa).
     * @param tetromino Tetromino đã bị phá hủy.
     */
    virtual void onTetrominoDestroyed(const Tetromino& tetromino) {}
};

#endif // ITETROMINO_EVENT_LISTENER_H
