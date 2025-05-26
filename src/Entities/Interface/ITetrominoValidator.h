#ifndef ITETROMINO_VALIDATOR_H
#define ITETROMINO_VALIDATOR_H

#include "../Field.h"
#include "../Point.h"

/**
 * @brief Interface cho việc kiểm tra tính hợp lệ của khối Tetromino
 * 
 * Tuân thủ nguyên tắc Interface Segregation (ISP) trong SOLID,
 * interface này chỉ chứa các phương thức liên quan đến việc kiểm tra tính hợp lệ.
 */
class ITetrominoValidator {
public:
    virtual ~ITetrominoValidator() = default;
    
    /**
     * @brief Kiểm tra tính hợp lệ của khối trên lưới
     * 
     * @param field Lưới game để kiểm tra
     * @return true nếu vị trí hợp lệ, false nếu không
     */
    virtual bool isValid(const Field& field) const = 0;
};

#endif
