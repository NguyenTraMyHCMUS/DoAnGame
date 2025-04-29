#ifndef LTETROMINO_H
#define LTETROMINO_H

#include "Tetromino.h"

class LTetromino : public Tetromino {
public:
    LTetromino(); // Constructor khởi tạo khối L
    ~LTetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối L
};

#endif
