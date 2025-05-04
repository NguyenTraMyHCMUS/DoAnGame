#ifndef ITETROMINO_H
#define ITETROMINO_H

/// \file ITetromino.h
/// \brief Định nghĩa lớp ITetromino đại diện cho khối hình I trong Tetris.
/// \author [Tên nhóm hoặc sinh viên]
/// \date [Ngày tạo]

#include "Tetromino.h"

/// \class ITetromino
/// \brief Lớp đại diện cho khối Tetromino hình chữ I.
///
/// Lớp này kế thừa từ lớp cơ sở Tetromino, định nghĩa hình dạng và hành vi riêng của khối I.
/// Bao gồm các chức năng khởi tạo hình dạng, xoay khối và clone bản sao.
class ITetromino : public Tetromino {
public:
    /// \brief Constructor khởi tạo khối I.
    ITetromino();

    /// \brief Destructor ảo mặc định.
    ~ITetromino() override = default;

    /// \brief Khởi tạo hình dạng mặc định cho khối I.
    void initializeShape() override;

    /// \brief Xoay khối I (chuyển giữa ngang và dọc).
    void rotate() override;

    /// \brief Tạo một bản sao của khối I.
    /// \return Trả về con trỏ thông minh chứa bản sao khối I.
    std::unique_ptr<Tetromino> clone() const override;
};

#endif
