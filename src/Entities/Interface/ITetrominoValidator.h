#ifndef ITETROMINO_VALIDATOR_H
#define ITETROMINO_VALIDATOR_H

#include "../Field.h"
#include "../Point.h"

/**
 * @file ITetrominoValidator.h
 * @brief Định nghĩa interface cho việc kiểm tra tính hợp lệ của khối Tetromino.
 */

/**
 * @class ITetrominoValidator
 * @brief Interface chuyên kiểm tra tính hợp lệ vị trí của khối Tetromino trên lưới.
 * 
 * Tuân thủ nguyên tắc Interface Segregation Principle (ISP) trong SOLID,
 * interface này tách riêng trách nhiệm kiểm tra hợp lệ khỏi logic khác như di chuyển, vẽ,...
 */
class ITetrominoValidator {
public:
    /**
     * @brief Hàm hủy ảo đảm bảo lớp kế thừa được giải phóng tài nguyên đúng cách.
     */
    virtual ~ITetrominoValidator() = default;

    /**
     * @brief Kiểm tra xem trạng thái hiện tại của khối có hợp lệ trên lưới không.
     * 
     * @param field Lưới game hiện tại.
     * @return true nếu khối nằm ở vị trí hợp lệ (không va chạm và trong giới hạn),
     *         false nếu khối vượt ra ngoài hoặc chồng lên khối khác.
     */
    virtual bool isValid(const Field& field) const = 0;
};

#endif // ITETROMINO_VALIDATOR_H
