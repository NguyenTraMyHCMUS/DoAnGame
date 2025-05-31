# 🎮 Đồ Án Game Tetris – Hướng Đối Tượng & Cải Tiến
# Cần tải thêm thư viện SFML

## 👩‍💻 Thành viên nhóm

| STT | MSSV      | Họ và Tên                       |
|-----|-----------|---------------------            |
| 1   | 23120300  | Nguyễn Trà My (Nhóm Trưởng)     |
| 2   | 23120302  | Mã Tuyết Ngân                   |
| 3   | 23120311  | Nguyễn Khả Như                  |

---
## Công việc của từng thành viên đã thực hiện
## Tuần 1
### Thành viên 1: Khả Như
- Coi video mẫu  
- Tìm hiểu Git, GitHub  
- Viết file `README.md`  
### Thành viên 2: Tuyết Ngân
- Coi video mẫu  
- Tìm hiểu Git, GitHub  
- Viết file `README.md`  
### Thành viên 3: Trà My
- Tạo repository trên GitHub và phân công công việc nhóm từ video mẫu của thầy  
- Coi video mẫu  
- Tìm hiểu Git, GitHub  
- Viết file `README.md`  
---
## Tuần 2
### Thành viên 1: Khả Như
- Tìm hiểu nguyên lý SOLID và Design Pattern  
- Đề xuất các cải tiến từ video mẫu
- Phát khảo kiến trúc layered  
### Thành viên 2: Tuyết Ngân  
- Tìm hiểu nguyên lý SOLID và Design Pattern  
- Đề xuất các cải tiến từ video mẫu  
- Phát khảo kiến trúc layered  
### Thành viên 3: Trà My
- Tìm hiểu nguyên lý SOLID và Design Pattern  
- Đề xuất các cải tiến từ video mẫu
- Phát khảo kiến trúc layered   
---
## Tuần 3
### Thành viên 1: Khả Như
- Chuyển đổi `Field` thành một lớp độc lập để quản lý lưới chơi  
- Viết các phương thức cơ bản như: `isOccupied`, `isInside`, `setCell`, `clearLines`, ...  
- Có chú thích rõ thuộc tính và phương thức để tiện theo dõi và tạo doxyfile
### Thành viên 2: Tuyết Ngân
- Chuyển đổi `Tetromino` thành một lớp độc lập để quản lý khối Tetris  
- Viết các phương thức: `initializeShape`, `move`, `rotate`, `fall`, ...  
- Có chú thích rõ thuộc tính và phương thức để tiện theo dõi và tạo doxyfile
### Thành viên 3: Trà My
- Tạo lớp `Game` để quản lý vòng lặp chính  
- Kết hợp `Field` và `Tetromino` vào vòng lặp trò chơi  
- Có chú thích rõ thuộc tính và phương thức để tiện theo dõi và tạo doxyfile 
---
## Tuần 4+5
### Thành viên 1: Khả Như
- Tăng tốc độ theo cấp độ (mỗi 10 điểm/1 dòng; đủ 10 dòng tăng level)  
- Hiển thị điểm số và cấp độ ở góc trên bên phải lưới (cập nhật sau mỗi lần thay đổi) trong trạng thái Playing
- Thêm combo điểm:
  - Xóa liên tiếp 2 dòng: x2 điểm
  - 3 dòng: x3 điểm, ...
- Tải doxygen và tạo doxyfile 
- Quay video demo
### Thành viên 2: Tuyết Ngân
- Áp dụng **Factory Pattern** để tạo các khối Tetris từ các class con  
- Xây dựng 3 class và giao diện cho 3 trạng thái: `MainMenu`, `Playing`, `GameOver`
- Thêm hướng dẫn trò chơi vào `MainMenu`
- Áp dụng **State Pattern** để quản lý trạng thái trò chơi: `MainMenu`, `Playing`, `Paused`, `GameOver`
- Tải doxygen và tạo doxyfile 
### Thành viên 3: Trà My
- Hiển thị các khối kế tiếp (1–3 khối) ở góc giữa bên phải trong trạng thái Playing
- Tải doxygen và tạo doxyfile 
- Viết file readme.md
---
## Tuần 6
### Thành viên 1: Khả Như
- Thêm trạng thái nhập tên người dùng
### Thành viên 2: Tuyết Ngân
- Áp dụng S, L, I trong SOLID cho tetromino. Tách các hành vi trong Terminal thành các class riêng xử lí 1 nhiêm vụ và class interface tương ứng. các type Tetromino có thể thay thế cho class cha Tetromino
- Áp dụng S, L, I trong SOLID cho hành vi xoay: Tách class hành vi xoay thành 3 class cho mỗi công việc xoay ngang-dọc (I), xoay theo kim đồng hồ (S, T, Z), ngược chiều kim đồng hồ (J, L). Và O không xoay. Có interface chung cho 3 class. Các rotator có thể thay thế cho nhau. Áp dụng **Factory Pattern** cho rotator.
- Áp dụng **Abstract Factory Pattern** cho ITetrominoComponentFactory 
### Thành viên 3: Trà My
 - Áp dụng S, I cho Game
