#ifndef PAUSEDSTATE_H
#define PAUSEDSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game; // Forward declaration of Game class
// Để tránh vòng lặp khi bao gồm các tệp tiêu đề

/**
 * @class PausedState
 * @brief Lớp đại diện cho trạng thái tạm dừng của trò chơi.
 * 
 * Lớp này xử lý các thao tác liên quan đến giao diện và hành động trong trạng thái tạm dừng của trò chơi.
 */
class PausedState : public GameState {
private:
    Game& _game; /**< Tham chiếu đến đối tượng game */
    sf::Texture _pausedTexture; /**< Texture cho hình ảnh tạm dừng */
    sf::Sprite _pausedSprite;   /**< Sprite để hiển thị hình ảnh tạm dừng */
    sf::Font _font; /**< Phông chữ cho menu */
    sf::Text _title; /**< Tiêu đề tạm dừng */
    sf::Text _menuOptions[2]; /**< Mảng các mục menu (Continue, Exit) */
    int _selectedIndex; /**< Chỉ số của mục menu đang được chọn */

public:
    /**
     * @brief Constructor cho lớp PausedState.
     * 
     * Khởi tạo trạng thái tạm dừng của trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    PausedState(Game& game);

    /**
     * @brief Xử lý đầu vào trong trạng thái tạm dừng.
     * 
     * Hàm này sẽ nhận và xử lý các sự kiện đầu vào từ người chơi, chẳng hạn như nhấn phím để tiếp tục hoặc thoát.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ hình ảnh trạng thái tạm dừng lên cửa sổ.
     * 
     * Phương thức này vẽ các yếu tố của trạng thái tạm dừng lên cửa sổ của trò chơi, bao gồm hình ảnh nền và các mục menu.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void draw(Game& game) override;
};

#endif
