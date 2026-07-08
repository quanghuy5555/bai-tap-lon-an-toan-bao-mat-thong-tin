# Bài tập lớn - An toàn bảo mật thông tin
## Chủ đề: Mô phỏng tấn công DoS/DDoS

### 1. Giới thiệu
Denial-of-Service (DoS) là kiểu tấn công khiến hệ thống không thể phục vụ người dùng hợp lệ do bị quá tải bởi nhiều yêu cầu.  
Trong bài này, chúng tôi xây dựng chương trình **mô phỏng** bằng C++ để minh họa khái niệm DoS/DDoS.

### 2. Nội dung
- **Phiên bản cơ bản**: chương trình gửi nhiều yêu cầu tuần tự → hệ thống xử lý bình thường.  
- **Phiên bản nâng cao**: chương trình gửi nhiều yêu cầu song song (đa luồng) → hệ thống bị quá tải, minh họa DDoS.

### 3. Cách chạy
1. Clone repo:
   ```bash
   git clone https://github.com/ten-nhom/ten-du-an.git
   cd ten-du-an
