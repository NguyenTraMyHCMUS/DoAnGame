// RotatorFactoryRegistry.h
#ifndef ROTATOR_FACTORY_REGISTRY_H
#define ROTATOR_FACTORY_REGISTRY_H

#include "../Interface/ITetrominoRotator.h"
#include <memory>
#include <map>
#include <functional>
#include <string>

/**
 * @file RotatorFactoryRegistry.h
 * @brief Định nghĩa lớp RotatorFactoryRegistry để quản lý và tạo các đối tượng rotator cho khối Tetromino.
 * 
 * Lớp này sử dụng pattern Singleton để đảm bảo chỉ có một instance duy nhất trong chương trình,
 * giúp quản lý việc đăng ký và tạo các rotator cho từng loại Tetromino một cách hiệu quả.
 */

/**
 * @class RotatorFactoryRegistry
 * @brief Quản lý đăng ký và tạo các đối tượng rotator cho từng loại Tetromino.
 * 
 * Lớp này sử dụng pattern Singleton để đảm bảo chỉ có một registry duy nhất trong chương trình.
 * Nó lưu trữ một map ánh xạ từ tên loại Tetromino sang factory function dùng để tạo đối tượng rotator tương ứng.
 * 
 * Người dùng có thể đăng ký các rotator mới thông qua phương thức registerRotator và
 * tạo đối tượng rotator thông qua createRotator dựa trên tên loại.
 */
class RotatorFactoryRegistry {
private:
    /**
     * @brief Bảng ánh xạ từ tên loại Tetromino sang factory function tạo rotator.
     * 
     * Factory function có kiểu std::function trả về std::unique_ptr<ITetrominoRotator>.
     */
    std::map<std::string, std::function<std::unique_ptr<ITetrominoRotator>()>> _factories;
    
    /**
     * @brief Constructor riêng tư để ngăn cản tạo nhiều instance.
     * 
     * Đảm bảo lớp này chỉ có một instance duy nhất (Singleton).
     */
    RotatorFactoryRegistry() = default;
    
public:
    /**
     * @brief Lấy tham chiếu đến instance duy nhất của registry.
     * 
     * @return Tham chiếu đến đối tượng RotatorFactoryRegistry singleton.
     */
    static RotatorFactoryRegistry& getInstance();
    
    /**
     * @brief Đăng ký một factory function tạo rotator cho loại Tetromino cụ thể.
     * 
     * @param type Tên loại Tetromino (ví dụ: "I", "J", "L", "S", "T", "Z", "O").
     * @param factory Hàm factory trả về unique_ptr tới đối tượng rotator tương ứng.
     */
    void registerRotator(const std::string& type, std::function<std::unique_ptr<ITetrominoRotator>()> factory);
    
    /**
     * @brief Tạo một đối tượng rotator cho loại Tetromino được chỉ định.
     * 
     * @param type Tên loại Tetromino.
     * @return unique_ptr đến đối tượng rotator mới được tạo. Nếu loại không tồn tại, trả về nullptr.
     */
    std::unique_ptr<ITetrominoRotator> createRotator(const std::string& type);
};

#endif
