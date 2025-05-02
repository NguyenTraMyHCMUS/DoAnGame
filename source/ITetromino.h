#ifndef ITETROMINO_H
#define ITETROMINO_H

#include "Tetromino.h"

class ITetromino : public Tetromino {
public:
    ITetromino();
    ~ITetromino() override = default; // Destructor ảo để giải phóng bộ nhớ
    void initializeShape() override; // Khởi tạo hình dạng khối I
    void rotate() override; // Xoay khối I (ngang hoặc dọc)
    std::unique_ptr<Tetromino> clone() const override {
        return std::make_unique<ITetromino>(*this);
    }
};

#endif
