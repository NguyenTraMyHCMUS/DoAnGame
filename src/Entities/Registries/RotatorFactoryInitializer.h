#include "RotatorFactoryRegistry.h"
#include "../Components/TypeRotation/StandardRotator.h"
#include "../Components/TypeRotation/IRotator.h"
#include "../Components/TypeRotation/CounterclockwiseRotator.h"

/**
 * @file RotatorFactoryInitializer.h
 * @brief Định nghĩa lớp RotatorFactoryInitializer để khởi tạo và đăng ký các rotator cho các loại Tetromino khi chương trình bắt đầu.
 */

/**
 * @class RotatorFactoryInitializer
 * @brief Lớp chịu trách nhiệm đăng ký các rotator tương ứng cho từng loại Tetromino vào registry.
 * 
 * Khi một thể hiện của lớp này được tạo, nó sẽ tự động đăng ký các rotator như StandardRotator, 
 * CounterclockwiseRotator,... với tên các loại khối như "I", "J", "L", "S", "T", "Z", "O".
 * Điều này đảm bảo rằng các rotator sẽ sẵn sàng được sử dụng trong suốt vòng đời chương trình.
 */
class RotatorFactoryInitializer {
public:
    /**
     * @brief Constructor của RotatorFactoryInitializer.
     * 
     * Trong constructor này, các rotator sẽ được đăng ký với registry thông qua các lệnh gọi hàm tương ứng.
     */
    RotatorFactoryInitializer();
};

// Khai báo một biến static toàn cục để tự động gọi constructor và thực hiện việc đăng ký rotators khi chương trình bắt đầu
static RotatorFactoryInitializer _init;
