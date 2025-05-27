// Interfaces/IColorMapper.h 
#ifndef ICOLOR_MAPPER_H
#define ICOLOR_MAPPER_H

#include <string>

/**
 * @file IColorMapper.h
 * @brief Định nghĩa interface cho việc ánh xạ màu sắc các loại khối Tetris.
 */

/**
 * @class IColorMapper
 * @brief Giao diện ánh xạ giữa loại khối Tetris và mã màu tương ứng.
 * 
 * Interface này giúp trừu tượng hóa việc quản lý màu sắc của các khối Tetris,
 * cho phép cấu hình màu động, dễ mở rộng hoặc thay thế.
 * 
 * Áp dụng nguyên lý DIP (Dependency Inversion Principle) trong SOLID:
 * - Các thành phần sử dụng màu không phụ thuộc vào logic ánh xạ cụ thể.
 */
class IColorMapper {
public:
    /**
     * @brief Hàm hủy ảo đảm bảo việc hủy đối tượng thông qua con trỏ đa hình diễn ra đúng cách.
     */
    virtual ~IColorMapper() = default;

    /**
     * @brief Lấy mã màu tương ứng với một loại khối Tetris.
     * 
     * @param type Tên loại khối (ví dụ: "I", "J", "L", "O", "S", "T", "Z").
     * @return Mã màu dưới dạng số nguyên, có thể được dùng để ánh xạ màu thực tế.
     */
    virtual int getColor(const std::string& type) const = 0;

    /**
     * @brief Kiểm tra xem loại khối có được ánh xạ màu không.
     * 
     * @param type Tên loại khối.
     * @return `true` nếu khối có ánh xạ màu, `false` nếu không có.
     */
    virtual bool hasColor(const std::string& type) const = 0;

    /**
     * @brief Thiết lập màu sắc mới cho một loại khối Tetris.
     * 
     * @param type Tên loại khối.
     * @param color Mã màu muốn gán.
     */
    virtual void setColor(const std::string& type, int color) = 0;

    /**
     * @brief Cập nhật bảng ánh xạ màu từ file cấu hình (hoặc nguồn ngoài).
     * 
     * Cho phép nạp lại cấu hình màu sắc nếu có thay đổi trong thời gian chạy.
     */
    virtual void updateFromConfig() = 0;
};

#endif // ICOLOR_MAPPER_H
