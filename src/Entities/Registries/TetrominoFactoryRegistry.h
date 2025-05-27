#ifndef TETROMINO_FACTORY_REGISTRY_H
#define TETROMINO_FACTORY_REGISTRY_H

#include "../Tetromino.h"
#include <memory>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @file TetrominoFactoryRegistry.h
 * @brief Định nghĩa lớp TetrominoFactoryRegistry để quản lý các factory của Tetromino
 * 
 * Lớp này sử dụng mẫu thiết kế Singleton để quản lý tập các factory tạo các đối tượng Tetromino.
 * Các factory được đăng ký theo cặp (ID, tên) kèm theo hàm tạo đối tượng tương ứng.
 */

/**
 * @class TetrominoFactoryRegistry
 * @brief Singleton registry quản lý các Tetromino factories.
 * 
 * Lớp này cho phép đăng ký, tra cứu và tạo các đối tượng Tetromino theo ID hoặc tên.
 * Áp dụng Registry Pattern, giúp dễ dàng mở rộng thêm các loại Tetromino mới mà không phải chỉnh sửa lớp này.
 */
class TetrominoFactoryRegistry {
private:
    /// Bản đồ từ ID (int) sang factory function tạo đối tượng Tetromino
    std::map<int, std::function<std::unique_ptr<Tetromino>()>> _factories;

    /// Bản đồ từ tên (string) sang ID (int) để tra cứu nhanh
    std::map<std::string, int> _nameToId;

    /// Constructor riêng tư để đảm bảo chỉ có một instance duy nhất (Singleton)
    TetrominoFactoryRegistry() = default;

public:
    /// Lấy thể hiện duy nhất của lớp (Singleton pattern)
    static TetrominoFactoryRegistry& getInstance();

    /// Xóa hàm copy constructor để tránh copy thể hiện singleton
    TetrominoFactoryRegistry(const TetrominoFactoryRegistry&) = delete;

    /// Xóa toán tử gán để tránh sao chép thể hiện singleton
    TetrominoFactoryRegistry& operator=(const TetrominoFactoryRegistry&) = delete;

    /**
     * @brief Đăng ký một factory cho loại Tetromino với ID và tên tương ứng.
     * 
     * @param id ID duy nhất của loại Tetromino.
     * @param name Tên định danh của loại Tetromino.
     * @param factory Hàm tạo đối tượng Tetromino dạng std::function.
     */
    void registerFactory(int id, const std::string& name, std::function<std::unique_ptr<Tetromino>()> factory);

    /**
     * @brief Tạo đối tượng Tetromino dựa trên ID.
     * 
     * @param id ID của loại Tetromino cần tạo.
     * @return unique_ptr tới đối tượng Tetromino nếu ID hợp lệ, nullptr nếu không tìm thấy.
     */
    std::unique_ptr<Tetromino> createTetromino(int id);

    /**
     * @brief Tạo đối tượng Tetromino dựa trên tên.
     * 
     * @param name Tên của loại Tetromino cần tạo.
     * @return unique_ptr tới đối tượng Tetromino nếu tên hợp lệ, nullptr nếu không tìm thấy.
     */
    std::unique_ptr<Tetromino> createTetromino(const std::string& name);

    /**
     * @brief Lấy danh sách các ID các loại Tetromino đã đăng ký.
     * 
     * @return Vector chứa các ID.
     */
    std::vector<int> getAvailableIds() const;

    /**
     * @brief Lấy danh sách các tên các loại Tetromino đã đăng ký.
     * 
     * @return Vector chứa các tên.
     */
    std::vector<std::string> getAvailableNames() const;

    /**
     * @brief Lấy số lượng factory đã được đăng ký.
     * 
     * @return Số lượng factory.
     */
    size_t getFactoryCount() const;

    /**
     * @brief Kiểm tra xem ID có tồn tại trong registry không.
     * 
     * @param id ID cần kiểm tra.
     * @return true nếu tồn tại, false nếu không.
     */
    bool hasId(int id) const;

    /**
     * @brief Kiểm tra xem tên có tồn tại trong registry không.
     * 
     * @param name Tên cần kiểm tra.
     * @return true nếu tồn tại, false nếu không.
     */
    bool hasName(const std::string& name) const;
};

#endif
