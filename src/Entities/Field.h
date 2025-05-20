#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
using namespace sf;

/**
 * @file Field.h
 * @brief Định nghĩa lớp Field đại diện cho lưới trò chơi Tetris.
 */

/** @brief Số dòng trong lưới trò chơi. */
const int M = 20;

/** @brief Số cột trong lưới trò chơi. */
const int N = 10;

/**
 * @class Field
 * @brief Quản lý lưới trò chơi Tetris, bao gồm kiểm tra va chạm, xóa dòng và vẽ.
 *
 * Lớp này chịu trách nhiệm giữ trạng thái các ô trong lưới,
 * kiểm tra tính hợp lệ của vị trí, vẽ lưới, và xử lý logic xóa dòng.
 */
class Field {
private:
    /** @brief Mảng lưu trạng thái từng ô trong lưới. 0 là trống, >0 là màu. */
    int grid[M][N];

public:
    /** @brief Khởi tạo lưới trống ban đầu. */
    Field();

    /**
     * @brief Kiểm tra vị trí (x, y) có nằm trong lưới không.
     * @param x Tọa độ x
     * @param y Tọa độ y
     * @return true nếu nằm trong lưới, ngược lại false
     */
    bool isInside(int x, int y) const;

    /**
     * @brief Kiểm tra ô tại (x, y) đã bị chiếm chưa.
     * @param x Tọa độ x
     * @param y Tọa độ y
     * @return true nếu ô đã bị chiếm, ngược lại false
     */
    bool isOccupied(int x, int y) const;

    /**
     * @brief Gán màu cho ô tại (x, y).
     * @param x Tọa độ x
     * @param y Tọa độ y
     * @param color Mã màu (hoặc chỉ số)
     */
    void setCell(int x, int y, int color);

    /**
     * @brief Lấy giá trị màu tại ô (x, y).
     * @param x Tọa độ x
     * @param y Tọa độ y
     * @return Mã màu tại ô
     */
    int getCell(int x, int y) const;

    /**
     * @brief Kiểm tra và xóa các dòng đầy, cập nhật lưới.
     * @return Số dòng đã xóa
     */
    int clearLines();

    /**
     * @brief Vẽ lưới lên cửa sổ SFML.
     * @param window Cửa sổ vẽ
     * @param sprite Sprite để vẽ từng ô
     */
    void draw(sf::RenderWindow& window, sf::Sprite& sprite);

    /** @brief Xóa toàn bộ lưới, đặt tất cả ô về 0. */
    void clear();

    /**
     * @brief Lấy chiều cao của lưới.
     * @return Chiều cao lưới
     */
    int getHeight() const;
    /**
     * @brief Lấy chiều rộng của lưới.
     * @return Chiều rộng lưới
     */
    int getWidth() const;
    
    /**
     * @brief Kiểm tra xem một khối có thể đặt vào vị trí không.
     * @param blockPositions Danh sách tọa độ (x, y) của khối
     * @return true nếu khối có thể đặt, ngược lại false
     */
    bool canPlaceBlock(const std::vector<std::pair<int, int>>& blockPositions) const;
};

#endif
