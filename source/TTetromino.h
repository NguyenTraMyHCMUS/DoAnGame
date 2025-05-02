#ifndef TTETROMINO_H
#define TTETROMINO_H

#include "Tetromino.h"

class TTetromino : public Tetromino {
public:
    TTetromino(); // Constructor khởi tạo khối T
    ~TTetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối T
    void rotate() override; // Xoay khối T (theo chiều kim đồng hồ)
     std::unique_ptr<Tetromino> clone() const override;
};

#endif
