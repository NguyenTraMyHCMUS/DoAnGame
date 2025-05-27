 #ifndef PAUSEDSTATE_H
 #define PAUSEDSTATE_H

/**
 * @file PausedState.h
 * @brief Định nghĩa lớp PausedState cho trạng thái tạm dừng của trò chơi.
 * 
 * Lớp này kế thừa từ GameState, cung cấp các phương thức và thuộc tính cần thiết để quản lý giao diện tạm dừng,
 * bao gồm việc xử lý đầu vào từ người dùng và vẽ các thành phần giao diện lên cửa sổ game.
 */

#include "GameState.h"
#include "PlayingState.h"
#include "../Core/Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
 
 class Game; // Forward declaration of Game class
 
 /**
  * @class PausedState
  * @brief Trạng thái tạm dừng của trò chơi.
  * 
  * Lớp này kế thừa từ GameState và chịu trách nhiệm hiển thị giao diện tạm dừng,
  * xử lý các lựa chọn menu như Tiếp tục (Continue) hoặc Thoát (Exit).
  */

 class PausedState : public GameState {
 private:
     Game& _game; ///< Tham chiếu đến đối tượng Game chính.
 
     sf::Texture _pausedTexture; ///< Texture cho hình ảnh tạm dừng.
     sf::Sprite _pausedSprite;   ///< Sprite để hiển thị hình ảnh tạm dừng.
 
     sf::Font _font; ///< Phông chữ dùng cho tiêu đề và menu.
     sf::Text _title; ///< Tiêu đề hiển thị trạng thái tạm dừng.
     sf::Text _menuOptions[2]; ///< Các mục menu: "Continue" và "Exit".
 
     int _selectedIndex; ///< Chỉ số của mục menu hiện tại đang được chọn.
 
 public:
     /**
      * @brief Constructor.
      * 
      * Khởi tạo trạng thái "Paused" bao gồm: tải các tài nguyên (hình ảnh, phông chữ), khởi tạo và thiết lập các thành phần của menu,
      * thiết lập hình ảnh nền và các văn bản liên quan (màu sắc, kích thước, vị trí).
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     PausedState(Game& game);
 
     /**
      * @brief Xử lý đầu vào từ người dùng.
      * 
      * @details
      * Hỗ trợ người dùng tương tác với menu "Paused":
      * - Nháy chuột trái vào nút X ở góc trên bên phải để đóng cửa sổ.
      * - Di chuyển giữa các mục menu bằng phím mũi tên trái/phải.
      * Chọn một mục bằng cách nhấn Enter.
      *   + Chọn "Continue" để quay lại trạng thái chơi game.
      *   + Chọn "Exit" để thoát trò chơi.
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     void handleInput(Game& game) override;
 
     /**
      * @brief Vẽ giao diện tạm dừng lên cửa sổ game.
      * 
      * Bao gồm hình ảnh tạm dừng, tiêu đề, và các mục menu.
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     void draw(Game& game) override;

     void update(Game& game) override;
 };
 
 #endif // PAUSEDSTATE_H
