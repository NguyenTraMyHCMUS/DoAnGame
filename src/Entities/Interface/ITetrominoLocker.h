#ifndef ITETROMINO_LOCKER_H
#define ITETROMINO_LOCKER_H

#include "../Field.h"

/**
 * @brief Interface cho việc cố định khối Tetromino vào lưới
 * 
 * Tuân thủ nguyên tắc Interface Segregation (ISP) trong SOLID,
 * interface này chỉ chứa các phương thức liên quan đến việc cố định khối.
 */
class ITetrominoLocker {
public:
    virtual ~ITetrominoLocker() = default;
    
    /**
     * @brief Cố định khối vào lưới
     * 
     * @param field Lưới để cố định khối vào
     * @param color Màu của khối cần cố định
     */
    virtual void lock(Field& field, int color) const = 0;
};

#endif
