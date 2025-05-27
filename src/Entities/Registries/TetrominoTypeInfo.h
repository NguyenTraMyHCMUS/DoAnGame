#ifndef TETROMINO_TYPE_INFO_H
#define TETROMINO_TYPE_INFO_H

#include <string>
#include <map>
#include <vector>

/**
 * @struct TetrominoTypeInfo
 * @brief Chứa thông tin đặc trưng cho mỗi loại khối Tetromino trong trò chơi.
 * 
 * Cấu trúc này lưu trữ các thuộc tính như:
 * - id: mã định danh duy nhất cho loại khối.
 * - name: tên loại khối (ví dụ "I", "O", "T", ...).
 * - description: mô tả chi tiết về loại khối.
 * - defaultColor: màu sắc mặc định của khối.
 * - canRotate: xác định khối có thể xoay hay không.
 * - rotatorType: kiểu bộ xử lý xoay phù hợp với loại khối.
 */
struct TetrominoTypeInfo {
    int id;                  /**< Mã định danh duy nhất cho loại Tetromino */
    std::string name;        /**< Tên loại Tetromino */
    std::string description; /**< Mô tả loại Tetromino */
    int defaultColor;        /**< Màu mặc định của khối */
    bool canRotate;          /**< Khả năng xoay của khối */
    std::string rotatorType; /**< Loại bộ xoay được dùng cho khối */
    
    /**
     * @brief Constructor mặc định
     */
    TetrominoTypeInfo();
    
    /**
     * @brief Constructor có tham số để khởi tạo tất cả thuộc tính
     * 
     * @param _id Mã định danh
     * @param _name Tên loại khối
     * @param _desc Mô tả chi tiết
     * @param _color Màu mặc định
     * @param _canRotate Có thể xoay hay không
     * @param _rotatorType Kiểu bộ xoay
     */
    TetrominoTypeInfo(int _id, const std::string& _name, const std::string& _desc, int _color, bool _canRotate, const std::string& _rotatorType);
};

#endif // TETROMINO_TYPE_INFO_H
