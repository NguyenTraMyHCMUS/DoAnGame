#ifndef POINT_H 
#define POINT_H

/**
 * @file Point.h
 * @brief Định nghĩa lớp Point đại diện cho một điểm trong hệ tọa độ 2 chiều.
 * Lớp này cung cấp các phương thức để khởi tạo, thiết lập và truy xuất tọa độ của điểm.
 * 
 */

/**
 * @class Point
 * @brief Lớp đại diện cho một điểm trong hệ tọa độ 2 chiều với tọa độ nguyên.
 * 
 * Lớp này chứa hai thuộc tính chính là _x và _y, biểu diễn tọa độ ngang và dọc.
 * Cung cấp các phương thức để khởi tạo, thiết lập và truy xuất tọa độ của điểm.
 */
class Point {
protected:
    int _x; ///< Tọa độ x (hoành độ) của điểm
    int _y; ///< Tọa độ y (tung độ) của điểm

public:
    /**
     * @brief Constructor mặc định khởi tạo điểm tại tọa độ (0, 0).
     */
    Point();

    /**
     * @brief Constructor khởi tạo điểm với tọa độ cho trước.
     * @param x Tọa độ x (hoành độ) của điểm.
     * @param y Tọa độ y (tung độ) của điểm.
     */
    Point(int x, int y);

    /**
     * @brief Thiết lập tọa độ x cho điểm.
     * @param x Giá trị tọa độ x mới.
     */
    void setX(int x);

    /**
     * @brief Thiết lập tọa độ y cho điểm.
     * @param y Giá trị tọa độ y mới.
     */
    void setY(int y);

    /**
     * @brief Lấy giá trị tọa độ x hiện tại của điểm.
     * @return Giá trị tọa độ x.
     */
    int getX() const;

    /**
     * @brief Lấy giá trị tọa độ y hiện tại của điểm.
     * @return Giá trị tọa độ y.
     */
    int getY() const;
};

#endif // POINT_H
