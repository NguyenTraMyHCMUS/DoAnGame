#include "Tetromino.h"
#include "Components/TetrominoValidator.h"
#include "Components/TetrominoState.h"
#include "Components/TetrominoRenderer.h"
#include "Components/TetrominoMovement.h"
#include "Components/TetrominoLocker.h"
#include "TetrominoConstants.h"
#include "Events/TetrominoEventManager.h" 
#include "Factories/DefaultTetrominoComponentFactory.h"

Tetromino::Tetromino(ITetrominoComponentFactory& factory) : _color(0), _cellSize(TetrominoConstants::DEFAULT_CELL_SIZE), _componentFactory(&factory) {
    try {
        // Initialize blocks
        for (int i = 0; i < 4; i++) {
            _blocks[i] = {0, 0};
            _backup[i] = {0, 0};
        }
        
        initializeComponents();
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to initialize Tetromino with factory: " << e.what() << std::endl;
        throw;
    }
}

// Constructor
Tetromino::Tetromino() : _color(0), _cellSize(TetrominoConstants::DEFAULT_CELL_SIZE) {
    try {
        // Initialize blocks
        for (int i = 0; i < 4; i++) {
            _blocks[i] = {0, 0};
            _backup[i] = {0, 0};
        }
        
        // Use default factory (still DIP compliant)
        static DefaultTetrominoComponentFactory defaultFactory;
        _componentFactory = &defaultFactory;
        
        initializeComponents();
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to initialize Tetromino with default factory: " << e.what() << std::endl;
        throw;
    }
}

Tetromino::Tetromino(const Tetromino& other) 
    : _color(other._color), _cellSize(other._cellSize), _componentFactory(other._componentFactory) {
    
    try {
        // Copy blocks
        for (int i = 0; i < 4; i++) {
            _blocks[i] = other._blocks[i];
            _backup[i] = other._backup[i];
        }
        
        cloneComponents(other);
    } 
    catch (const std::exception& e) {
        std::cerr << "Copy constructor failed: " << e.what() << std::endl;
        throw;
    }
}

Tetromino& Tetromino::operator=(const Tetromino& other) {
    if (this != &other) {
        _color = other._color;
        _cellSize = other._cellSize;
        _componentFactory = other._componentFactory;
        
        // Copy blocks
        for (int i = 0; i < 4; i++) {
            _blocks[i] = other._blocks[i];
            _backup[i] = other._backup[i];
        }
        
        cloneComponents(other);
    }
    return *this;
}

