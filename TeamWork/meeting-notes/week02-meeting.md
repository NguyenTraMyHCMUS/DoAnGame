# 📝 Biên bản họp nhóm – Tuần 2

**Thời gian họp:** 12/04/2025  
**Hình thức:** Trực tuyến  
**Thành viên tham dự:**  
- Nguyễn Trà My  
- Mã Tuyết Ngân  
- Nguyễn Khả Như

---

## ✅ Nội dung cuộc họp:

1. **Thiết kế kiến trúc phần mềm:**
   - Áp dụng kiến trúc **Layered Architecture** với các layer:
     - Input, Game Logic, UI/Renderer, Core.
   - Luồng hoạt động: Input → GameManager → Board/Tetrimino → Renderer.

2. **Vẽ sơ đồ lớp (Class Diagram v1):**
   - Các lớp chính: `GameManager`, `Tetrimino`, `Board`, `InputHandler`, `Renderer`.

3. **Xác định interface cần có:**
   - `IRenderable`, `IUpdatable`, `IControllable`.

---

## 📌 Phân công tuần 2:
- **Trà My:** Vẽ class diagram, mô tả module chính.
- **Tuyết Ngân:** Mô tả chi tiết các lớp, phân tích interface.
- **Khả Như:** Đề xuất pattern, viết tài liệu mô tả kiến trúc.

---

## 📊 Tỉ lệ đóng góp:
| Thành viên         | Công việc chính                           | Tỉ lệ (%) |
|--------------------|-------------------------------------------|-----------|
| Nguyễn Trà My      | Kiến trúc + class diagram                  | 35%       |
| Mã Tuyết Ngân      | Phân tích SRP, interface                  | 35%       |
| Nguyễn Khả Như     | Tài liệu mô tả, đề xuất design pattern    | 30%       |
