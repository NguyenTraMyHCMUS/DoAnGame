#ifndef TETROMINO_H
#define TETROMINO_H

/**
 * @file Tetromino.h
 * @brief Định nghĩa lớp trừu tượng Tetromino cho các khối Tetris trong trò chơi.
 * 
 * Lớp này định nghĩa các thuộc tính và phương thức cần thiết để quản lý các khối Tetris,
 * bao gồm việc khởi tạo hình dạng, xoay, di chuyển, vẽ, kiểm tra tính hợp lệ của khối trong lưới và lưu trữ trạng thái của khối.
 */

#include "../Entities/Field.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "Point.h"
#include "Interface/ITetrominoValidator.h"
#include "Interface/ITetrominoState.h"
#include "Interface/ITetrominoRenderer.h"
#include "Interface/ITetrominoMovement.h"
#include "Interface/ITetrominoLocker.h"
#include "Interface/ITetrominoRotator.h"
#include "Interface/ITetrominoComponentFactory.h"

/**
 * @class Tetromino
 * @brief Lớp cơ sở trừu tượng đại diện cho khối Tetris trong trò chơi
 * 
 * Lớp này quản lý các thao tác như: xoay, di chuyển, vẽ, kiểm tra tính hợp lệ và lưu trữ trạng thái của khối.
 */

class Tetromino {
protected:
    Point _blocks[4]; /**< Mảng chứa 4 ô của khối Tetris */
    Point _backup[4]; /**< Lưu trạng thái khối để khôi phục */
    int _color;     /**< Màu sắc của khối */
    int _cellSize; /**< Kích thước của mỗi ô trong khối */
    
    std::unique_ptr<ITetrominoValidator> _validator;
    std::unique_ptr<ITetrominoState> _state;
    std::unique_ptr<ITetrominoRenderer> _renderer;
    std::unique_ptr<ITetrominoMovement> _movement;
    std::unique_ptr<ITetrominoLocker> _locker;
    std::unique_ptr<ITetrominoRotator> _rotator;

    ITetrominoComponentFactory* _componentFactory;
public:
    explicit Tetromino(ITetrominoComponentFactory& factory);

    /**
     * @brief Constructor khởi tạo khối Tetris.
     * 
     * Khởi tạo các giá trị mặc định cho khối Tetris.
     */
    Tetromino();
    Tetromino(const Tetromino& other);
    Tetromino& operator=(const Tetromino& other);

    /**
     * @brief Destructor ảo để giải phóng bộ nhớ.
     * 
     * Phương thức này sẽ giải phóng bộ nhớ khi đối tượng bị hủy.
     */
    virtual ~Tetromino() = default;

    /**
     * @brief Khởi tạo hình dạng của khối Tetris.
     * 
     * Phương thức này phải được cài đặt trong các lớp kế thừa để khởi tạo hình dạng cụ thể của từng khối Tetris.
     */
    virtual void initializeShape() = 0;
    virtual std::string getTypeName() const = 0;

      /**
     * @brief Tạo một bản sao của khối Tetris.
     * 
     * Phương thức này tạo một bản sao của khối Tetris hiện tại.
     * 
     * @return Một con trỏ duy nhất đến bản sao của khối Tetris.
     */
    virtual std::unique_ptr<Tetromino> clone() const = 0;

    /**
     * @brief Xoay khối Tetris.
     * 
     * Phương thức này xoay khối Tetris theo quy tắc: O không xoay, I xoay ngang và dọc, {Z, T, S} xoay theo chiều kim đồng hồ,
     * {L, J} xoay ngược chiều kim đồng hồ.
     */

    virtual void rotate();

    /**
     * @brief Di chuyển khối theo chiều ngang.
     * 
     * Phương thức này di chuyển khối Tetris sang bên phải hoặc trái theo hướng dx.
     * 
     * @param dx Giá trị di chuyển theo chiều ngang (âm là sang trái, dương là sang phải).
     */
    void move(int dx);

    /**
     * @brief Di chuyển khối xuống dưới.
     * 
     * Phương thức này di chuyển khối xuống một ô.
     */
    void fall();

