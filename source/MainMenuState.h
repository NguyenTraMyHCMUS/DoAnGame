/** 
* @file MainMenuState.h
* @brief Định nghĩa lớp MainMenuState cho trạng thái menu chính của trò chơi.
* 
* Lớp này kế thừa từ GameState, cung cấp các phương thức và thuộc tính cần thiết để quản lý giao diện menu,
* bao gồm việc xử lý đầu vào từ người dùng và vẽ các thành phần giao diện lên cửa sổ game.
*/

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

/**
 * @class MainMenuState
 * @brief Trạng thái menu của trò chơi.
 * 
 * Lớp này kế thừa từ GameState (interface) và chịu trách nhiệm hiển thị giao diện menu chính.
 * Xử lý các lựa chọn menu như: Start (bắt đầu trò chơi), Instructions (hướng dẫn), và Exit (thoát).
 */
class MainMenuState : public GameState {
private:
    Game& _game;  ///< Tham chiếu đến đối tượng Game để truy cập và thay đổi trạng thái.

    sf::Texture _menuBackgroundTexture; ///< Texture cho hình nền của menu.
    sf::Sprite _menuBackgroundSprite;   ///< Sprite hiển thị hình nền menu.

    sf::Font _fontTitle;    ///< Phông chữ dùng cho tiêu đề menu.
    sf::Font _fontWelcome;  ///< Phông chữ dùng cho dòng chữ chào mừng.
    sf::Text _welcome;      ///< Văn bản chào mừng người chơi.

    sf::Font _font;         ///< Phông chữ dùng cho các mục menu.
    sf::Text _title;        ///< Tiêu đề chính của menu.

    sf::Texture _buttonTexture;         ///< Texture dùng cho các nút menu.
    sf::Sprite _buttonSprites[3];       ///< Mảng các nút (Start, Instructions, Exit).
    sf::Text _menuOptions[3];           ///< Mảng các văn bản cho mỗi lựa chọn menu.

    int _selectedIndex;     ///< Chỉ số hiện tại của lựa chọn được chọn trong 3 mục menu.

public:
    /**
     * @brief Constructor.
     * 
     * Khởi tạo trạng thái "MainMenu" bao gồm: tải các tài nguyên (hình ảnh, phông chữ), khởi tạo và thiết lập các thành phần của menu,
     * thiết lập hình ảnh nền, khung nút và các văn bản liên quan (màu sắc, kích thước, vị trí).
     *  
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    MainMenuState(Game& game);

   /**
     * @brief Xử lý đầu vào từ người dùng (bàn phím, chuột).
     * 
     * @details
     * Hỗ trợ người dùng tương tác với menu chính:
     * - Nháy chuột trái vào nút X ở góc trên bên trái để đóng cửa sổ.
     * - Di chuyển giữa các mục menu bằng keyboard (mũi tên lên/xuống),
     * thực hiện chọn một mục bằng cách nhấn Enter.
     *   + Chọn "Start": để chuyển sang trạng thái chơi game.
     *   + Chọn "Instruction": để mở cửa sổ hướng dẫn.
     *   + Chọn "Exit": để thoát trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void handleInput(Game& game) override;


    /**
     * @brief Vẽ giao diện menu chính lên cửa sổ game.
     * 
     * Bao gồm hình nền, tiêu đề, lời chào mừng, các nút và mục menu.
     * 
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void draw(Game& game) override;
};

#endif // MAINMENUSTATE_H
