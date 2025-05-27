#ifndef TETROMINO_AUTO_REGISTRAR_H
#define TETROMINO_AUTO_REGISTRAR_H

#include "TetrominoFactoryRegistry.h"

/**
 * @file TetrominoAutoRegistrar.h
 * @brief Định nghĩa lớp TetrominoAutoRegistrar để tự động đăng ký các loại Tetromino
 */

/**
 * @class TetrominoAutoRegistrar
 * @brief Template class giúp tự động đăng ký các lớp Tetromino vào registry.
 * 
 * Khi tạo một instance của lớp này với template parameter là một lớp Tetromino cụ thể,
 * nó sẽ đăng ký một factory function tạo đối tượng Tetromino đó vào TetrominoFactoryRegistry.
 * 
 * Việc đăng ký này cho phép hệ thống tạo ra các Tetromino dựa trên id hoặc tên,
 * mà không cần phải chỉnh sửa trực tiếp factory hoặc registry.
 * 
 * Lưu ý:
 * - Đây là một template class, nên định nghĩa phải nằm trong header (không có .cpp riêng).
 */
template<typename T>
class TetrominoAutoRegistrar {
public:
    /**
     * @brief Constructor tự động đăng ký factory function cho lớp Tetromino T
     * @param id Mã số duy nhất của loại Tetromino
     * @param name Tên duy nhất của loại Tetromino
     * 
     * Constructor sẽ gọi hàm registerFactory của TetrominoFactoryRegistry,
     * truyền vào id, name và một lambda tạo mới đối tượng kiểu T.
     */
    TetrominoAutoRegistrar(int id, const std::string& name) {
        TetrominoFactoryRegistry::getInstance().registerFactory(
            id, name, []() { return std::make_unique<T>(); }
        );
    }
};

/**
 * @brief Macro tiện lợi để đăng ký một loại Tetromino
 * 
 * Macro này sẽ tạo một biến static kiểu TetrominoAutoRegistrar<TetrominoClass>,
 * đảm bảo hàm đăng ký được gọi tự động khi chương trình khởi động.
 * 
 * Ví dụ:
 *   REGISTER_TETROMINO(MyTetrominoClass, 0, "I")
 * 
 * Sẽ tạo biến static:
 *   static TetrominoAutoRegistrar<MyTetrominoClass> _auto_registrar_MyTetrominoClass(0, "I");
 * 
 * Qua đó tự động đăng ký MyTetrominoClass với id = 0 và tên "I".
 */
#define REGISTER_TETROMINO(TetrominoClass, id, name) \
    static TetrominoAutoRegistrar<TetrominoClass> \
    _auto_registrar_##TetrominoClass(id, name);

#endif
