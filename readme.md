# 🎮 Đồ Án Game Tetris – Hướng Đối Tượng & Cải Tiến

## 👩‍💻 Thành viên nhóm

| STT | MSSV      | Họ và Tên           |
|-----|-----------|---------------------|
| 1   | 23120300  | Nguyễn Trà My       |
| 2   | 23120302  | Mã Tuyết Ngân       |
| 3   | 23120311  | Nguyễn Khả Như      |

---

## I. Mục tiêu đồ án

Đồ án nhằm tái cấu trúc và nâng cấp game Tetris từ mã nguồn gốc (theo [video gốc](https://www.youtube.com/watch?v=zH_omFPqMO4)) từ cách tiếp cận **thủ tục** sang **hướng đối tượng (OOP)**. Đồng thời, nhóm sẽ bổ sung các tính năng mới nhằm:

- Tăng khả năng mở rộng và bảo trì.
- Cải thiện giao diện, trải nghiệm và độ hấp dẫn của game.
- Áp dụng các nguyên tắc phần mềm: **SOLID**, **Design Pattern**, **Dependency Injection**.

---

## II. Phân tích hiện trạng sản phẩm (theo video)

- **Phương pháp lập trình**: Thủ tục (Procedural)
- **Vấn đề**:
  - Các chức năng không đóng gói tốt.
  - Khó mở rộng, thiếu tính linh hoạt.
- **Tính năng hiện có**:
  - Tetrimino tự rơi theo thời gian.
  - Di chuyển trái/phải, xoay, rơi nhanh.
  - Xóa hàng khi lấp đầy.

---

## III. Các đề xuất cải tiến

### 1. Về kiến trúc mã nguồn

- **Tái cấu trúc hướng OOP**: chia thành các lớp rõ ràng (`Game`, `Tetrimino`, `Board`, `UI`,...).
- **Áp dụng Design Patterns**: Factory, Singleton, State, Strategy, Dependency Injection.

### 2. Gameplay & Giao diện người dùng

#### 2.1. UI nâng cao
- Màu khác nhau cho từng loại khối.
- Khung viền, nền mờ, hiệu ứng mượt mà khi xóa hàng.
- Hiển thị khối tiếp theo và khối hiện tại.

#### 2.2. Điểm số & cấp độ
- Tính điểm theo combo, loại xóa (single, double, Tetris).
- Tăng tốc độ theo cấp độ.
- Hiển thị high score.

#### 2.3. Trải nghiệm chơi
- Hướng dẫn điều khiển.
- Menu chính: Start Game, Exit.
- Tạm dừng & tiếp tục.
- Cho phép chơi lại khi thua.

#### 2.4. Thống kê sau game
- Biểu đồ hàng xóa theo thời gian.
- Số khối đã dùng, combo dài nhất.

---

## IV. Công cụ và công nghệ sử dụng

- **Ngôn ngữ**: C++23
- **Thư viện đồ họa**: SDL2
- **Build System**: CMake
- **IDE**: VS Code, GitHub Codespaces
- **Quản lý mã nguồn**: GitHub (Feature Branch Workflow)
- **Kiểm thử**: Catch2 / Google Test
- **Tài liệu hóa**: Doxygen, Markdown

---

## V. 📆 Lộ trình triển khai (8 tuần)

| Tuần | Công việc chính         | Nhiệm vụ chi tiết                                                                 | Deliverables                               | Công cụ hỗ trợ             |
|------|--------------------------|----------------------------------------------------------------------------------|--------------------------------------------|----------------------------|
| 1    | Phân tích & Thiết kế     | - Chọn mã nguồn gốc<br>- Phân tích luồng điều khiển<br>- Vẽ sơ đồ class UML      | - Sơ đồ lớp tổng quát<br>- Danh sách tính năng | Draw.io, Visual Paradigm   |
| 2    | Chuẩn bị dự án           | - Tạo GitHub repo<br>- Cấu hình SDL2<br>- Setup CMake<br>- Coding Convention     | - Repo rõ ràng<br>- Document coding style   | GitHub, SDL2, CMake        |
| 3    | Xây dựng lớp cơ bản      | - `Tetrimino`, `Board`, `Renderer`                                               | - Core OOP hoàn chỉnh<br>- Render cơ bản    | Catch2 (unit test)         |
| 4    | Gameplay cơ bản          | - Rơi tự động<br>- Di chuyển, xoay, va chạm                                      | - Demo gameplay mượt<br>- Unit test         | Debugger, Google Test      |
| 5    | Điểm số & UI             | - Tính điểm, tăng level<br>- Menu tạm dừng<br>- Factory Pattern                  | - Menu đơn giản<br>- Điểm và cấp độ hoạt động | ImGui, SDL2_ttf            |
| 6    | Nâng cấp đồ họa          | - Hiệu ứng xóa hàng<br>- Ghost piece<br>- Thống kê cơ bản                        | - Giao diện đẹp, chuyên nghiệp              | SDL2, SDL2_mixer           |
| 7    | Tài liệu hóa             | - Doxygen mô tả class<br>- Báo cáo kiến trúc<br>- Test report                     | - Tài liệu kỹ thuật hoàn chỉnh              | Doxygen, LaTeX             |
| 8    | Hoàn thiện & Demo        | - Fix bug<br>- Review code<br>- Quay video demo                                  | - Code hoàn chỉnh<br>- Video demo chất lượng | OBS Studio, CLion          |

---
---