    /**
     * @brief Kiểm tra tính hợp lệ của vị trí hiện tại của khối.
     * 
     * Phương thức này kiểm tra xem vị trí hiện tại của khối có hợp lệ trong lưới hay không.
     * 
     * @param field Lưới chơi.
     * @return True nếu vị trí hợp lệ, false nếu không hợp lệ.
     */
    bool isValid(const Field &field) const;

    /**
     * @brief Cố định khối vào lưới.
     * 
     * Phương thức này cố định khối vào vị trí hiện tại trên lưới sau khi nó không thể di chuyển thêm.
     * 
     * @param field Lưới chơi.
     */
    void lock(Field &field) const;

    /**
     * @brief Vẽ khối lên cửa sổ trò chơi.
     * 
     * Phương thức này vẽ khối Tetris lên cửa sổ trò chơi bằng cách sử dụng sprite.
     * 
     * @param window Cửa sổ render nơi khối sẽ được vẽ.
     * @param sprite Sprite để hiển thị khối.
     */
    void draw(sf::RenderWindow &window, sf::Sprite &sprite) const;

     /**
     * @brief Lưu trạng thái hiện tại của khối.
     * 
     * Phương thức này lưu lại trạng thái hiện tại của các ô trong khối để có thể khôi phục sau.
     */
    void backupState();

    /**
     * @brief Khôi phục trạng thái từ backup.
     * 
     * Phương thức này khôi phục lại trạng thái của các ô trong khối từ backup trước đó.
     */
    void restoreState();

    /**
     * @brief Thay đổi kích thước ô trong khối.
     * 
     * Phương thức này thay đổi kích thước của mỗi ô trong khối Tetris.
     * 
     * @param size Kích thước mới của ô.
     */

    void setCellSize(int size);

    /**
     * @brief Lấy danh sách các ô trong khối.
     * 
     * Phương thức này trả về mảng các ô trong khối Tetris.
     * 
     * @return Con trỏ đến mảng các ô của khối.
     */
    const Point* getBlocks() const;

    /**
     * @brief Thiết lập màu sắc cho khối.
     * 
     * Phương thức này thiết lập màu sắc cho khối Tetris.
     * 
     * @param color Mã màu sắc của khối.
     */
    void setColor(int color);

    /**
     * @brief Lấy màu sắc của khối.
     * 
     * Phương thức này trả về màu sắc hiện tại của khối Tetris.
     * 
     * @return Mã màu sắc của khối.
     */
    int getColor() const;

    /**
     * @brief Lấy tọa độ x của ô tại chỉ số i.
     * 
     * Phương thức này trả về tọa độ x của ô tại chỉ số i trong mảng các ô của khối.
     * 
     * @param i Chỉ số của ô trong mảng.
     * @return Tọa độ x của ô.
     */
    int getX(int i) const;

    /**
     * @brief Lấy tọa độ y của ô tại chỉ số i.
     * 
     * Phương thức này trả về tọa độ y của ô tại chỉ số i trong mảng các ô của khối.
     * 
     * @param i Chỉ số của ô trong mảng.
     * @return Tọa độ y của ô.
     */
    
    int getY(int i) const;
    /**
     * @brief Thiết lập con trỏ đến bộ xoay cho khối Tetris.
     * 
     * @param rotator Con trỏ đến đối tượng ITetrominoRotator.
     */
    void setRotator(std::unique_ptr<ITetrominoRotator> rotator); 
    void setValidator(std::unique_ptr<ITetrominoValidator> validator);
    void setRenderer(std::unique_ptr<ITetrominoRenderer> renderer);
    void setMovement(std::unique_ptr<ITetrominoMovement> movement);
    void setLocker(std::unique_ptr<ITetrominoLocker> locker);
    void setState(std::unique_ptr<ITetrominoState> state);

protected:
    virtual void initializeComponents();
    /**
     * @brief Sao chép các thành phần từ một khối Tetris khác.
     * 
     * Phương thức này sao chép các thuộc tính và thành phần của khối Tetris từ đối tượng khác.
     * 
     * @param other Đối tượng Tetromino khác để sao chép.
     */
    void cloneComponents(const Tetromino& other);
};

#endif