---
## Tuần 7
### Thành viên 1: Khả Như
- Thêm hiển thị bảng xếp hạng top 3 (Tên - Điểm)
### Thành viên 2: Tuyết Ngân
- Áp dụng O trong SOLID cho class xoay: **Registry Pattern** để quản lí và tạo các đối tượng rotators. **Strategy Pattern** cho ITetrominoRotator để xử lí các hành vi xoay khác nhau cho từng loại Tetromino. **Singleton Pattern** trong RotatorFactoryRegistry. **Auto registration** - tự động đăng ký rotator khi khởi động trong RotatorFactoryInitialized => dễ dàng thêm rotator mới
- Áp dụng D trong SOLID cho class xoay và tetromino: tetromino phụ thuộc vào interface ITetrominoRotator. Factory trả về interface. High-level modules (VD: ITetromino) không phụ thuộc low-level (IRotator)
### Thành viên 3: Trà My
- Áp dụng L, O, D cho Game
---
## Tuần 8
### Thành viên 1: Khả Như
- Tạo file doxygen
- Viết unitest
### Thành viên 2: Tuyết Ngân
- Hoàn tất nguyên lí **SOLID**, **design pattern** cho tetromino. Component Substitutability, Rotator Substitutability, Tetromino Substitutability
- Áp dụng O trong SOLID cho tetromino : **Registry Pattern** để quản lí quản lý các factory của Tetromino. **Singleton Pattern** trong TetrominoFactoryRegistry. **Auto registration** - tự động đăng ký các loại tetromino khi compile => dễ dàng thêm tetromino mới
- Áp dụng D trong SOLID cho tetromino: tetromino phụ thuộc vào interface. Factory trả về interface. High-level modules không phụ thuộc low-level
- Hỗ trợ viết file readme.md
### Thành viên 3: Trà My
- Tổng hợp lại cách viết file
- Thêm hiệu ứng khi xóa dòng, x dòng
- Vẽ diagram
- Quay video demo
- Viết file readme.md
---
## 🔹 Tỉ lệ đóng góp vào dự án
| Thành viên       | Tỉ lệ đóng góp |
|------------------|----------------|
| Nguyễn Trà My    |      33%      |
| Mã Tuyết Ngân    |      34%      |
| Nguyễn Khả Như   |      33%      |

---

## 🔹 Tỉ lệ điểm : Chia đều cho mỗi thành viên

---

## 🔹 Mô tả các yêu cầu trong cách thức đánh giá
Dựa trên tiến trình nhóm bạn đã cung cấp, cùng với cấu trúc file mã nguồn từ hai ảnh chụp, dưới đây là bản mô tả chi tiết **Cách thức đánh giá** theo từng tiêu chí của đồ án, giúp giáo viên dễ theo dõi:

---

### 🧑‍🤝‍🧑 **1. Teamwork (15%)**

**Mô tả đánh giá:**

* **Phân công rõ ràng theo từng tuần**, thể hiện trong kế hoạch từ Tuần 1–5. Mỗi thành viên đảm nhận phần riêng biệt như:

  * Khả Như: Xử lý `Field`, quản lý điểm & cấp độ.
  * Tuyết Ngân: Thiết kế khối Tetris, giao diện UI, quản lý trạng thái trò chơi.
  * Trà My: Vòng lặp chính `Game`, khối kế tiếp, cấu trúc tổng thể chương trình.

* **Tiến độ được theo dõi đều đặn trên GitHub**:

  * Có phân công người tạo repository (`Trà My`, Tuần 1).
  * Commit chia đều, không dồn vào cuối.
  * Có sử dụng file `README.md` do cả 3 thành viên viết ngay từ Tuần 1.

