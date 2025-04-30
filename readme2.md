# 🎮 Đồ Án Game Tetris – Hướng Đối Tượng & Cải Tiến

## 👩‍💻 Thành viên nhóm

| STT | MSSV      | Họ và Tên                       |
|-----|-----------|---------------------            |
| 1   | 23120300  | Nguyễn Trà My (Nhóm Trưởng)     |
| 2   | 23120302  | Mã Tuyết Ngân                   |
| 3   | 23120311  | Nguyễn Khả Như                  |

---
## Công việc của từng thành viên đã thực hiện
1. Trà My

| Tuần | Mô tả công việc                            |
|----- |--------------------------------            |
| 1    |         ..                                 |
| 2    |         ..                                 |
| 3    |         ..                                 |
| 4    |         ..                                 |

2. Tuyết Ngân

| Tuần | Mô tả công việc                            |
|----- |--------------------------------            |
| 1    |         ..                                 |
| 2    |         ..                                 |
| 3    |         ..                                 |
| 4    |         ..                                 |

3. Khả Như

| Tuần | Mô tả công việc                            |
|----- |--------------------------------            |
| 1    |         ..                                 |
| 2    |         ..                                 |
| 3    |         ..                                 |
| 4    |         ..                                 |

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

## 1. Teamwork

Dưới đây là bảng **phân chia công việc cụ thể theo tuần cho 3 thành viên trong 8 tuần**, đảm bảo **đáp ứng đầy đủ các yêu cầu của đề bài** về viết lại game theo OOP, cải tiến bằng SOLID, design pattern, dependency injection, sử dụng git, kiểm thử, tài liệu hóa, v.v.

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


- **Git Commit:**
  - Lịch sử commit của từng thành viên được ghi nhận đầy đủ trên GitHub. Các commit được thực hiện đều đặn, tránh tình trạng dồn vào phút cuối.

---

### **UI/UX (20%)**
- **Cài đặt lại chức năng theo hướng đối tượng (3%):**
  - Các chức năng của game được tái cấu trúc theo hướng đối tượng, sử dụng các lớp như `Game`, `Tetromino`, `Field`, và các trạng thái `GameState`.
- **Các chức năng thêm và cải tiến (14%):**
  - **Cải tiến:** 
    - Thêm trạng thái `MainMenuState`, `PlayingState`, và `GameOverState` để quản lý các giai đoạn của trò chơi.
    - Tăng độ khó tự động khi người chơi đạt được số dòng xóa nhất định.
    - Hiển thị điểm số, cấp độ, và số dòng đã xóa.
  - **Chức năng mới:**
    - Reset game khi kết thúc.
    - Kiểm tra và xử lý khi đỉnh của lưới bị chiếm.
- **Giao diện bố trí hợp lý (3%):**
  - Giao diện được thiết kế trực quan, dễ sử dụng với các thành phần như khung nền (`frame`), bảng điểm (`score`), và lưới chơi (`field`).

---

### **Kiến trúc phần mềm + Design Pattern (20%)**
- **Kiến trúc phần mềm:**
  - Dự án được thiết kế theo mô hình hướng đối tượng (OOP), đảm bảo tính đóng gói, kế thừa, và đa hình.
  - Các lớp chính:
    - `Game`: Quản lý vòng lặp chính và trạng thái của trò chơi.
    - `Tetromino`: Đại diện cho các khối Tetris.
    - `Field`: Quản lý lưới chơi và xử lý xóa dòng.
    - `GameState`: Lớp cơ sở cho các trạng thái của trò chơi.
- **Design Pattern:**
  - **State Pattern:** Quản lý các trạng thái `MainMenuState`, `PlayingState`, và `GameOverState`.
  - **Factory Pattern:** Sử dụng `TetrominoFactory` để tạo các khối Tetris ngẫu nhiên.

---

### **Đảm bảo chất lượng (20%)**
- **Kiểm thử:**
  - Đã thực hiện kiểm thử các chức năng chính như di chuyển, xoay, và xóa dòng.
  - Kiểm tra trạng thái game khi đạt điều kiện kết thúc.
- **Coding Convention:**
  - Mã nguồn tuân thủ các quy tắc đặt tên biến, hàm, và tổ chức file hợp lý.
  - Các getter và setter được sử dụng để đảm bảo tính đóng gói.

---

### **Tài liệu mô tả kiến trúc phần mềm và các module (10%)**
- **Tài liệu kiến trúc:**
  - Mô tả chi tiết các lớp, chức năng, và cách chúng tương tác với nhau.
  - Sơ đồ UML minh họa kiến trúc tổng thể của dự án.
- **Các module chính:**
  - `Game`: Quản lý vòng lặp chính và trạng thái.
  - `Tetromino`: Xử lý logic của các khối Tetris.
  - `Field`: Quản lý lưới chơi và xử lý xóa dòng.
  - `GameState`: Quản lý các trạng thái khác nhau của trò chơi.

---

### **Các chủ đề nâng cao (15%)**
- **Tăng độ khó tự động:**
  - Tốc độ rơi của khối Tetris tăng dần khi người chơi đạt được số dòng xóa nhất định.
- **Quản lý trạng thái:**
  - Sử dụng State Pattern để chuyển đổi linh hoạt giữa các trạng thái `MainMenu`, `Playing`, và `GameOver`.
- **Xử lý va chạm và kiểm tra hợp lệ:**
  - Các khối Tetris được kiểm tra tính hợp lệ trước khi di chuyển hoặc xoay.

---

## 🔹 Video demo

- Link YouTube: [https://youtu.be/your-demo-link](https://youtu.be/your-demo-link)

---




