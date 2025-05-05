/**
 * @file InstructionsState.h
 * @brief Định nghĩa lớp InstructionsState cho trạng thái "Instructions" của trò chơi.
 * 
 * Lớp này kế thừa từ GameState, cung cấp các phương thức và thuộc tính cần thiết để quản lý giao diện hướng dẫn,
 * bao gồm việc xử lý đầu vào từ người dùng và vẽ các thành phần giao diện lên cửa sổ game.
 */

#ifndef INSTRUCTIONSSTATE_H
#define INSTRUCTIONSSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Game;

/**
 * @class InstructionsState
 * @brief Trạng thái hiển thị hướng dẫn của trò chơi.
 *
 * Lớp này kế thừa từ GameState (interface) và chịu trách nhiệm hiển thị giao diện hướng dẫn chơi.
 * Trạng thái này hiển thị nội dung hướng dẫn và quy tắc chơi của game.
 * 
 */
class InstructionsState : public GameState {
private:
    Game& _game;  ///< Tham chiếu đến đối tượng Game chính.

    sf::Texture _instructionTexture;  ///< Texture cho nền của màn hình hướng dẫn.
    sf::Sprite _instructionSprite;    ///< Sprite hiển thị nền hướng dẫn.

    sf::Font _font;           ///< Phông chữ dùng cho tiêu đề, nội dung và nút trở về.
    sf::Text _title;          ///< Tiêu đề "Hướng dẫn".
    sf::Text _instructions;   ///< Nội dung hướng dẫn chi tiết cách chơi.
    sf::Text _backOption;     ///< Tùy chọn để quay lại menu chính.

public:
    /**
     * @brief Constructor.
     *
     * Khởi tạo trạng thái "Instruction", bao gồm việc tải tài nguyên,
     * thiết lập hình ảnh nền và các văn bản liên quan.
     *
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    InstructionsState(Game& game);

    /**
     * @brief Xử lý đầu vào của người dùng (bàn phím, chuột).
     *
     * @details
     * Hỗ trợ người dùng tương tác với "Instructions":
     * - Nháy chuột trái vào nút X ở góc trên bên phải để đóng cửa sổ.
     * - Nhấn phím Enter để quay lại menu chính.
     *
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ màn hình hướng dẫn lên cửa sổ.
     *
     * Bao gồm nền, tiêu đề, nội dung hướng dẫn và tùy chọn quay lại.
     *
     * @param game Tham chiếu đến đối tượng Game chính.
     */
    void draw(Game& game) override;
};

#endif // INSTRUCTIONSSTATE_H
