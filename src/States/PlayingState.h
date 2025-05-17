#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "GameState.h"
#include "PausedState.h"
#include "../Core/Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Game;

/**
 * @class PlayingState
 * @brief Lớp đại diện cho trạng thái chơi của trò chơi.
 * 
 * Lớp này quản lý các thao tác và hiển thị thông tin trong khi trò chơi đang diễn ra, bao gồm xử lý đầu vào và vẽ các thông tin trò chơi.
 */
class PlayingState : public GameState {
private:
    Game& _game; /**< Tham chiếu đến đối tượng game */
    sf::Font _font; /**< Phông chữ dùng cho hiển thị thông tin trong game */

public:
    /**
     * @brief Constructor cho lớp PlayingState.
     * 
     * Khởi tạo trạng thái chơi của trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    PlayingState(Game& game);

    /**
     * @brief Xử lý đầu vào trong trạng thái chơi.
     * 
     * Phương thức này nhận và xử lý các sự kiện đầu vào từ người chơi như di chuyển khối, xoay khối hoặc dừng trò chơi.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void handleInput(Game& game) override;

    /**
     * @brief Vẽ hộp thông tin trong trò chơi.
     * 
     * Phương thức này vẽ một hộp thông tin chứa các thông tin như điểm số, level và khối tiếp theo lên cửa sổ.
     * 
     * @param window Cửa sổ render nơi hộp thông tin sẽ được vẽ.
     * @param position Vị trí trên màn hình nơi hộp thông tin sẽ được đặt.
     * @param title Tiêu đề của hộp thông tin.
     * @param value Giá trị (ví dụ: điểm số, level, hoặc khối tiếp theo).
     */
    void drawInfoBox(sf::RenderWindow& window, sf::Vector2f position, const std::string& title, const std::string& value);

    /**
     * @brief Vẽ toàn cảnh trong trạng thái chơi.
     * 
     * Phương thức này vẽ tất cả các yếu tố cần thiết trong trạng thái chơi, bao gồm cả giao diện và các khối.
     * 
     * @param game Tham chiếu đến đối tượng game.
     */
    void draw(Game& game) override;
};

#endif
