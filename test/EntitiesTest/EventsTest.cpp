#include "catch.hpp"
#include "../../Entities/Events/TetrominoEventManager.h"
#include "../../Entities/Tetromino.h"

// Dummy Listener kế thừa đúng interface
class DummyListener : public ITetrominoEventListener {
public:
    bool _created = false, _moved = false, _rotated = false, _fell = false, _locked = false, _destroyed = false;
    void onTetrominoCreated(const Tetromino&) override { _created = true; }
    void onTetrominoMoved(const Tetromino&, int) override { _moved = true; }
    void onTetrominoRotated(const Tetromino&) override { _rotated = true; }
    void onTetrominoFell(const Tetromino&) override { _fell = true; }
    void onTetrominoLocked(const Tetromino&) override { _locked = true; }
    void onTetrominoDestroyed(const Tetromino&) override { _destroyed = true; }
};

// Dummy Tetromino kế thừa đúng kiểu
class DummyTetrominoReal : public Tetromino {
public:
    void initializeShape() override {}
    std::string getTypeName() const override { return "Dummy"; }
    std::unique_ptr<Tetromino> clone() const override { return std::make_unique<DummyTetrominoReal>(); }
    // Nếu Tetromino có thêm hàm THUẦN ẢO nào khác, bạn phải override ở đây!
};

TEST_CASE("TetrominoEventManager singleton and listener", "[TetrominoEventManager]") {
    TetrominoEventManager& manager = TetrominoEventManager::getInstance();

    auto listener = std::make_shared<DummyListener>();
    manager.addListener(listener);

    DummyTetrominoReal tetromino;

    manager.notifyCreated(tetromino);
    manager.notifyMoved(tetromino, 1);
    manager.notifyRotated(tetromino);
    manager.notifyFell(tetromino);
    manager.notifyLocked(tetromino);
    manager.notifyDestroyed(tetromino);

    REQUIRE(listener->_created);
    REQUIRE(listener->_moved);
    REQUIRE(listener->_rotated);
    REQUIRE(listener->_fell);
    REQUIRE(listener->_locked);
    REQUIRE(listener->_destroyed);

    // Test removeExpiredListeners không crash
    listener.reset();
    REQUIRE_NOTHROW(manager.removeExpiredListeners());
}
