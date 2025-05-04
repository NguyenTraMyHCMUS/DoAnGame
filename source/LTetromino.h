#ifndef LTETROMINO_H
#define LTETROMINO_H

/// \file LTetromino.h
/// \brief Định nghĩa lớp LTetromino đại diện cho khối hình L trong trò chơi Tetris.


#include "Tetromino.h"

/// \class LTetromino
/// \brief Đại diện cho khối Tetromino hình chữ L.
///
/// Lớp này kế thừa từ lớp cơ sở Tetromino, định nghĩa cụ thể cách khởi tạo hình dạng,
/// xoay khối L và tạo bản sao.
/// Áp dụng nguyên tắc LSP (Liskov Substitution) và OCP (Open/Closed Principle).
class LTetromino : public Tetromino {
public:
    /// \brief Constructor khởi tạo khối L với hình dạng ban đầu.
    LTetromino();

    /// \brief Destructor ảo mặc định để giải phóng đúng bộ nhớ.
    ~LTetromino() override = default;

    /// \brief Khởi tạo hình dạng mặc định của khối L.
    void initializeShape() override;

    /// \brief Xoay khối L (theo chiều ngược kim đồng hồ).
    void rotate() override;

    /// \brief Tạo một bản sao của khối L (Prototype Pattern).
    /// \return Con trỏ thông minh chứa đối tượng bản sao của khối L.
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
