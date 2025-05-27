#ifndef TETROMINO_TYPE_REGISTRY_H
#define TETROMINO_TYPE_REGISTRY_H

#include "TetrominoTypeInfo.h"
#include <map>
#include <string>
#include <vector>

/**
 * @file TetrominoTypeRegistry.h
 * @brief Định nghĩa lớp quản lý các loại Tetromino trong trò chơi Tetris.
 * 
 * Lớp này cung cấp các phương thức để đăng ký, truy vấn và kiểm tra tính hợp lệ của các loại Tetromino.
 */

/**
 * @class TetrominoTypeRegistry
 * @brief Quản lý registry chứa thông tin các loại Tetromino trong trò chơi.
 * 
 * Lớp này lưu trữ thông tin kiểu Tetromino theo dạng map để truy xuất nhanh theo ID hoặc tên.
 * Đồng thời cung cấp các phương thức đăng ký, truy vấn và kiểm tra tính hợp lệ của loại Tetromino.
 * 
 * Cấu trúc dữ liệu bao gồm:
 * - _typeInfo: map từ ID (int) sang thông tin loại Tetromino (TetrominoTypeInfo).
 * - _nameToId: map từ tên loại (string) sang ID (int).
 * - _initialized: cờ để đảm bảo khởi tạo registry chỉ một lần.
 */
class TetrominoTypeRegistry {
private:
    /// Bảng map từ ID sang thông tin loại Tetromino
    static std::map<int, TetrominoTypeInfo> _typeInfo;

    /// Bảng map từ tên loại Tetromino sang ID
    static std::map<std::string, int> _nameToId;

    /// Cờ đánh dấu registry đã được khởi tạo chưa
    static bool _initialized;
    
    /**
     * @brief Hàm khởi tạo registry, gọi một lần duy nhất.
     * 
     * Hàm này sẽ thêm các loại Tetromino mặc định vào registry.
     */
    static void initialize();
    
public:
    /**
     * @brief Đăng ký một loại Tetromino mới vào registry.
     * 
     * @param info Thông tin về loại Tetromino cần đăng ký (ID, tên, đặc tính,...).
     */
    static void registerType(const TetrominoTypeInfo& info);

    /**
     * @brief Lấy thông tin loại Tetromino theo ID.
     * 
     * @param id ID của loại Tetromino.
     * @return Con trỏ tới thông tin loại Tetromino nếu tồn tại, nullptr nếu không tìm thấy.
     */
    static const TetrominoTypeInfo* getTypeInfo(int id);

    /**
     * @brief Lấy thông tin loại Tetromino theo tên.
     * 
     * @param name Tên loại Tetromino.
     * @return Con trỏ tới thông tin loại Tetromino nếu tồn tại, nullptr nếu không tìm thấy.
     */
    static const TetrominoTypeInfo* getTypeInfo(const std::string& name);

    /**
     * @brief Lấy danh sách tất cả các loại Tetromino đã đăng ký.
     * 
     * @return Vector chứa thông tin tất cả các loại Tetromino.
     */
    static std::vector<TetrominoTypeInfo> getAllTypes();

    /**
     * @brief Kiểm tra xem ID có phải là một loại Tetromino hợp lệ hay không.
     * 
     * @param id ID cần kiểm tra.
     * @return true nếu hợp lệ, false nếu không.
     */
    static bool isValidType(int id);

    /**
     * @brief Kiểm tra xem tên có phải là một loại Tetromino hợp lệ hay không.
     * 
     * @param name Tên cần kiểm tra.
     * @return true nếu hợp lệ, false nếu không.
     */
    static bool isValidType(const std::string& name);
};

#endif
