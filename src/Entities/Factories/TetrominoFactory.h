#ifndef TETROMINO_FACTORY_H
#define TETROMINO_FACTORY_H

#include "../Tetromino.h"
#include "../Registries/TetrominoTypeInfo.h"
#include <memory>
#include <string>

// Forward declarations thay vì include trực tiếp các lớp cụ thể (nếu cần)
class TetrominoFactoryRegistry;

/**
 * @file TetrominoFactory.h
 * @brief Định nghĩa lớp TetrominoFactory để tạo các khối Tetromino
 */

/**
 * @class TetrominoFactory
 * @brief Lớp factory tạo các đối tượng Tetromino.
 * 
 * Lớp này tuân thủ Open/Closed Principle (mở để mở rộng, đóng để sửa đổi) nhờ sử dụng Registry Pattern.
 * Cho phép thêm các loại Tetromino mới mà không cần chỉnh sửa code trong factory này.
 * 
 * Hỗ trợ tạo Tetromino dựa trên ID, tên, hoặc tạo ngẫu nhiên.
 * Cung cấp các hàm kiểm tra hợp lệ và truy xuất thông tin metadata của các loại Tetromino.
 * 
 * Hệ thống auto-registration giúp tự động đăng ký các loại Tetromino khi chương trình khởi động.
 * 
 * @see TetrominoFactoryRegistry: Quản lý registry các factory functions.
 * @see TetrominoAutoRegistrar: Hệ thống tự động đăng ký.
 */
class TetrominoFactory {
public:
    /**
     * @brief Tạo đối tượng Tetromino theo loại (ID).
     * @param type ID của loại Tetromino (ví dụ: 0-6 ứng với các loại I, J, L, O, S, T, Z).
     * @return unique_ptr trỏ tới đối tượng Tetromino đã tạo, trả về nullptr nếu type không hợp lệ.
     */
    static std::unique_ptr<Tetromino> createTetromino(int type);

    /**
     * @brief Tạo đối tượng Tetromino theo tên.
     * @param name Tên loại Tetromino (ví dụ: "I", "J", "L", "O", "S", "T", "Z").
     * @return unique_ptr trỏ tới đối tượng Tetromino đã tạo, trả về nullptr nếu name không hợp lệ.
     */
    static std::unique_ptr<Tetromino> createTetromino(const std::string& name);

    /**
     * @brief Tạo một đối tượng Tetromino ngẫu nhiên.
     * @return unique_ptr trỏ tới đối tượng Tetromino được tạo ngẫu nhiên.
     */
    static std::unique_ptr<Tetromino> createRandomTetromino();

    /**
     * @brief Lấy số lượng loại Tetromino đã đăng ký.
     * @return Số lượng loại Tetromino có sẵn.
     */
    static size_t getAvailableTypeCount();

    /**
     * @brief Kiểm tra xem một ID loại Tetromino có tồn tại hay không.
     * @param type ID loại Tetromino cần kiểm tra.
     * @return true nếu hợp lệ, false nếu không hợp lệ.
     */
    static bool isValidType(int type);

    /**
     * @brief Kiểm tra xem một tên loại Tetromino có tồn tại hay không.
     * @param name Tên loại Tetromino cần kiểm tra.
     * @return true nếu hợp lệ, false nếu không hợp lệ.
     */
    static bool isValidName(const std::string& name);

    /**
     * @brief Tạo Tetromino kèm metadata ứng dụng.
     * 
     * Hàm này có thể mở rộng để khởi tạo các đối tượng với thông tin bổ sung (ví dụ như cấu hình hoặc trạng thái ban đầu).
     */
    static std::unique_ptr<Tetromino> createTetrominoWithMetadata(int type);
    static std::unique_ptr<Tetromino> createTetrominoWithMetadata(const std::string& name);

    /**
     * @brief Truy vấn thông tin metadata của loại Tetromino theo ID hoặc tên.
     * @param type ID loại Tetromino.
     * @return Con trỏ tới TetrominoTypeInfo, nullptr nếu không tồn tại.
     */
    static const TetrominoTypeInfo* getTypeInfo(int type);
    static const TetrominoTypeInfo* getTypeInfo(const std::string& name);

    /**
     * @brief Lấy toàn bộ danh sách thông tin các loại Tetromino đã đăng ký.
     * @return Vector chứa thông tin của tất cả các loại Tetromino.
     */
    static std::vector<TetrominoTypeInfo> getAllTypeInfo();
};

#endif
