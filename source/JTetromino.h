#ifndef JTETROMINO_H
#define JTETROMINO_H

#include "Tetromino.h"

class JTetromino : public Tetromino {
public:
    JTetromino(); // Constructor khởi tạo khối J
    ~JTetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối
    void rotate() override; // Xoay khối J (ngược chiều kim đồng hồ)
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
