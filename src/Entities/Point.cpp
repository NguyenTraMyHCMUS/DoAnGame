#include "Point.h"

// Hàm khởi tạo mặc định của lớp Point
Point::Point(){
    _x = 0;
    _y = 0;
}

// Hàm khởi tạo với tham số của lớp Point
Point::Point(int x, int y){
    _x = x;
    _y = y;
}

// Hàm thiết lập tọa độ x cho điểm
void Point::setX(int x){
    _x = x;
}

// Hàm thiết lập tọa độ y cho điểm
void Point::setY(int y){
    _y = y;
}

// Hàm lấy tọa độ x của điểm
int Point::getX() const {
    return _x;
}

// Hàm lấy tọa độ y của điểm
int Point::getY() const {
    return _y;
}
