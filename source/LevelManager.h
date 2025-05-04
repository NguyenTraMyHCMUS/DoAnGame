#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

/// \file LevelManager.h
/// \brief Định nghĩa lớp LevelManager để quản lý cấp độ và số dòng đã xóa trong trò chơi.


/// \class LevelManager
/// \brief Quản lý cấp độ hiện tại và số dòng đã xóa trong trò chơi.
///
/// Lớp này theo dõi tiến trình của người chơi bằng cách cập nhật cấp độ dựa trên số dòng đã xóa.
/// Việc tách riêng logic này giúp tuân thủ nguyên lý SRP (Single Responsibility Principle) trong SOLID.
class LevelManager {
private:
    int currentLevel;   ///< Cấp độ hiện tại của trò chơi.
    int linesCleared;   ///< Tổng số dòng đã được xóa.

public:
    /// \brief Constructor khởi tạo cấp độ và số dòng đã xóa về 0.
    LevelManager();

    /// \brief Tăng cấp độ hiện tại lên 1.
    void increaseLevel();

    /// \brief Thêm số dòng đã xóa vào tổng số dòng.
    /// \param lines Số dòng vừa được xóa.
    void addClearedLines(int lines);

    /// \brief Lấy cấp độ hiện tại.
    /// \return Cấp độ hiện tại.
    int getLevel() const;

    /// \brief Lấy tổng số dòng đã xóa.
    /// \return Tổng số dòng đã xóa.
    int getLinesCleared() const;

    /// \brief Đặt lại cấp độ và số dòng đã xóa về 0.
    void reset();

    /// \brief Chỉ đặt lại số dòng đã xóa về 0.
    void resetLinesCleared();
};

#endif
