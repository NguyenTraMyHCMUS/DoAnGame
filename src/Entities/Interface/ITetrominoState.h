#ifndef ITETROMINO_STATE_H
#define ITETROMINO_STATE_H

/**
 * @file ITetrominoState.h
 * @brief Định nghĩa interface cho việc quản lý trạng thái của khối Tetromino.
 */

/**
 * @class ITetrominoState
 * @brief Interface chuyên trách việc lưu và khôi phục trạng thái của khối Tetromino.
 * 
 * Interface này tuân thủ nguyên tắc Interface Segregation Principle (ISP) trong SOLID,
 * cho phép tách riêng logic quản lý trạng thái ra khỏi các hành vi khác như di chuyển hoặc xoay.
 */
class ITetrominoState {
public:
    /**
     * @brief Hàm hủy ảo đảm bảo việc giải phóng tài nguyên đúng cách trong đa hình.
     */
    virtual ~ITetrominoState() = default;

    /**
     * @brief Lưu lại trạng thái hiện tại của khối Tetromino.
     * 
     * Ví dụ: vị trí, hướng, kiểu khối,...
     */
    virtual void backupState() = 0;

    /**
     * @brief Khôi phục trạng thái đã được lưu trước đó.
     * 
     * Dùng để hoàn tác hoặc xử lý các tình huống như va chạm sau khi xoay.
     */
    virtual void restoreState() = 0;
};

#endif // ITETROMINO_STATE_H
