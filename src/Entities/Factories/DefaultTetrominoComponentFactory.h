#ifndef DEFAULT_TETROMINO_COMPONENT_FACTORY_H
#define DEFAULT_TETROMINO_COMPONENT_FACTORY_H

#include "../Interface/ITetrominoComponentFactory.h"
#include "../Interface/ITetrominoValidator.h"
#include "../Interface/ITetrominoState.h"
#include "../Interface/ITetrominoRenderer.h"
#include "../Interface/ITetrominoMovement.h"
#include "../Interface/ITetrominoLocker.h"
#include "../Interface/ITetrominoRotator.h"
#include "../Point.h"
#include <memory>
#include <string>

/**
 * @class DefaultTetrominoComponentFactory
 * @brief Nhà máy (Factory) mặc định tạo các thành phần của Tetromino.
 * 
 * Lớp này triển khai các phương thức tạo các thành phần khác nhau của khối Tetris
 * như Validator, Renderer, Locker, State, Movement, và Rotator.
 * 
 * Các thành phần này được tách biệt giúp dễ dàng mở rộng và thay thế.
 */
class DefaultTetrominoComponentFactory : public ITetrominoComponentFactory {
public:
    DefaultTetrominoComponentFactory() = default;  /**< Constructor mặc định */
    virtual ~DefaultTetrominoComponentFactory() = default; /**< Destructor mặc định */
    
    /**
     * @brief Tạo đối tượng Validator kiểm tra tính hợp lệ của khối.
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối (không thay đổi).
     * @return unique_ptr đến đối tượng ITetrominoValidator.
     */
    std::unique_ptr<ITetrominoValidator> createValidator(const Point (&blocks)[4]) override;
    
    /**
     * @brief Tạo đối tượng Renderer để vẽ khối lên màn hình.
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối (không thay đổi).
     * @param cellSize Kích thước mỗi ô vuông.
     * @return unique_ptr đến đối tượng ITetrominoRenderer.
     */
    std::unique_ptr<ITetrominoRenderer> createRenderer(const Point (&blocks)[4], int cellSize) override;
    
    /**
     * @brief Tạo đối tượng Locker để cố định khối vào lưới khi không thể di chuyển.
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối (không thay đổi).
     * @return unique_ptr đến đối tượng ITetrominoLocker.
     */
    std::unique_ptr<ITetrominoLocker> createLocker(const Point (&blocks)[4]) override;
    
    /**
     * @brief Tạo đối tượng State quản lý trạng thái hiện tại của khối.
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối (có thể thay đổi).
     * @return unique_ptr đến đối tượng ITetrominoState.
     */
    std::unique_ptr<ITetrominoState> createState(Point (&blocks)[4]) override;
    
    /**
     * @brief Tạo đối tượng Movement quản lý các thao tác di chuyển của khối.
     * 
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối (có thể thay đổi).
     * @return unique_ptr đến đối tượng ITetrominoMovement.
     */
    std::unique_ptr<ITetrominoMovement> createMovement(Point (&blocks)[4]) override;
    
    /**
     * @brief Tạo đối tượng Rotator xử lý việc xoay khối dựa theo loại khối.
     * 
     * @param type Chuỗi tên loại khối (ví dụ: "I", "O", "T", "L", ...)
     * @return unique_ptr đến đối tượng ITetrominoRotator.
     */
    std::unique_ptr<ITetrominoRotator> createRotator(const std::string& type) override;
};

#endif
