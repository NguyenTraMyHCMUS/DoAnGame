#ifndef ROTATOR_FACTORY_H
#define ROTATOR_FACTORY_H

#include "../Interface/ITetrominoRotator.h"
#include "../Components/TypeRotation/StandardRotator.h"
#include "../Components/TypeRotation/IRotator.h"
#include "../Components/TypeRotation/CounterclockwiseRotator.h"
#include <memory>
#include <string>
#include "../Registries/RotatorFactoryRegistry.h"

/**
 * @file RotatorFactory.h
 * @brief Định nghĩa lớp RotatorFactory để tạo các rotator cho các khối Tetromino trong trò chơi Tetris.
 */

/**
 * @class RotatorFactory
 * @brief Factory chịu trách nhiệm tạo các đối tượng rotator phù hợp với từng loại khối Tetromino.
 * 
 * Lớp này cung cấp một phương thức tĩnh để tạo ra các đối tượng rotator (thuộc interface ITetrominoRotator) 
 * tương ứng với loại khối Tetromino được yêu cầu (I, J, L, S, T, Z, O).
 * Việc sử dụng factory giúp tách biệt quá trình khởi tạo đối tượng rotator khỏi phần logic sử dụng, 
 * giúp chương trình dễ mở rộng và bảo trì hơn.
 */
class RotatorFactory {
public:
    /**
     * @brief Tạo một rotator phù hợp với loại khối Tetromino được chỉ định.
     * 
     * Phương thức này nhận tên loại khối (ví dụ: "I", "J", "L", "S", "T", "Z", "O") và trả về một 
     * con trỏ thông minh unique_ptr trỏ đến đối tượng rotator tương ứng, có thể là StandardRotator, 
     * CounterclockwiseRotator hoặc các lớp rotator khác.
     * 
     * @param type Chuỗi tên loại khối Tetromino.
     * @return std::unique_ptr<ITetrominoRotator> Con trỏ duy nhất đến rotator tương ứng.
     */
    static std::unique_ptr<ITetrominoRotator> createRotator(const std::string& type);
};

#endif