* **Nhóm trưởng (Trà My)** có vai trò dẫn dắt, khởi tạo repo, gộp code, hỗ trợ kết hợp các thành phần và Doxygen tài liệu hóa kiến trúc.
![image](https://github.com/user-attachments/assets/750ee903-c14a-424c-9e94-a6cfc54c3fbb)


---

### 🎨 **2. UI/UX (20%)**

**Mô tả đánh giá:**

* **Cài đặt lại chức năng mã nguồn mẫu theo hướng đối tượng (3%)**:

  * `Field`, `Tetromino`, `Game` tách thành các lớp riêng, mỗi lớp có `.cpp` và `.h` rõ ràng.
  * Áp dụng nguyên lý OOP với `ITetromino` là interface trừu tượng, và các lớp kế thừa như `STetromino`, `ZTetromino`,...

* **Chức năng cải tiến (14%)**:
* Có thêm điểm số, level, chơi lại khi game over, nhập tên người chơi
* Combo điểm khi xóa x dòng + cấp độ tự tăng tương ứng, cập nhật tốc độ theo cấp độ (level)
* Hiển thị khối kế tiếp (1–3 khối): Giúp người chơi có chiến thuật
* Xây dựng 4 trạng thái giao diện
* Hướng dẫn chơi riêng biệt (InstructionsState) trong MainMenu
* Hiệu ứng khi xóa dòng, combo x dòng
* Số liệu tổng kết: điểm cao nhất, điểm vòng hiện tại, tên người chơi

* **Bố cục giao diện hợp lý (3%)**:

  * Sử dụng các lớp giao diện riêng biệt để tách biệt logic với hiển thị.
  * Có hỗ trợ hình ảnh, âm thanh, và hướng dẫn trước khi chơi (`InstructionsState`).

---

### 🏗️ **3. Kiến trúc phần mềm & Design Pattern (20%)**

**Mô tả đánh giá:**

* Thiết kế theo **Layered Architecture**:

  * Logic xử lý (`Field`, `Tetromino`, `Game`, `ScoreManager`,...) tách khỏi giao diện (`State`).
  * Mỗi lớp phụ trách một nhiệm vụ rõ ràng, đúng nguyên tắc **SRP** (Single Responsibility).

* **Design Pattern áp dụng**:
  * `Factory Pattern`: `TetrominoFactory` để quản lý tạo các loại Tetromino, `RotatorFactory` quản lý tạo các loại rotator
  * `Abstract Factory Pattern`: `ITetrominoComponentFactory` factory chung cho tất cả component (rotator có nhiều kiểu xoay), thuận tiện cho các component phát triển sau này
  * `Registry Pattern`: `TetrominoFactoryRegistry` quản lý đăng ký cho Tetromino Factory, `RotatorFactoryRegistry` quản lý đăng ký cho Rotator Factory
  * `Singleton Pattern`: `CongifgurationManager` quản lý cấu hình game, `ColorMapper` quản lý màu sắc cho Tetromino
  * `Strategy Pattern`: `ITetrominoRotator`, `StandardRotator`,.. quản lý cách xoay khác nhau của khối Tetromino. `IRenderingStrategy`,.. quản lý vẽ khối hiện tại, khối tiếp theo lên lưới. 
  * `State Pattern`: `IGameState`, `MainMenuState`, `PlayingState`, `PausedState`, `GameOverState`,... quản lý, tạo và chuyển đổi trạng thái dễ dàng hơn
  * `Observer Pattern`: `TetrominoEventManager`,.. quản lý và thông báo các sự kiện liên quan Tetromino trong game


* Áp dụng **nguyên lý SOLID** toàn bộ trong cách chia class, interface, dependency injection.
  
## 1. S - Single Responsibility Principle (Nguyên lý trách nhiệm đơn)

Mỗi lớp trong dự án đảm nhiệm một nhiệm vụ duy nhất và rõ ràng:

### 🧱 **Entities**
- `Point`: Quản lý tọa độ 2D.
- `Field`: Quản lý lưới trò chơi (_field 2 chiều), kiểm tra và xóa các dòng hoàn chỉnh.
- `TetrominoConstants`: Lưu trữ các hằng số (constant) liên quan đến Tetromino.

### 🔧 **Tách biệt hành vi (Components folder)**  
- `TetrominoValidator`: Kiểm tra tính hợp lệ của vị trí Tetromino.  
- `TetrominoMovement`: Xử lý di chuyển ngang và rơi xuống.  
- `TetrominoRenderer`: Xử lý logic hiển thị và vẽ lên màn hình.  
- `TetrominoState`: Quản lý backup và restore trạng thái của khối.  
- `TetrominoLocker`: Cố định Tetromino vào lưới.  

#### 🔄 Logic xoay:
- `StandarRotator`: Xoay theo chiều kim đồng hồ.  
- `CounterclockwiseRotator`: Xoay ngược chiều kim đồng hồ.  
- `IRotator`: Xử lý xoay ngang/dọc dành riêng cho khối I.

### 🏭 **Tách biệt logic khởi tạo (Factories folder)**
- `TetrominoFactory`: Tạo đối tượng Tetromino.
- `RotatorFactory`: Tạo các đối tượng xoay tương ứng cho từng loại Tetromino.
- `DefaultTetrominoComponentFactory`: Tạo các components cho Tetromino.

### 🖼 **Graphics**
- `ResourceManager`: Quản lý tài nguyên đồ họa.
- `GameRenderer`: Vẽ các thành phần của game.
- `FlashLineEffect`: Hiệu ứng nhấp nháy khi xóa hàng.

### 🎮 **Input**
- `InputManager`: Quản lý và xử lý đầu vào từ người dùng.
- `InputPlayerName`: Xử lý nhập tên người chơi.

### 🧠 **Game Logic**
- `GameLogic`: Logic chính của trò chơi.
- `ScoreManager`: Quản lý điểm số.
- `LevelManager`: Quản lý level và tăng tốc độ trò chơi.

### 🎭 **States**
- `MainMenuState`: Trạng thái menu chính.
- `InstructionsState`: Trạng thái hiển thị hướng dẫn chơi.
- `PlayerNameState`: Trạng thái nhập tên người chơi.
- `PlayingState`: Trạng thái chơi game.
- `PausedState`: Trạng thái tạm dừng.
- `GameOverState`: Trạng thái game over và xử lý chơi lại.

### ⏱ **Time**
- `GameTime`: Quản lý thời gian cập nhật khung hình/game.

---

## 2. O - Open/Closed Principle (Nguyên lý mở rộng mà không sửa đổi)

### ✅ Registry Pattern cho mở rộng:
- `TetrominoFactoryRegistry`: Cho phép đăng ký factory mới mà không sửa code registry.
- `RotatorFactoryRegistry`: Cho phép thêm các chiến lược xoay mới mà không cần thay đổi code hiện tại.

### ⚙️ Hệ thống Auto-registration:
- `Register_Tetromino` macro: Chỉ cần 1 dòng để thêm loại Tetromino mới.
- `TetrominoAutoRegistrar` (template): Tự động đăng ký khối Tetromino khi compile.

### 🧩 Strategy Pattern:
- `ITetrominoRotator`: Có thể mở rộng nhiều kiểu xoay khác nhau (Standar, I, CounterClockwise).
- `IRenderingStrategy`: Dễ dàng thêm các chiến lược hiển thị mới mà không sửa interface hiện tại.

---

## 3. L - Liskov Substitution Principle (Nguyên lý thay thế Liskov)
### ✅ Các Tetromino có thể thay thế cho nhau 
#### Examples:
```cpp
std::unique_ptr<Tetromino> tetromino;
tetromino = std::make_unique<LTetromino>();
tetromino = std::make_unique<ZTetromino>();
```
### ✅ Các Component Interface có thể thay thế được bởi các class con kế thừa tương ứng
#### Examples:
```cpp
std::unique_ptr<ITetrominoMovement> movement;
movement = std::make_unique<TetrominoMovement>();
movement->move(dx);

std::unique_ptr<ITetrominoRotator> rotator;
rotator = std::make_unique<IRotator>();
rotator->rotate(_blocks);
rotator = std::make_unique<StandardRotator>();
rotator->rotate(_blocks);
```
### ✅ Các State có thể thay thế cho nhau 
#### Examples:
```cpp
std::unique_ptr<IGameState> state;
state = std::make_unique<MainMenuState>(game);
state = std::make_unique<GameOverState>(game);
```

---
## 4. I - Interface Segregation Principle (Nguyên lý phân tách interface)

- Các interface được chia nhỏ tương ứng với từng hành vi cụ thể, giúp các lớp chỉ cần implement những gì chúng thực sự sử dụng.
- Tất cả các interface đều được đặt trong thư mục `Interface`, ví dụ:
  - `ITetrominoMovement`: chỉ định nghĩa hành vi di chuyển.
  - `ITetrominoRotator`: chỉ định nghĩa hành vi xoay khối.
  - `ITetrominoRenderer`: chỉ định nghĩa hành vi vẽ.
  - `ITetrominoState`: định nghĩa hành vi lưu/khôi phục trạng thái.
  - `ITetrominoLocker`: định nghĩa hành vi cố định khối.
- Và các interface tương ứng trong từng thư mục

➡️ Điều này giúp code dễ bảo trì, tránh "interface béo" (fat interface) và tăng tính linh hoạt khi mở rộng.

---

## 5. D - Dependency Inversion Principle (Nguyên lý đảo ngược phụ thuộc)

- Lớp `Tetromino` không phụ thuộc vào các lớp cụ thể (concrete class) mà phụ thuộc vào **interface** (lớp trừu tượng).
- Sử dụng **Dependency Injection** qua constructor để truyền các thành phần cần thiết.
  
### 🔁 Áp dụng Dependency Injection:
```cpp
Tetromino(
    std::unique_ptr<ITetrominoMovement> movement,
    std::unique_ptr<ITetrominoRotator> rotator,
    std::unique_ptr<ITetrominoRenderer> renderer,
    std::unique_ptr<ITetrominoState> state,
    std::unique_ptr<ITetrominoLocker> locker
);
```
- Factory DefaultTetrominoComponentFactory, RotatorFactory,... trả về interface.
- High-level modules không phụ thuộc low-level. VD: ITetromino không phụ thuộc IRotator (không trực tiếp tạo  IRotator) mà thông qua rotator factory 


---

### ✅ **4. Đảm bảo chất lượng (20%)**

**Mô tả đánh giá:**

- **Coding Convention:**  
  - **Đặt tên:**  
    - Lớp: `PascalCase` (ví dụ: `Tetrimino`, `BoardManager`).  
    - Hàm: `camelCase` (ví dụ: `rotatePiece`, `clearLine`).  
    - Biến: `lower_snake_case` (ví dụ: `current_piece`, `line_count`).  
    - Thành viên lớp: thêm `_` đầu (ví dụ: `_position`, `_board`).  
  - **Định dạng:** Thụt lề bằng **tab**, dấu `{` cùng dòng với khai báo hàm/class.  
  - **Comments:** Dùng **Doxygen** (`/** ... */`) cho lớp/hàm quan trọng, tránh ghi chú dư thừa. 
* **Tài liệu hóa bằng Doxygen**:

  * Từ tuần 3, toàn bộ class như `Game`, `Field`, `Tetromino`,... đều có mô tả rõ ràng qua Doxygen.
* **Đảm bảo không lỗi logic, chia lớp gọn gàng**, dễ mở rộng và bảo trì.

---

### 📄 **5. Tài liệu mô tả kiến trúc phần mềm và các module (10%)**

**Mô tả đánh giá:**

* Đã viết tài liệu chi tiết mô tả:

  * Cấu trúc lớp.
  * Mối quan hệ giữa các thành phần (`Game` chứa `Field`, `Tetromino`; các `State` hoạt động qua `GameState`).
  * Flow chương trình: từ `MainMenu` → `Playing` → `Paused` hoặc `GameOver`.

* Có sơ đồ class (nếu cần, nhóm có thể trích từ Doxygen), giải thích vai trò từng module: `LevelManager`, `ScoreManager`,...

---

### 🚀 **6. Các chủ đề nâng cao (15%)**

**Mô tả đánh giá:**
* **Registry Pattern**
* **State Pattern**
* **Abstract Factory Pattern**
* **Observer Pattern**
* **Auto registration** - tự động đăng ký các loại tetromino khi compile
  
## Thư viện: Tải thư viện SFML 
## 🔹 Video demo

- Link: [https://www.youtube.com/watch?v=TfmBUhhInyo](https://www.youtube.com/watch?v=DL3vBhwOEOY)

---




