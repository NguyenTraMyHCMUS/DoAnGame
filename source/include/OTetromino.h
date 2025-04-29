#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "Tetromino.h"

class OTetromino : public Tetromino {
public:
    OTetromino(); // Constructor khởi tạo khối O
    ~OTetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối O
};

#endif
