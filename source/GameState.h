#ifndef GAMESTATE_H
#define GAMESTATE_H

/// \file GameState.h
/// \brief Định nghĩa lớp trừu tượng GameState cho mô hình State Pattern.


#include <SFML/Graphics.hpp>

class Game;

/// \class GameState
/// \brief Lớp trừu tượng đại diện cho một trạng thái trong trò chơi.
///
/// Các trạng thái như PlayingState, PauseState, GameOverState sẽ kế thừa từ lớp này.
/// Mỗi trạng thái cần định nghĩa cách xử lý đầu vào và cách vẽ.
class GameState {
public:
    /// \brief Destructor ảo để đảm bảo hủy đúng đối tượng con.
    virtual ~GameState() = default;

    /// \brief Xử lý đầu vào (bàn phím, chuột, v.v.)
    /// \param game Tham chiếu tới đối tượng Game chính để thay đổi trạng thái hoặc truy cập hệ thống
    virtual void handleInput(Game& game) = 0;

    /// \brief Vẽ trạng thái hiện tại lên cửa sổ
    /// \param game Tham chiếu tới đối tượng Game chính để truy cập cửa sổ và tài nguyên
    virtual void draw(Game& game) = 0;
};

#endif
