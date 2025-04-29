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
| Tuần | Nguyễn Trà My (Trưởng nhóm) | Mã Tuyết Ngân | Nguyễn Khả Như | Đánh giá |
|------|------------------------------|----------------|----------------|----------------|
| **Tuần 1**<br>🔍 Phân tích mã nguồn & lên kế hoạch | - Tạo repository trên github và phân công công việc nhóm từ video mẫu của thầy<br>- Tìm hiểu git, github <br>- Coi video mẫu <br>- Viết file readme.md | - Tìm hiểu git, github <br>- Coi video mẫu <br>- Viết file readme.md | - Tìm hiểu git, github <br>- Coi video mẫu <br>- Viết file readme.md | 100% |
| **Tuần 2**<br>📐 Thiết kế class diagram & Tìm hiểu SOLID, Design Pattern| - Vẽ dirgram <br>- Tìm hiểu SOLID, Design Pattern<br>- Đề xuất những cải tiến từ video mẫu | - Vẽ dirgram <br>- Tìm hiểu SOLID, Design Pattern<br>- Đề xuất những cải tiến từ video mẫu | - Vẽ dirgram <br>- Tìm hiểu SOLID, Design Pattern<br>- Đề xuất những cải tiến từ video mẫu | 100% |
| **Tuần 3**<br>💻 Viết code khung chương trình (OOP) | - Tạo lớp Game để quản lý vòng lặp chính <br> - Kết hợp Field và Tetromino vào vòng lặp trò chơi <br> - Sử dụng Doxygen để mô tả class cụ thể (sử dụng từ giờ đến cuối đồ án) | - Chuyển đổi Tetromino thành một lớp độc lập, quản lý khối Tetris <br> - Viết các phương thức như initializeShape, move, rotate, fall,… <br> - Sử dụng Doxygen để mô tả class cụ thể (sử dụng từ giờ đến cuối đồ án)| - Chuyển đổi Field thành một lớp độc lập, quản lý lưới chơi <br> - Viết các phương thức cơ bản như isOccupied, isInside, setCell, clearLines,… <br> - Sử dụng Doxygen để mô tả class cụ thể (sử dụng từ giờ đến cuối đồ án) | 100% |
| **Tuần 4**<br>⚙️ Cải tiến | - Hiển thị khối tiếp theo ở góc giữa bên phải (1-3 khối kế tiếp)<br> - Hiển thị ảnh của khối hiện tại trên lưới (nhấn enter để xuống đáy lưới) | - Áp dụng Factory Pattern để tạo các khối Tetris từ các class con <br> - Xây dựng giao diện cho 3 trạng thái: MainMenu, Playing, GameOver (hình ảnh, âm thanh, gồm những lựa chọn nào…) <br> - Thêm hướng dẫn trước khi vào MainMenu <br> - Thêm hiệu ứng mượt mà khi xóa hàng (có âm thanh, hiệu ứng,..) | - Tăng tốc độ theo cấp độ (hoàn thành 1 dòng được 10 điểm, đủ 5 dòng lên level) <br> - Hiển thị điểm số và cấp độ trên lưới ở góc trên bên phải (quản lí thay đổi và hiển thị lại trên lưới mỗi lần tăng điểm số, cấp độ) | 100% |
| **Tuần 5**<br>🎨 Áp dụng Design Pattern + Cải tiến | - Áp dụng Dependency Injection để giảm sự phụ thuộc giữa các lớp <br> - Tách các lớp lớn thành các lớp nhỏ hơn (Single Responsibility Principle) <br> - Đề xuất và thêm các cải tiến (tự thêm vào đây) | - Áp dụng Observer Pattern để cập nhật giao diện khi điểm số hoặc cấp độ thay đổi <br> - Thêm chế độ chơi: truyền thống, có giới hạn thời gian, không giới hạn cấp độ<br> - Đề xuất và thêm các cải tiến (tự thêm vào đây) | - Áp dụng State Pattern để quản lý trạng thái trò chơi (Playing, Paused, GameOver) <br> - Thêm combo điểm (xóa liên tiếp 2 dòng thì x2 điểm, 3 dòng thì x3 điểm,….) <br> - Đề xuất và thêm các cải tiến (tự thêm vào đây) | 100% |
| **Tuần 6**<br>🔧 Coi lại toàn bộ code + cải tiến| - Thêm bảng xếp hạng điểm (so sánh với những lần chơi trước đó) và hiển thị bảng xếp hạng này mỗi lần game over <br> - Phân tích và tối ưu code | - Hỗ trợ, cải thiện giao diện đẹp và hoàn thiện hơn cho các thành viên khác <br> - Phân tích và tối ưu code | - Thêm thống kê sau game (số dòng đã xóa, số khối đã dùng, tổng điểm) của vòng chơi hiện tại <br>- Phân tích và tối ưu code | 100% |
| **Tuần 7**<br>🧪 Kiểm thử | - Viết unit test cho lớp GameManager<br>- Tạo báo cáo kiểm thử (test report) | - Viết unit test cho lớp Tetromino<br>- Kiểm tra tích hợp giữa các module | - Tạo test plan và các test case cho từng module <br>- Viết unit test cho lớp Field | 100% |
| **Tuần 8**<br>📚 Tài liệu hóa + Báo cáo + Demo |- Tạo báo cáo kiểm thử và tài liệu mô tả các lớp <br> - Đảm bảo mã nguồn được tối ưu và không có lỗi <br> - Quay video demo | - Chuẩn bị slide trình bày và bản demo chương trình<br>- Đảm bảo giao diện người dùng hoàn thiện <br> - Sửa video | - Hoàn thiện tài liệu mô tả kiến trúc phần mềm <br>- Kiểm tra lần cuối các tính năng gameplay <br> - Sửa video| 100% |

---
