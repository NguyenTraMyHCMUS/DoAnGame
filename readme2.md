# 🎮 Đồ Án Game Tetris – Hướng Đối Tượng & Cải Tiến

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
- Xây dựng giao diện cho 3 trạng thái: `MainMenu`, `Playing`, `GameOver`
- Thêm hướng dẫn trò chơi vào `MainMenu`
- Áp dụng **State Pattern** để quản lý trạng thái trò chơi: `MainMenu`, `Playing`, `Paused`, `GameOver`
- Tải doxygen và tạo doxyfile 
### Thành viên 3: Trà My
- Hiển thị các khối kế tiếp (1–3 khối) ở góc giữa bên phải trong trạng thái Playing
- Tải doxygen và tạo doxyfile 
- Viết file readme.md
---
## 🔹 Tỉ lệ đóng góp vào dự án
| Thành viên       | Tỉ lệ đóng góp |
|------------------|----------------|
| Nguyễn Trà My    |      100%      |
| Mã Tuyết Ngân    |      100%      |
| Nguyễn Khả Như   |      100%      |

---

## 🔹 Tỉ lệ điểm 
| Thành viên       |  Tỉ lệ    | 
|------------------|-----------|
| Nguyễn Trà My    |    10     |
| Mã Tuyết Ngân    |    10     |
| Nguyễn Khả Như   |    10     |

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
![image](https://github.com/user-attachments/assets/af7b4b12-0e32-4179-9249-931754c9a110)


---

### 🎨 **2. UI/UX (20%)**

**Mô tả đánh giá:**

* **Cài đặt lại chức năng mã nguồn mẫu theo hướng đối tượng (3%)**:

  * `Field`, `Tetromino`, `Game` tách thành các lớp riêng, mỗi lớp có `.cpp` và `.h` rõ ràng.
  * Áp dụng nguyên lý OOP với `ITetromino` là interface trừu tượng, và các lớp kế thừa như `STetromino`, `ZTetromino`,...

* **Chức năng cải tiến (14%)**:

  * Tính điểm combo (Khả Như – Tuần 5).
  * Giao diện trạng thái gồm `MainMenuState`, `PlayingState`, `PausedState`, `GameOverState`.
  * Hiển thị khối kế tiếp (`NextTetrominoPreview`) – do Trà My phụ trách.
  * Cập nhật tốc độ theo cấp độ (level) – Tuần 5.

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

  * `Factory Pattern`: `TetrominoFactory` tạo khối từ tên loại (do Tuyết Ngân triển khai – Tuần 5).
  * `State Pattern`: `GameState`, `MainMenuState`, `PlayingState`, `PausedState`, `GameOverState` – rõ ràng trong source.
  * Interface `ITetromino` đóng vai trò chuẩn hóa đa hình các khối.

* Áp dụng **nguyên lý SOLID** toàn bộ trong cách chia class, interface, dependency injection.

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

* **Combo điểm + cấp độ tự tăng** (Khả Như – Tuần 5): Cơ chế phức tạp, tính theo nhiều dòng liên tục.
* **Hiển thị khối kế tiếp (1–3 khối)**: Giúp người chơi có chiến thuật – Trà My phụ trách.
* **Hướng dẫn chơi riêng biệt (InstructionsState)** – tự mở rộng từ mẫu.
* **Hình ảnh động**, **chuyển trạng thái mềm mại** – Tuyết Ngân triển khai.

## Thư viện: Tải thư viện SFML 
## 🔹 Video demo

- Link: https://www.youtube.com/watch?v=TfmBUhhInyo

---




