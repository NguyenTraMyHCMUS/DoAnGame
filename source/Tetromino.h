#ifndef TETROMINO_H
#define TETROMINO_H

#include "Field.h"
#include <SFML/Graphics.hpp>


struct Point {
    int _x; // Tọa độ x của ô trong lưới
    int _y; // Tọa độ y của ô trong lưới
    Point(int x = 0, int y = 0) : _x(x), _y(y) {} // Constructor khởi tạo tọa độ
};

class Tetromino {
protected:
    Point _blocks[4]; // Mảng chứa 4 ô của khối Tetris
    Point _backup[4]; // Lưu trạng thái khối để khôi phục
    int _color; // Màu sắc của khối là cố định cho mỗi hình 
    int _cellSize; // Kích thước của mỗi ô trong khối

public:
    Tetromino(); // Constructor khởi tạo khối Tetris

    virtual ~Tetromino() = default; // Destructor ảo để giải phóng bộ nhớ
    virtual void initializeShape() = 0; // Khởi tạo hình dạng khối Tetris
    virtual void rotate(); // Xoay khối: O không xoay, I xoay ngang và dọc, {Z, T, S} xoay theo chiều kim đồng hồ, {L, J} ngược chiều kim đồng hồ

    void setCellSize(int size); // Thay đổi kích thước ô trong khối
    std::vector<Point> getBlocks() const; // Lấy danh sách các ô trong khối
    void setColor(int color); // Thiết lập màu sắc cho khối
    int getColor() const; // Lấy màu sắc của khối

    void backupState(); // Lưu trạng thái hiện tại của khối
    void restoreState(); // Khôi phục trạng thái từ backup
    void move(int dx); // Di chuyển khối theo chiều ngang
    void fall(); // Di chuyển khối xuống dưới
    bool isValid(const Field &field) const; // Kiểm tra vị trí hợp lệ
    void lock(Field &field) const; // Cố định khối vào lưới
    void draw(sf::RenderWindow &window, sf::Sprite &sprite) const; //  Vẽ khối lên cửa sổ trò chơi    
};

#endif
