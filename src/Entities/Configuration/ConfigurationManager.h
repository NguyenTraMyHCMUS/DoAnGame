#ifndef CONFIGURATION_MANAGER_H
#define CONFIGURATION_MANAGER_H

#include <string>
#include <map>

/**
 * @class ConfigurationManager
 * @brief Quản lý cấu hình cho ứng dụng, cho phép load cấu hình từ file,
 * lưu trữ các giá trị cấu hình dưới dạng key-value, hỗ trợ các kiểu dữ liệu int và string.
 * 
 * Đây là lớp Singleton đảm bảo chỉ có một thể hiện duy nhất trong toàn bộ ứng dụng.
 */
class ConfigurationManager {
private:
    std::map<std::string, int> _intValues;         /**< Lưu trữ các giá trị cấu hình kiểu int với key là string */
    std::map<std::string, std::string> _stringValues; /**< Lưu trữ các giá trị cấu hình kiểu string với key là string */
    
    static ConfigurationManager* instance; /**< Con trỏ static giữ instance duy nhất của lớp */
    
    ConfigurationManager() = default; /**< Constructor private để ngăn không cho tạo đối tượng ngoài lớp */
    
public:
    /**
     * @brief Lấy instance duy nhất của ConfigurationManager
     * 
     * @return Tham chiếu đến instance ConfigurationManager
     */
    static ConfigurationManager& getInstance();
    
    /**
     * @brief Load cấu hình từ file
     * 
     * File cấu hình sẽ được đọc và các giá trị được lưu vào các map tương ứng
     * 
     * @param filename Tên file cấu hình
     * @return true nếu load thành công, false nếu thất bại
     */
    bool loadFromFile(const std::string& filename);
    
    /**
     * @brief Lấy giá trị kiểu int từ cấu hình
     * 
     * Nếu key không tồn tại thì trả về giá trị mặc định
     * 
     * @param key Khóa cấu hình
     * @param defaultValue Giá trị mặc định nếu key không tồn tại
     * @return Giá trị int tương ứng với key
     */
    int getInt(const std::string& key, int defaultValue = 0) const;
    
    /**
     * @brief Lấy giá trị kiểu string từ cấu hình
     * 
     * Nếu key không tồn tại thì trả về giá trị mặc định
     * 
     * @param key Khóa cấu hình
     * @param defaultValue Giá trị mặc định nếu key không tồn tại
     * @return Giá trị string tương ứng với key
     */
    std::string getString(const std::string& key, const std::string& defaultValue = "") const;
    
    /**
     * @brief Thiết lập giá trị kiểu int cho một key
     * 
     * @param key Khóa cấu hình
     * @param value Giá trị int cần thiết lập
     */
    void setInt(const std::string& key, int value);
    
    /**
     * @brief Thiết lập giá trị kiểu string cho một key
     * 
     * @param key Khóa cấu hình
     * @param value Giá trị string cần thiết lập
     */
    void setString(const std::string& key, const std::string& value);
};

#endif
