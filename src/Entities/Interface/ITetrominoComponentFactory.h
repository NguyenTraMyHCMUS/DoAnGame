// Interface/ITetrominoComponentFactory.h - ✅ Đã sửa đúng chữ ký hàm
#ifndef ITETROMINO_COMPONENT_FACTORY_H
#define ITETROMINO_COMPONENT_FACTORY_H

#include <memory>
#include <string>

// Khai báo trước các class để tránh include không cần thiết
class Point;
class ITetrominoValidator;
class ITetrominoState;
class ITetrominoRenderer;
class ITetrominoMovement;
class ITetrominoLocker;
class ITetrominoRotator;

/**
 * @file ITetrominoComponentFactory.h
 * @brief Interface factory dùng để tạo các thành phần (components) của một khối Tetromino.
 */

/**
 * @class ITetrominoComponentFactory
 * @brief Lớp trừu tượng định nghĩa interface cho việc tạo các component của Tetromino.
 *
 * Áp dụng nguyên lý SOLID:
 * - SRP (Single Responsibility Principle): Chịu trách nhiệm duy nhất là tạo components.
 * - OCP (Open/Closed Principle): Có thể mở rộng bằng cách tạo factory mới mà không sửa code cũ.
 * - DIP (Dependency Inversion Principle): Tetromino phụ thuộc vào abstraction thay vì implementation cụ thể.
 */
class ITetrominoComponentFactory {
public:
    /**
     * @brief Hàm hủy ảo để đảm bảo việc hủy đối tượng đúng cách qua con trỏ base class.
     */
    virtual ~ITetrominoComponentFactory() = default;

    /**
     * @brief Tạo validator kiểm tra hợp lệ cho các khối Tetromino.
     * @param blocks Mảng 4 điểm đại diện cho vị trí các ô (cell) của khối Tetromino.
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoValidator.
     */
    virtual std::unique_ptr<ITetrominoValidator> createValidator(const Point (&blocks)[4]) = 0;

    /**
     * @brief Tạo renderer để vẽ khối Tetromino.
     * @param blocks Mảng 4 điểm đại diện cho các ô của khối.
     * @param cellSize Kích thước mỗi ô để vẽ.
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoRenderer.
     */
    virtual std::unique_ptr<ITetrominoRenderer> createRenderer(const Point (&blocks)[4], int cellSize) = 0;

    /**
     * @brief Tạo locker để xử lý việc cố định khối Tetromino trên lưới.
     * @param blocks Mảng các điểm của khối.
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoLocker.
     */
    virtual std::unique_ptr<ITetrominoLocker> createLocker(const Point (&blocks)[4]) = 0;

    /**
     * @brief Tạo state để quản lý trạng thái của khối Tetromino.
     * @param blocks Mảng 4 điểm, có thể chỉnh sửa để thay đổi trạng thái.
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoState.
     */
    virtual std::unique_ptr<ITetrominoState> createState(Point (&blocks)[4]) = 0;

    /**
     * @brief Tạo movement handler để xử lý di chuyển của khối.
     * @param blocks Mảng 4 điểm, có thể thay đổi khi di chuyển khối.
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoMovement.
     */
    virtual std::unique_ptr<ITetrominoMovement> createMovement(Point (&blocks)[4]) = 0;

    /**
     * @brief Tạo rotator để xoay khối Tetromino.
     * @param type Chuỗi đại diện cho loại Tetromino (I, O, T, S, Z, J, L).
     * @return std::unique_ptr trỏ đến đối tượng ITetrominoRotator.
     */
    virtual std::unique_ptr<ITetrominoRotator> createRotator(const std::string& type) = 0;
};

#endif // ITETROMINO_COMPONENT_FACTORY_H
