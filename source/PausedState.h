/**
 * @file PausedState.h
 * @brief Định nghĩa trạng thái tạm dừng của trò chơi.
 * 
 * Lớp này kế thừa từ GameState và chịu trách nhiệm hiển thị giao diện tạm dừng,
 * xử lý các lựa chọn menu như Tiếp tục (Continue) hoặc Thoát (Exit).
 */

 #ifndef PAUSEDSTATE_H
 #define PAUSEDSTATE_H
 
 #include "GameState.h"
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
      * Khởi tạo trạng thái tạm dừng, bao gồm việc tải tài nguyên, thiết lập hình ảnh
      * và các mục menu.
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     PausedState(Game& game);
 
     /**
      * @brief Xử lý đầu vào từ người dùng.
      * 
      * Hỗ trợ người dùng tương tác với menu tạm dừng:
      * Nháy chuột trái vào nút X ở góc trên bên trái để đóng cửa sổ.
      * Di chuyển giữa các mục menu bằng phím mũi tên trái/phải.
      * Chọn một mục bằng cách nhấn Enter.
      * Chọn "Continue" để quay lại trạng thái chơi game.
      * Chọn "Exit" để thoát trò chơi.
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
 };
 
 #endif // PAUSEDSTATE_H
