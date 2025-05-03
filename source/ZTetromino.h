#ifndef ZTETROMINO_H
#define ZTETROMINO_H

#include "Tetromino.h"

class ZTetromino : public Tetromino {
public:
    ZTetromino(); // Constructor khởi tạo khối Z
    ~ZTetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    
    void initializeShape() override; // Khởi tạo hình dạng khối Z
    void rotate() override; // Xoay khối Z (theo chiều kim đồng hồ)
    std::unique_ptr<Tetromino> clone() const override; // Tạo một bản sao của khối Z
};

#endif
