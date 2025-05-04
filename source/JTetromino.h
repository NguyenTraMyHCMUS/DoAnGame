#ifndef JTETROMINO_H
#define JTETROMINO_H

/// \file JTetromino.h
/// \brief Định nghĩa lớp JTetromino đại diện cho khối hình J trong trò chơi Tetris.


#include "Tetromino.h"

/// \class JTetromino
/// \brief Đại diện cho khối Tetromino hình chữ J.
///
/// Lớp kế thừa từ lớp cơ sở Tetromino, định nghĩa cụ thể về hình dạng, cách xoay
/// và khả năng tạo bản sao của khối J.
class JTetromino : public Tetromino {
public:
    /// \brief Constructor khởi tạo khối J.
    JTetromino();

    /// \brief Destructor ảo mặc định.
    ~JTetromino() override = default;

    /// \brief Khởi tạo hình dạng mặc định của khối J.
    void initializeShape() override;

    /// \brief Xoay khối J theo quy luật xác định (ngược chiều kim đồng hồ).
    void rotate() override;

    /// \brief Tạo bản sao mới của khối J.
    /// \return Trả về một con trỏ thông minh chứa đối tượng bản sao.
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
