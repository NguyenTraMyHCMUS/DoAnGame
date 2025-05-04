
#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

/**
 * @file GameOverState.h
 * @brief Định nghĩa lớp GameOverState quản lý trạng thái "Game Over" trong trò chơi.
 */

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

/**
 * @class GameOverState
 * @brief Lớp đại diện cho trạng thái "Game Over" trong trò chơi.
 * 
 * Lớp này kế thừa từ GameState và hiển thị màn hình Game Over, 
 * cho phép người chơi chọn giữa việc chơi lại hoặc thoát.
 */
class GameOverState : public GameState {
private:
    Game& _game; ///< Tham chiếu đến đối tượng Game chính.
    sf::Texture _gameOverTexture; ///< Texture chứa hình ảnh "Game Over".
    sf::Sprite _gameOverSprite; ///< Sprite dùng để vẽ hình ảnh "Game Over".
    sf::Font _font; ///< Phông chữ được sử dụng để hiển thị văn bản.
    sf::Text _title; ///< Văn bản tiêu đề "Game Over".
    sf::Text _menuOptions[2]; ///< Các tùy chọn menu: Retry và Exit.
    int _selectedIndex; ///< Chỉ số mục menu hiện đang được chọn.

public:
    /**
     * @brief Constructor khởi tạo trạng thái Game Over.
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    GameOverState(Game& game);

    /**
     * @brief Xử lý các sự kiện đầu vào như bàn phím từ người dùng.
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ giao diện trạng thái Game Over lên màn hình.
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void draw(Game& game) override;
};

#endif // GAMEOVERSTATE_H
