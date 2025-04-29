#ifndef STETROMINO_H
#define STETROMINO_H

#include "Tetromino.h"

class STetromino : public Tetromino {
public:
    STetromino(); // Constructor khởi tạo khối S
    ~STetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối S
};

#endif