void Tetromino::initializeComponents() {
   if (!_componentFactory) {
        throw std::runtime_error("ComponentFactory is null");
    }
    
    try {
        // const blocks for read-only components
        _validator = _componentFactory->createValidator(_blocks);
        if (!_validator) {
            throw std::runtime_error("Failed to create validator component");
        }
        
        _renderer = _componentFactory->createRenderer(_blocks, _cellSize);
        if (!_renderer) {
            throw std::runtime_error("Failed to create renderer component");
        }
        
        _locker = _componentFactory->createLocker(_blocks);
        if (!_locker) {
            throw std::runtime_error("Failed to create locker component");
        }
        
        // non-const blocks for modifying components
        _state = _componentFactory->createState(_blocks);
        if (!_state) {
            throw std::runtime_error("Failed to create state component");
        }
        
        _movement = _componentFactory->createMovement(_blocks);
        if (!_movement) {
            throw std::runtime_error("Failed to create movement component");
        }
        
        // _rotator will be set by derived classes based on type
        
    } 
    catch (const std::exception& e) {
        std::cerr << "Component initialization failed: " << e.what() << std::endl;
        throw;
    }
}
// Hàm setCellSize: Thay đổi kích thước ô trong khối
void Tetromino::setCellSize(int size) {
    if (size <= 0) {
        throw std::invalid_argument("Cell size must be positive: " + std::to_string(size));
    }
    
    try {
        _cellSize = size;
        if (_renderer) {
            _renderer->setCellSize(size);
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set cell size: " << e.what() << std::endl;
        throw;
    }
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
     if (color < 0) {
        throw std::invalid_argument("Color must be non-negative: " + std::to_string(color));
    }
    _color = color;
}

// Hàm backupState: Lưu trạng thái hiện tại của khối
void Tetromino::backupState() {
    try {
        if (_state) {
            _state->backupState();
        } else {
            std::cerr << "Warning: State component is null, cannot backup" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to backup state: " << e.what() << std::endl;
        throw;
    }
}

// Hàm restoreState: Khôi phục trạng thái từ backup
void Tetromino::restoreState() {
    try {
        if (_state) {
            _state->restoreState();
        } else {
            std::cerr << "Warning: State component is null, cannot restore" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to restore state: " << e.what() << std::endl;
        throw;
    }
}

// Hàm move: Di chuyển khối theo chiều ngang
void Tetromino::move(int dx) {
    try {
        if (_movement) {
            _movement->move(dx);
            TetrominoEventManager::getInstance().notifyMoved(*this, dx);
        } else {
            std::cerr << "Warning: Movement component is null" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to move tetromino: " << e.what() << std::endl;
        throw;
    }
}

// Hàm rotate: Xoay khối theo chiều kim đồng hồ
void Tetromino::rotate() {
   try {
        if (_rotator) {
            _rotator->rotate(_blocks);
            TetrominoEventManager::getInstance().notifyRotated(*this);
        } else {
            std::cerr << "Warning: Rotator component is null" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to rotate tetromino: " << e.what() << std::endl;
        throw;
    }
}

// Hàm fall: Di chuyển khối xuống dưới
void Tetromino::fall() {
    try {
        if (_movement) {
            _movement->fall();
            TetrominoEventManager::getInstance().notifyFell(*this);
        } else {
            std::cerr << "Warning: Movement component is null" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to make tetromino fall: " << e.what() << std::endl;
        throw;
    }
}

// Hàm isValid: Kiểm tra xem khối có ở vị trí hợp lệ không
bool Tetromino::isValid(const Field& field) const {
     try {
        if (_validator) {
            return _validator->isValid(field);
        } else {
            std::cerr << "Warning: Validator component is null, assuming invalid" << std::endl;
            return false;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to validate tetromino position: " << e.what() << std::endl;
        return false; // Safe default
    }
}

// Hàm lock: Cố định khối vào lưới
void Tetromino::lock(Field &field) const {
    try {
        if (_locker) {
            _locker->lock(field, _color);
            TetrominoEventManager::getInstance().notifyLocked(*this);
        } else {
            std::cerr << "Warning: Locker component is null" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to lock tetromino: " << e.what() << std::endl;
        throw;
    }
}

// Hàm draw: Vẽ khối lên cửa sổ trò chơi
void Tetromino::draw(RenderWindow &window, Sprite &sprite) const {
    try {
        if (_renderer) {
            _renderer->draw(window, sprite, _color);
        } else {
            std::cerr << "Warning: Renderer component is null" << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to draw tetromino: " << e.what() << std::endl;
    }
}

// Hàm getX: Trả về tọa độ x của ô thứ i
int Tetromino::getX(int i) const {
    if (i < 0 || i >= 4) {
        throw std::out_of_range("Block index out of range: " + std::to_string(i));
    }
    
    try {
        return _blocks[i].getX();
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to get X coordinate for block " << i << ": " << e.what() << std::endl;
        throw;
    }
}

// Hàm getY: Trả về tọa độ y của ô thứ i
int Tetromino::getY(int i) const {
    if (i < 0 || i >= 4) {
        throw std::out_of_range("Block index out of range: " + std::to_string(i));
    }
    
    try {
        return _blocks[i].getY();
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to get Y coordinate for block " << i << ": " << e.what() << std::endl;
        throw;
    }
}

// Hàm setRotator: Thiết lập con trỏ đến bộ xoay khối
void Tetromino::setRotator(std::unique_ptr<ITetrominoRotator> rotator) {
    if (!rotator) {
        throw std::invalid_argument("Rotator cannot be null");
    }
    
    try {
        _rotator = std::move(rotator);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set rotator: " << e.what() << std::endl;
        throw;
    }
}

void Tetromino::setValidator(std::unique_ptr<ITetrominoValidator> validator) {
   if (!validator) {
        throw std::invalid_argument("Validator cannot be null");
    }
    
    try {
        _validator = std::move(validator);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set validator: " << e.what() << std::endl;
        throw;
    }
}

void Tetromino::setRenderer(std::unique_ptr<ITetrominoRenderer> renderer) {
    if (!renderer) {
        throw std::invalid_argument("Renderer cannot be null");
    }
    
    try {
        _renderer = std::move(renderer);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set renderer: " << e.what() << std::endl;
        throw;
    }
}

void Tetromino::setMovement(std::unique_ptr<ITetrominoMovement> movement) {
   if (!movement) {
        throw std::invalid_argument("Movement cannot be null");
    }
    
    try {
        _movement = std::move(movement);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set movement: " << e.what() << std::endl;
        throw;
    }
}

void Tetromino::setLocker(std::unique_ptr<ITetrominoLocker> locker) {
    if (!locker) {
        throw std::invalid_argument("Locker cannot be null");
    }
    
    try {
        _locker = std::move(locker);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set locker: " << e.what() << std::endl;
        throw;
    }
}

void Tetromino::setState(std::unique_ptr<ITetrominoState> state) {
    if (!state) {
        throw std::invalid_argument("State cannot be null");
    }
    
    try {
        _state = std::move(state);
    } 
    catch (const std::exception& e) {
        std::cerr << "Failed to set state: " << e.what() << std::endl;
        throw;
    }
}

// Sao chép các thành phần từ Tetromino khác
void Tetromino::cloneComponents(const Tetromino& other) {
    if (!_componentFactory) {
        throw std::runtime_error("ComponentFactory is null during cloning");
    }
    
    try {
        // const blocks for read-only components
        _validator = _componentFactory->createValidator(_blocks);
        _renderer = _componentFactory->createRenderer(_blocks, _cellSize);
        _locker = _componentFactory->createLocker(_blocks);
        
        // non-const blocks for modifying components
        _state = _componentFactory->createState(_blocks);
        _movement = _componentFactory->createMovement(_blocks);
        
    } catch (const std::exception& e) {
        std::cerr << "Component cloning failed: " << e.what() << std::endl;
        throw;
    }
}
