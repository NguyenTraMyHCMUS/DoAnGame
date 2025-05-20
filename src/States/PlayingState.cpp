#include "PlayingState.h"
#include "../Graphics/ResourceManager.h"
// Constructor
PlayingState::PlayingState(Game& game) : _game(game) {
    // Tải phông chữ
    if (!_font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cout << "Failed to load font \"assets/fonts/arial.ttf\". Please ensure the file exists." << std::endl;
        game.getWindow().close();
        return;
    }
    
    // ResourceManager đã được khởi tạo trong Game constructor
    // Không cần tải lại textures và sprites ở đây

}

// Xử lý đầu vào 
void PlayingState::handleInput(Game& game) {
    sf::Event event;
    // Xử lý sự kiện từ cửa sổ
    while (game.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.getWindow().close();
        }

        // Xử lý các phím bấm
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                game.setState(std::make_unique<PausedState>(game)); // Chuyển sang trạng thái tạm dừng
            } 
            else if (event.key.code == sf::Keyboard::Left) {
                game.getInputManager().setDx(-1); // Di chuyển sang trái
            } 
            else if (event.key.code == sf::Keyboard::Right) {
                game.getInputManager().setDx(1); // Di chuyển sang phải
            } 
            else if (event.key.code == sf::Keyboard::Up) {
                game.getInputManager().setRotate(true); // Xoay Tetromino
            }
            // Khi thả phím Down, đặt lại tốc độ về mặc định
            else if (event.key.code == sf::Keyboard::Down && event.type == sf::Event::KeyReleased) {
                game.getGameTimer().setDelay(0.3f); // Đặt lại delay về giá trị mặc định
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) game.getGameTimer().setDelay(0.05);
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) game.getGameTimer().setDelay(0.3f);
    }
}

// Vẽ toàn cảnh trạng thái playing
void PlayingState::draw(Game& game) {
    GameRenderer& renderer = game.getRenderer();
    
    // Xóa cửa sổ với màu trắng
    renderer.clear();

    // Vẽ nền
    renderer.drawBackground();

    // Vẽ lưới và Tetromino
    renderer.drawField(game.getField());
    renderer.drawTetromino(game.getTetromino().get());
    renderer.drawNextPreview(game.getNextTetrominoPreview());
  
    // Vẽ khung
    renderer.drawFrame();

    // Hiển thị thông tin cấp độ, điểm số, và điểm cao
    renderer.drawStats(game.getScoreManager(), game.getLevelManager());

    // Hiển thị cửa sổ
    renderer.display();
}
