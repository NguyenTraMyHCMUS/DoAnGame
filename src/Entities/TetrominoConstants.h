#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

/**
 * @struct TetrominoConstants
 * @brief Tập hợp các hằng số dùng chung cho hệ thống Tetromino trong game.
 * 
 * Bao gồm các hằng số liên quan đến hiển thị (rendering), màu sắc của các khối,
 * cũng như các hằng số vật lý như tốc độ rơi và kích thước lưới.
 * 
 * Việc tập trung các hằng số ở một nơi giúp dễ dàng quản lý và điều chỉnh khi cần.
 */
struct TetrominoConstants {
    // Các hằng số dùng để vẽ lưới và các ô (cells)
    static constexpr int DEFAULT_CELL_SIZE = 18;  // Kích thước mặc định (pixel) của một ô trong lưới
    
    // Màu sắc của các Tetromino được ánh xạ tương ứng với các chỉ số texture
    static constexpr int I_COLOR = 1;  // Màu cyan cho khối I
    static constexpr int J_COLOR = 2;  // Màu xanh dương cho khối J
    static constexpr int L_COLOR = 3;  // Màu cam cho khối L
    static constexpr int O_COLOR = 4;  // Màu vàng cho khối O
    static constexpr int S_COLOR = 5;  // Màu xanh lá cho khối S
    static constexpr int T_COLOR = 6;  // Màu tím cho khối T
    static constexpr int Z_COLOR = 7;  // Màu đỏ cho khối Z
    
    // Các hằng số vật lý liên quan đến hành vi rơi của Tetromino
    static constexpr float DEFAULT_FALL_SPEED = 0.3f;  // Tốc độ rơi mặc định (đơn vị tùy game)
    
    // Kích thước lưới chơi
    static constexpr int GRID_WIDTH = 10;  // Chiều rộng lưới (số ô)
    static constexpr int GRID_HEIGHT = 20; // Chiều cao lưới (số ô)
};

#endif
