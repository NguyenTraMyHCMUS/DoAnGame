#include "catch.hpp"
#include "../../Entities/Events/TetrominoEventManager.h"
#include "../../Entities/Tetromino.h"

// Dummy Listener kế thừa đúng interface
class DummyListener : public ITetrominoEventListener {
public:
    bool created = false, moved = false, rotated = false, fell = false, locked = false, destroyed = false;
    void onTetrominoCreated(const Tetromino&) override { created = true; }
    void onTetrominoMoved(const Tetromino&, int) override { moved = true; }
    void onTetrominoRotated(const Tetromino&) override { rotated = true; }
    void onTetrominoFell(const Tetromino&) override { fell = true; }
    void onTetrominoLocked(const Tetromino&) override { locked = true; }
    void onTetrominoDestroyed(const Tetromino&) override { destroyed = true; }
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

    REQUIRE(listener->created);
    REQUIRE(listener->moved);
    REQUIRE(listener->rotated);
    REQUIRE(listener->fell);
    REQUIRE(listener->locked);
    REQUIRE(listener->destroyed);

    // Test removeExpiredListeners không crash
    listener.reset();
    REQUIRE_NOTHROW(manager.removeExpiredListeners());
}
