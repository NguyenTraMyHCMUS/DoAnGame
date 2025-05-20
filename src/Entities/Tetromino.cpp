#include "Tetromino.h"

// Constructor
Tetromino::Tetromino() {
    _cellSize = 18; // Kích thước ô mặc định
    _color = 0; // Màu mặc định
    for (int i = 0; i < 4; i++) {
        _blocks[i] = {0, 0}; // Khởi tạo các ô ở vị trí (0, 0)
        _backup[i] = {0, 0}; // Khởi tạo bản sao lưu
    }
}

// Hàm setCellSize: Thay đổi kích thước ô trong khối
void Tetromino::setCellSize(int size) {
    _cellSize = size;
}

// Hàm getBlocks: Trả về danh sách các ô của khối
const Point* Tetromino::getBlocks() const {
    return _blocks; // Trả về mảng các ô của khối
}

// Hàm getColor: Trả về màu sắc của khối
int Tetromino::getColor() const {
    return _color;
}

// Hàm setColor: Thiết lập màu sắc cho khối
void Tetromino::setColor(int color) {
    _color = color;
}

// Hàm backupState: Lưu trạng thái hiện tại của khối
void Tetromino::backupState() {
    for (int i = 0; i < 4; i++) {
        _backup[i] = _blocks[i];
    }
}

// Hàm restoreState: Khôi phục trạng thái từ backup
void Tetromino::restoreState() {
    for (int i = 0; i < 4; i++) {
        _blocks[i] = _backup[i];
    }
}

// Hàm move: Di chuyển khối theo chiều ngang
void Tetromino::move(int dx) {
    for (int i = 0; i < 4; i++) {
        _blocks[i]._x += dx;
    }
}

// Hàm rotate: Xoay khối theo chiều kim đồng hồ
void Tetromino::rotate() {
    Point center = _blocks[1]; // Điểm trung tâm để xoay
    for (int i = 0; i < 4; i++) {
        int x = _blocks[i]._y - center._y;
        int y = _blocks[i]._x - center._x;
        _blocks[i]._x = center._x - x;
        _blocks[i]._y = center._y + y;
    }
}

// Hàm fall: Di chuyển khối xuống dưới
void Tetromino::fall() {
    for (int i = 0; i < 4; i++) {
        _blocks[i]._y += 1;
    }
}

// Hàm isValid: Kiểm tra xem khối có ở vị trí hợp lệ không
bool Tetromino::isValid(const Field &field) const {
    for (int i = 0; i < 4; i++) {
        if (!field.isInside(_blocks[i]._x, _blocks[i]._y) || field.isOccupied(_blocks[i]._x, _blocks[i]._y)) {
            return false;
        }
    }
    return true;
}

// Hàm lock: Cố định khối vào lưới
void Tetromino::lock(Field &field) const {
    for (int i = 0; i < 4; i++) {
        field.setCell(_blocks[i]._x, _blocks[i]._y, _color);
    }
}

// Hàm draw: Vẽ khối lên cửa sổ trò chơi
void Tetromino::draw(RenderWindow &window, Sprite &sprite) const {
    for (int i = 0; i < 4; i++) {
        sprite.setTextureRect(IntRect(_color * _cellSize, 0, _cellSize, _cellSize)); // Đặt màu sắc
        sprite.setPosition(_blocks[i]._x * _cellSize, _blocks[i]._y * _cellSize); // Đặt vị trí
        sprite.move(28, 31); // Offset để căn chỉnh với khung
        window.draw(sprite); // Vẽ sprite lên cửa sổ
    }
}

int Tetromino::getX(int i) const {
    return _blocks[i]._x; // Trả về tọa độ x của ô thứ i
}
int Tetromino::getY(int i) const {
    return _blocks[i]._y; // Trả về tọa độ y của ô thứ i
}