#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

/**
 * @class MainMenuState
 * @brief Lớp đại diện cho trạng thái menu chính của trò chơi.
 * 
 * Lớp này xử lý tất cả các thao tác liên quan đến giao diện menu chính, bao gồm xử lý đầu vào và vẽ màn hình menu.
 */
class MainMenuState : public GameState {
private:
    Game& _game; /**< Tham chiếu đến đối tượng game */
    sf::Texture _menuBackgroundTexture; /**< Texture cho hình ảnh menu nền */
    sf::Sprite _menuBackgroundSprite;   /**< Sprite để hiển thị hình ảnh nền */
    sf::Font _fontTitle; /**< Phông chữ cho tiêu đề */
    sf::Font _fontWelcome; /**< Phông chữ cho phần chào mừng */
    sf::Text _welcome; /**< Tiêu đề chào mừng trên menu */
    sf::Font _font; /**< Phông chữ cho các mục menu */
    sf::Text _title; /**< Tiêu đề menu */
    sf::Texture _buttonTexture; /**< Texture cho hình ảnh các nút bấm */
    sf::Sprite _buttonSprites[3]; /**< Mảng các sprite cho các nút */
    sf::Text _menuOptions[3]; /**< Mảng các mục menu (Start Game, Instructions, Exit) */
    int _selectedIndex; /**< Chỉ số của mục menu đang được chọn */

public:
    /**
     * @brief Constructor cho lớp MainMenuState.
     * 
     * Khởi tạo trạng thái menu chính của trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    MainMenuState(Game& game);

    /**
     * @brief Xử lý đầu vào của người chơi trong trạng thái menu chính.
     * 
     * Hàm này sẽ nhận và xử lý các sự kiện đầu vào từ người chơi như phím bấm.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ giao diện menu chính lên màn hình.
     * 
     * Hàm này vẽ tất cả các yếu tố của menu chính, bao gồm nền, tiêu đề và các nút.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void draw(Game& game) override;
};

#endif
