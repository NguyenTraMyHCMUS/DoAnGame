#ifndef ITETROMINO_STATE_H
#define ITETROMINO_STATE_H

/**
 * @brief Interface cho việc quản lý trạng thái của khối Tetromino
 * 
 * Tuân thủ nguyên tắc Interface Segregation (ISP) trong SOLID,
 * interface này chỉ chứa các phương thức liên quan đến việc lưu và khôi phục trạng thái.
 */

class ITetrominoState {
public:
    virtual ~ITetrominoState() = default;
    
    /**
     * @brief Lưu trạng thái hiện tại
     */
    virtual void backupState() = 0;
    
    /**
     * @brief Khôi phục trạng thái đã lưu
     */
    virtual void restoreState() = 0;
};

#endif
