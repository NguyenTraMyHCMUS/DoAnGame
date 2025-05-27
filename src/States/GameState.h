/**
 * @file GameState.h
 * @brief Định nghĩa lớp trừu tượng GameState cho các trạng thái trong trò chơi.
 * 
 * Lớp này cung cấp các phương thức cơ bản mà mọi trạng thái trong trò chơi cần phải triển khai,
 * bao gồm xử lý đầu vào và vẽ giao diện.
 */

 #ifndef GAMESTATE_H
 #define GAMESTATE_H
 
 #include <SFML/Graphics.hpp>
 
 class Game;
 
 /**
  * @class GameState
  * @brief Lớp trừu tượng đại diện cho một trạng thái trong trò chơi
  * 
  * Lớp trừu tượng này định nghĩa các phương thức cơ bản mà các trạng thái cụ thể
  * (như MainMenuState, PlayingState, PauseState, GameOverState) cần phải triển khai.
  * 
  */
 class GameState {
 public:
     /**
      * @brief Destructor ảo
      * 
      * Đảm bảo việc hủy tài nguyên được thực hiện đúng cách khi đối tượng bị hủy.
      * 
      */
     virtual ~GameState() = default;
 
     /**
      * @brief Xử lý đầu vào từ người dùng.
      * 
      * Phương thức này sẽ được triển khai bởi các lớp con để xử lý các sự kiện đầu vào
      * như bàn phím, chuột, hoặc các thiết bị khác.
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     virtual void handleInput(Game& game) = 0;
 
     /**
      * @brief Vẽ giao diện của trạng thái lên cửa sổ game.
      * 
      * Phương thức này sẽ được triển khai bởi các lớp con để hiển thị giao diện
      * tương ứng với trạng thái hiện tại.
      * 
      * @param game Tham chiếu đến đối tượng Game chính.
      */
     virtual void draw(Game& game) = 0;

     virtual void update(Game& game) = 0;
 };
 
 #endif // GAMESTATE_H
