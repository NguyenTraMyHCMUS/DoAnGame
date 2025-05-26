#include "Tetromino.h"
#include "Task/TetrominoValidator.h"
#include "Task/TetrominoState.h"
#include "Task/TetrominoRenderer.h"
#include "Task/TetrominoMovement.h"
#include "Task/TetrominoLocker.h"

// Constructor
Tetromino::Tetromino() : _color(0), _cellSize(0), _rotator(nullptr) {
    for (int i = 0; i < 4; i++) {
        _blocks[i] = {0, 0}; // Khởi tạo các ô ở vị trí (0, 0)
        _backup[i] = {0, 0}; // Khởi tạo bản sao lưu
    }

    // Khởi tạo các thành phần theo interface
    _validator = std::make_unique<TetrominoValidator>(_blocks);
    _state = std::make_unique<TetrominoState>(_blocks);
    _renderer = std::make_unique<TetrominoRenderer>(_blocks, _cellSize);
    _movement = std::make_unique<TetrominoMovement>(_blocks);
    _locker = std::make_unique<TetrominoLocker>(_blocks);
}

Tetromino::~Tetromino() {
    delete _rotator;
}

// Hàm setCellSize: Thay đổi kích thước ô trong khối
void Tetromino::setCellSize(int size) {
    _renderer->setCellSize(size); // Thiết lập kích thước ô mới
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
   _state->backupState(); // Lưu trạng thái hiện tại
}

// Hàm restoreState: Khôi phục trạng thái từ backup
void Tetromino::restoreState() {
    _state->restoreState();
}

// Hàm move: Di chuyển khối theo chiều ngang
void Tetromino::move(int dx) {
    _movement->move(dx); // Di chuyển khối theo chiều ngang
}

// Hàm rotate: Xoay khối theo chiều kim đồng hồ
void Tetromino::rotate() {
    if (_rotator) {
        _rotator->rotate(_blocks); // Sử dụng con trỏ với ->
    }
}

// Hàm fall: Di chuyển khối xuống dưới
void Tetromino::fall() {
    _movement->fall(); // Di chuyển khối xuống dưới
}


// Hàm isValid: Kiểm tra xem khối có ở vị trí hợp lệ không
bool Tetromino::isValid(const Field &field) const {
    return _validator->isValid(field);
}

// Hàm lock: Cố định khối vào lưới
void Tetromino::lock(Field &field) const {
    _locker->lock(field, _color); // Cố định khối vào lưới
}

// Hàm draw: Vẽ khối lên cửa sổ trò chơi
void Tetromino::draw(RenderWindow &window, Sprite &sprite) const {
    _renderer->draw(window, sprite, _color); // Vẽ khối lên cửa sổ
}

int Tetromino::getX(int i) const {
    return _blocks[i].getX(); // Trả về tọa độ x của ô thứ i
}
int Tetromino::getY(int i) const {
    return _blocks[i].getY(); // Trả về tọa độ y của ô thứ i
}

// Thêm phương thức này vào public section
void Tetromino::setRotator(ITetrominoRotator* rotator) {
    if (_rotator) {
        delete _rotator;  // Xóa rotator cũ nếu có
    }
    _rotator = rotator;
}

// Sao chép các thành phần từ Tetromino khác
void Tetromino::cloneComponents(const Tetromino& other) {
    // Sao chép dữ liệu thường
    _color = other._color;
    _cellSize = other._cellSize;
        
    // Sao chép blocks
    for (int i = 0; i < 4; i++) {
        _blocks[i] = other._blocks[i];
        _backup[i] = other._backup[i];
    }
        
    // Khởi tạo lại các thành phần
    _validator = std::make_unique<TetrominoValidator>(_blocks);
    _state = std::make_unique<TetrominoState>(_blocks);
    _renderer = std::make_unique<TetrominoRenderer>(_blocks, _cellSize);
    _movement = std::make_unique<TetrominoMovement>(_blocks);
    _locker = std::make_unique<TetrominoLocker>(_blocks);
        
     // Rotator sẽ được xử lý bởi các lớp con
}
