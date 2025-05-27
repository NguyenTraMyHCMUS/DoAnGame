#ifndef TETROMINO_STATE_H
#define TETROMINO_STATE_H

#include "../Point.h"
#include "../Interface/ITetrominoState.h"

/**
 * @file TetrominoState.h
 * @brief Định nghĩa lớp TetrominoState để quản lý trạng thái của khối Tetromino
 */

/**
 * @class TetrominoState
 * @brief Lớp quản lý trạng thái của khối Tetromino
 * 
 * Lớp này tuân thủ nguyên tắc Single Responsibility Principle (SRP) trong SOLID,
 * chỉ chịu trách nhiệm về việc lưu và khôi phục trạng thái của các ô trong khối Tetromino.
 * Cho phép lưu trữ trạng thái hiện tại của các ô và khôi phục lại khi cần thiết,
 * ví dụ khi thực hiện xoay hay di chuyển mà cần rollback nếu vị trí không hợp lệ.
 */
class TetrominoState : public ITetrominoState {
private:
    /**
     * @brief Tham chiếu tới mảng 4 điểm đại diện cho vị trí hiện tại của các ô trong khối Tetromino
     * 
     * Đây là trạng thái đang được sử dụng trong game.
     */
    Point (&_blocks)[4];

    /**
     * @brief Mảng lưu trạng thái sao lưu (backup) của các ô
     * 
     * Được dùng để khôi phục trạng thái khi cần thiết.
     */
    Point _backup[4];

public:
    /**
     * @brief Constructor khởi tạo TetrominoState với mảng các ô
     * 
     * @param blocks Tham chiếu tới mảng chứa 4 điểm của khối Tetromino
     */
    TetrominoState(Point (&blocks)[4]);

    /**
     * @brief Destructor ảo mặc định
     */
    ~TetrominoState() override = default;

    /**
     * @brief Lưu trạng thái hiện tại của các ô vào bộ nhớ sao lưu
     * 
     * Ghi lại vị trí hiện tại của từng ô để có thể khôi phục lại sau này.
     */
    void backupState() override;

    /**
     * @brief Khôi phục trạng thái các ô từ bộ nhớ sao lưu
     * 
     * Phục hồi vị trí các ô của khối Tetromino về trạng thái đã lưu trước đó.
     */
    void restoreState() override;
};

#endif
