#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

/**
 * @file GameOverState.h
 * @brief Định nghĩa lớp GameOverState cho trạng thái "Game Over" của trò chơi.
 * 
 * Lớp này kế thừa từ GameState, cung cấp các phương thức và thuộc tính cần thiết để quản lý giao diện "Game Over",
 * bao gồm việc xử lý đầu vào từ người dùng và vẽ các thành phần giao diện lên cửa sổ game.
 */

#include "GameState.h"
#include "../Core/Game.h"
#include "PlayingState.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class Game;

/**
 * @class GameOverState
 * @brief Trạng thái "Game Over" của trò chơi.
 * 
 * Lớp này kế thừa từ GameState (interface) và chịu trách nhiệm hiển thị giao diện khi kết thúc trò chơi.
 * Xử lý các lựa chọn như: Retry (chơi lại) và Exit (thoát).
 * 
 */
class GameOverState : public GameState {
private:
    Game& _game;  ///< Tham chiếu đến đối tượng Game chính để chuyển đổi trạng thái.

    sf::Texture _gameOverTexture;  ///< Texture chứa hình ảnh "Game Over".
    sf::Sprite _gameOverSprite;    ///< Sprite dùng để hiển thị texture "Game Over".

    sf::Font _font;          ///< Phông chữ dùng cho tiêu đề và menu.
    sf::Text _title;         ///< Tiêu đề "Game Over" hiển thị trên màn hình.
    sf::Text _menuOptions[2];///< Hai lựa chọn menu: Retry và Exit.
    sf::Text _topScoreTexts[3]; ///< Hiển thị top 3 điểm cao nhất

    int _selectedIndex;      ///< Chỉ số của mục menu hiện đang được chọn.
    
public:
    /**
     * @brief Constructor.
     * 
     * Khởi tạo trạng thái "GameOver" bao gồm: tải các tài nguyên (hình ảnh, phông chữ), khởi tạo và thiết lập các thành phần của menu,
     * thiết lập hình ảnh nền và các văn bản liên quan (màu sắc, kích thước, vị trí).
     * 
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    GameOverState(Game& game);

    /**
     * @brief Xử lý đầu vào từ người dùng (bàn phím, chuột).
     * 
     * @details
     * Hỗ trợ người dùng tương tác với menu "Game Over": 
     * - Nháy chuột trái vào nút X ở góc trên bên phải để đóng cửa sổ.
     * - Di chuyển giữa các mục menu bằng keyboard (mũi tên lên/xuống).
     * Thực hiện chọn một mục bằng cách nhấn Enter.
     *   + Chọn "Retry": để chuyển sang trạng thái chơi game.
     *   + Chọn "Exit": để thoát trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ màn hình "Game Over" và menu lựa chọn lên cửa sổ.
     * 
     * Bao gồm hình nền, tiêu đề, và các mục menu.
     * 
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void draw(Game& game) override;

    void update(Game& game) override;
};

#endif // GAMEOVERSTATE_H
