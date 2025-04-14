# 🎮 Đồ Án Game Tetris – Hướng Đối Tượng & Cải Tiến

## 👩‍💻 Thành viên nhóm

| STT | MSSV      | Họ và Tên                       |
|-----|-----------|---------------------            |
| 1   | 23120300  | Nguyễn Trà My (Nhóm Trưởng)     |
| 2   | 23120302  | Mã Tuyết Ngân                   |
| 3   | 23120311  | Nguyễn Khả Như                  |

---

## I. Mục tiêu đồ án

- Đồ án nhằm tái cấu trúc và nâng cấp game Tetris từ mã nguồn gốc (theo [video gốc](https://www.youtube.com/watch?v=zH_omFPqMO4)) từ cách tiếp cận **thủ tục** sang **hướng đối tượng (OOP)**.
- Áp dụng các nguyên tắc và thực hành chuyên nghiệp:
  - **SOLID principles**
  - **Design Patterns**
  - **Dependency Injection**
  - **Kiến trúc nhiều lớp (Layered Architecture)**
  - **Đảm bảo chất lượng mã nguồn**
- Bổ sung tính năng mới nhằm nâng cao trải nghiệm người chơi.

---

## II. Phân tích hiện trạng sản phẩm (theo video)

- **Phương pháp lập trình**: Thủ tục
- **Vấn đề**:
  - Logic tập trung vào `main()`, thiếu phân chia trách nhiệm.
  - Khó tái sử dụng và mở rộng.
- **Tính năng hiện có**:
  - Tetrimino rơi tự động.
  - Di chuyển ngang, xoay, rơi nhanh.
  - Xóa hàng khi đầy.

---

## III. Các đề xuất cải tiến

### 1. Thiết kế kiến trúc phần mềm – **Layered Architecture**

| Layer              | Vai trò chính                                               |
|--------------------|-------------------------------------------------------------|
| **Presentation**   | Hiển thị UI, khung game, hiệu ứng qua `Renderer` (SDL2).   |
| **Game Logic**     | Quản lý gameplay (điểm số, trạng thái game, điều khiển).   |
| **Input**          | Tách rời nhập liệu bàn phím (`InputHandler`).              |
| **Core**           | Quản lý tài nguyên (`AssetManager`, `ConfigLoader`).       |

- **Luồng hoạt động**:  
  `InputHandler` → `GameManager` → `Board` + `Tetrimino` → `Renderer`

### 2. Các lớp chính & phân tích trách nhiệm (SRP – Single Responsibility)

- `GameManager`: quản lý vòng lặp chính (update/draw).
- `Board`: quản lý lưới và va chạm.
- `Tetrimino`: trạng thái, di chuyển, xoay.
- `Renderer`: hiển thị mọi thứ.
- `UI`: menu, điểm số, hiệu ứng.
- `InputHandler`: ánh xạ bàn phím → hành động.
- `ScoreManager`, `LevelManager`: tính toán và cập nhật điểm/cấp.

---

## IV. Áp dụng SOLID & Design Patterns

### 1. **SOLID Principles**

| Nguyên tắc | Cách áp dụng trong Tetris |
|------------|----------------------------|
| SRP        | Mỗi lớp chỉ đảm nhận một vai trò (Game, UI, Logic). |
| OCP        | Dễ thêm loại khối mới hoặc trạng thái game mà không sửa lớp cũ. |
| LSP        | Các Tetrimino kế thừa từ `BasePiece` và dùng hoán vị an toàn. |
| ISP        | Tách `IRenderable`, `IUpdatable`, `IControllable`. |
| DIP        | Inject `IRenderer`, `ISoundPlayer` thay vì khởi tạo trực tiếp. |

### 2. **Design Patterns áp dụng**

| Pattern         | Mục đích |
|------------------|---------|
| **Factory Method** | Sinh khối Tetrimino theo type (I, T, O, L, S, Z, J). |
| **State**         | Quản lý trạng thái game: Playing, Paused, GameOver. |
| **Strategy**      | Thay đổi thuật toán tính điểm, sinh khối ngẫu nhiên. |
| **Singleton**     | `AssetManager`, `ConfigManager` – dùng toàn cục an toàn. |
| **Observer**      | Khi xóa hàng: cập nhật điểm, cấp độ, UI hiệu ứng. |

---

## V. Gameplay & Giao diện người dùng

#### 1. UI nâng cao
- Màu khác nhau cho từng loại khối.
- Khung viền, nền mờ, hiệu ứng mượt mà khi xóa hàng.
- Hiển thị khối tiếp theo và khối hiện tại.

#### 2. Điểm số & cấp độ
- Tính điểm theo combo, loại xóa (single, double, Tetris).
- Tăng tốc độ theo cấp độ.
- Hiển thị high score.

#### 3. Trải nghiệm chơi
- Hướng dẫn điều khiển.
- Menu chính: Start Game, Exit.
- Tạm dừng & tiếp tục.
- Cho phép chơi lại khi thua.

#### 4. Thống kê sau game
- Biểu đồ hàng xóa theo thời gian.
- Số khối đã dùng, combo dài nhất.

---

## VI. Công cụ và công nghệ sử dụng

| Thành phần     | Công cụ                   |
|----------------|---------------------------|
| Ngôn ngữ        | C++23                     |
| Đồ họa          | SDL2                      |
| Build          | CMake                     |
| IDE            | VS Code, GitHub Codespaces |
| Quản lý mã     | GitHub + Feature Branch   |
| Unit Test      | Catch2 / Google Test      |
| Tài liệu hóa   | Doxygen, Markdown         |

---

## VII. Đảm bảo chất lượng mã nguồn
- **Quản lý mã nguồn với Git:**  
  - Sử dụng **Feature Branch Workflow**:  
    - Tạo nhánh riêng cho từng cải tiến (ví dụ: `feature/refactor-board`, `feature/add-score-manager`).  
    - Commit với thông điệp rõ ràng, theo cú pháp: `feat:`, `fix:`, `refactor:`, `test:` (ví dụ: `feat: implement ScoreManager`, `fix: resolve collision bug`).  
    - Tạo Pull Request, yêu cầu review và đảm bảo **pass unit test** trước khi merge vào `main`.

- **Coding Convention:**  
  - **Đặt tên:**  
    - Lớp: `PascalCase` (ví dụ: `Tetrimino`, `BoardManager`).  
    - Hàm: `camelCase` (ví dụ: `rotatePiece`, `clearLine`).  
    - Biến: `lower_snake_case` (ví dụ: `current_piece`, `line_count`).  
    - Thành viên lớp: thêm `_` đầu (ví dụ: `_position`, `_board`).  
  - **Định dạng:** Thụt lề bằng **tab**, dấu `{` cùng dòng với khai báo hàm/class.  
  - **Comments:** Dùng **Doxygen** (`/** ... */`) cho lớp/hàm quan trọng, tránh ghi chú dư thừa.  
  - **Includes:** Sắp xếp theo thứ tự: header tương ứng → thư viện chuẩn C++ (STL) → header nội bộ → thư viện ngoài; dùng `#pragma once` hoặc include guard; tránh dùng `using namespace` trong header.  
  - **Best Practices:** `++i`, tránh `endl`, khởi tạo biến ngay khi khai báo, ưu tiên **pure function** nếu có thể.

- **Unit Testing với Google Test:**  
  - **Test Plan:**  
    - Test logic di chuyển và xoay của `Tetrimino`.  
    - Test va chạm trong `Board` (kiểm tra vị trí hợp lệ, xóa hàng).  
    - Test điểm số trong `ScoreManager` (tính điểm khi xóa 1–4 hàng).  
  - **Test Cases:**  
    - `Tetrimino::rotate()`: Kiểm tra ma trận sau khi xoay.  
    - `Board::placePiece()`: Kiểm tra cập nhật trạng thái lưới.  
    - `ScoreManager::updateScore()`: Kiểm tra điểm khi xóa hàng liên tiếp.  
  - **Test Report:** Thống kê số test, pass/fail, tập trung vào logic game, không phụ thuộc SDL2 (mock nếu cần).

---

Nếu bạn muốn mình cập nhật thẳng vào tài liệu đang làm việc (trên canvas), bạn có thể gửi nội dung gốc hoặc yêu cầu tạo lại canvas cho phần này nhé!
### 3. **Unit Test**

- **Test lớp `Board`**: kiểm tra logic xếp khối, xóa hàng.
- **Test `Tetrimino`**: xoay, di chuyển trái/phải.
- **Test `GameManager`**: chuyển trạng thái game, điều kiện kết thúc.
- **Mock** `Renderer`, `Input` để test logic riêng.

---
## VII. 📆 Lộ trình triển khai (8 tuần)

Dưới đây là bảng **phân chia công việc cụ thể theo tuần cho 3 thành viên trong 8 tuần**, đảm bảo **đáp ứng đầy đủ các yêu cầu của đề bài** về viết lại game theo OOP, cải tiến bằng SOLID, design pattern, dependency injection, sử dụng git, kiểm thử, tài liệu hóa, v.v.

---

## 📌 **Phân chia công việc – 8 tuần (3 thành viên)**
| Tuần | Nguyễn Trà My (Trưởng nhóm) | Mã Tuyết Ngân | Nguyễn Khả Như |
|------|------------------------------|----------------|----------------|
| **Tuần 1**<br>🔍 Phân tích mã nguồn & lên kế hoạch | - Lựa chọn game Tetris gốc để refactor<br>- Phân tích kiến trúc hiện tại (video, code)<br>- Lên timeline 8 tuần | - Ghi chú các vấn đề của mã nguồn gốc<br>- Đề xuất các class cần có khi refactor | - Tìm hiểu SOLID, Design Pattern áp dụng được<br>- Gợi ý các tính năng có thể cải tiến |
| **Tuần 2**<br>📐 Thiết kế kiến trúc & class diagram | - Phác thảo kiến trúc Layered<br>- Vẽ sơ đồ class diagram (v1)<br>- Viết mô tả sơ bộ các module chính | - Viết mô tả từng lớp: vai trò, hàm chính (SRP)<br>- Phân tích các interface cần tạo (IRenderable, IUpdatable,...) | - Đề xuất các pattern: Factory, Observer...<br>- Lập tài liệu mô tả kiến trúc phần mềm |
| **Tuần 3**<br>💻 Viết code khung chương trình (OOP) | - Viết lớp GameManager, StateManager | - Viết lớp Board, Cell | - Viết lớp Tetrimino, PieceFactory |
| **Tuần 4**<br>⚙️ Kết nối logic & UI | - Tạo vòng lặp game (`update`, `render`)<br>- Kết nối `GameManager` với `Board`, `Tetrimino` | - Cài đặt InputHandler | - Xây dựng Renderer hiển thị khối, lưới |
| **Tuần 5**<br>🎨 Thêm UI, điểm số & cấp độ | - Viết ScoreManager, LevelManager | - Cập nhật UI (hiển thị điểm, khối tiếp theo, hiệu ứng) | - Tạo menu: start, pause, game over |
| **Tuần 6**<br>🔧 Refactor & áp dụng Design Pattern | - Áp dụng **Factory Method** và **Strategy** | - Áp dụng **Observer** cho update điểm/UI<br>- Refactor theo **DIP**, **ISP** | - Áp dụng **Singleton** cho AssetManager<br>- Inject các dependency thay vì tạo trực tiếp |
| **Tuần 7**<br>🧪 Unit Test + Git + Convention | - Viết test plan tổng quan<br>- Viết test case cho GameManager, State chuyển đổi | - Viết test cho Board: xếp khối, xóa hàng<br>- Viết tài liệu coding convention (naming, formatting, comment...) | - Viết test cho Tetrimino: di chuyển, xoay<br>- Viết test report (tổng số, pass/fail) |
| **Tuần 8**<br>📚 Tài liệu hóa + Báo cáo + Demo | - Viết tài liệu Doxygen cho tất cả lớp chính | - Viết báo cáo tổng hợp (Markdown)<br>- | - Quay video demo game<br>- Viết README (cách build, chơi game) |

---
