#ifndef INSTRUCTIONSSTATE_H
#define INSTRUCTIONSSTATE_H

/// \file InstructionsState.h
/// \brief Định nghĩa lớp InstructionsState để hiển thị hướng dẫn chơi.

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

/// \class InstructionsState
/// \brief Trạng thái hướng dẫn trong trò chơi, hiển thị các phím điều khiển và cách chơi.
///
/// Đây là một trạng thái cụ thể kế thừa từ GameState, cho phép người chơi đọc hướng dẫn và quay lại menu chính.
class InstructionsState : public GameState {
private:
    Game& _game;                           ///< Tham chiếu đến đối tượng Game chính
    sf::Texture _instructionTexture;      ///< Texture dùng làm nền cho màn hình hướng dẫn
    sf::Sprite _instructionSprite;        ///< Sprite hiển thị nền hướng dẫn
    sf::Font _font;                       ///< Font chữ dùng để hiển thị văn bản
    sf::Text _title;                      ///< Tiêu đề "Hướng dẫn"
    sf::Text _instructions;               ///< Nội dung hướng dẫn cách chơi
    sf::Text _backOption;                 ///< Văn bản cho tùy chọn quay lại menu chính

public:
    /// \brief Constructor khởi tạo màn hình hướng dẫn.
    /// \param game Tham chiếu đến đối tượng Game để truy cập tài nguyên và trạng thái.
    InstructionsState(Game& game);

    /// \brief Xử lý đầu vào của người dùng (ví dụ: nhấn phím quay lại).
    /// \param game Đối tượng Game để cập nhật trạng thái nếu cần.
    void handleInput(Game& game) override;

    /// \brief Vẽ màn hình hướng dẫn, bao gồm tiêu đề, nội dung và tùy chọn quay lại.
    /// \param game Đối tượng Game để truy cập cửa sổ SFML và các tài nguyên liên quan.
    void draw(Game& game) override;
};

#endif
