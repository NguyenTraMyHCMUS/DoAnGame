#include "Game.h"
Game::Game() : window(VideoMode(320, 480), "Tetris")
{
    t1.loadFromFile("images/tiles.png"); // tải hình ảnh cho các ô vuông
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    s.setTexture(t1); // thiết lập hình ảnh cho các ô vuông
    background.setTexture(t2); // thiết lập hình ảnh nền
    frame.setTexture(t3); // thiết lập hình ảnh khung
}

void Game::handleInput()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close(); // đóng cửa sổ khi nhấn nút đóng
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Left)
                dx = -1; // di chuyển sang trái
            else if (event.key.code == Keyboard::Right)
                dx = 1; // di chuyển sang phải
            else if (event.key.code == Keyboard::Up)
                rotate = true; // quay Tetromino
        }
    }
}

void Game::update()
{
    timer += clock.getElapsedTime().asSeconds(); // cập nhật thời gian
    clock.restart(); // khởi động lại đồng hồ
    if (timer > delay) // nếu thời gian lớn hơn độ trễ
    {
        tetromino.fall(); // Tetromino rơi xuống
        if (!tetromino.isValid(field)) // nếu Tetromino không hợp lệ
        {
            tetromino.restoreState(); // khôi phục lại trạng thái của Tetromino
            tetromino.lock(field); // khóa Tetromino vào ô vuông
            field.clearLines(); // xóa các dòng đầy trong trò chơi
            tetromino.spawn(); // tạo một Tetromino mới
        }
        timer = 0; // đặt lại thời gian
    }
    if (dx != 0) // nếu có di chuyển
    {
        tetromino.move(dx); // di chuyển Tetromino
        if (!tetromino.isValid(field)) // nếu Tetromino không hợp lệ
        {
            tetromino.restoreState(); // khôi phục lại trạng thái của Tetromino
        }
    }
    if (rotate) // nếu cần quay Tetromino
    {
        tetromino.rotate(); // quay Tetromino
        if (!tetromino.isValid(field)) // nếu Tetromino không hợp lệ
        {
            tetromino.restoreState(); // khôi phục lại trạng thái của Tetromino
        }
        rotate = false; // đặt lại biến quay về false
    }
}

void Game::draw()
{
    window.clear(); // xóa cửa sổ
    window.draw(background); // vẽ hình nền
    field.draw(window, s); // vẽ các ô vuông trong trò chơi
    tetromino.draw(window, s); // vẽ Tetromino
    window.draw(frame); // vẽ khung
    window.display(); // hiển thị cửa sổ
}
