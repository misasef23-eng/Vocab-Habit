# VocabHabit – Ứng dụng học từ vựng (Anh – Việt & Trung – Việt)

**VocabHabit** (*Learn a little. Grow every day.*) là ứng dụng web đơn trang (Single-Page Application) và **Progressive Web App (PWA)** giúp luyện tập, kiểm tra và xây dựng thói quen học từ vựng mỗi ngày. Ứng dụng hoạt động hoàn toàn trên trình duyệt (không cần đăng ký tài khoản, không gửi dữ liệu lên máy chủ) và có thể cài đặt lên điện thoại/máy tính để dùng mượt mà ngay cả khi **không có kết nối Internet (Offline)**.

---

## 📱 Hướng dẫn cài đặt ứng dụng (Add to Home Screen / PWA)

Vì **VocabHabit** hỗ trợ công nghệ PWA, bạn có thể cài đặt trực tiếp trang web này lên màn hình chính như một ứng dụng độc lập (mở toàn màn hình, không có thanh địa chỉ trình duyệt, dùng được khi mất mạng).

> **Điều kiện:** Mở trang web bằng đường dẫn `https://...` (hoặc `http://localhost` nếu chạy thử trên máy tính). Chờ vài giây để trình duyệt tải xong bộ nhớ đệm offline (bạn có thể kiểm tra dòng trạng thái *"✓ Đã sẵn sàng dùng khi không có mạng"* trong mục **Cài VocabHabit như một ứng dụng** ở tab **Streak**).

### 1. Trên iPhone / iPad (iOS / iPadOS)
> ⚠️ **Bắt buộc dùng trình duyệt Safari** (Apple chưa cho phép các trình duyệt khác như Chrome/Cốc Cốc trên iOS cài đặt ứng dụng web hoàn chỉnh).

1. Mở trang web **VocabHabit** bằng trình duyệt **Safari**.
2. Bấm vào nút **Chia sẻ (Share)** ở thanh công cụ phía dưới (biểu tượng hình vuông có mũi tên hướng lên `↑`).
3. Cuộn danh sách xuống dưới và chọn **Thêm vào MH chính (Add to Home Screen)**.
4. Kiểm tra tên ứng dụng (`VocabHabit`), sau đó bấm **Thêm (Add)** ở góc trên bên phải.
5. Quay lại màn hình chính điện thoại, biểu tượng **VocabHabit** màu đỏ sẽ xuất hiện. Bấm vào để mở ứng dụng!

> 💡 **Lưu ý cực kỳ quan trọng dành cho người dùng iPhone / iPad:**
> Trên iOS, ứng dụng mở từ Màn hình chính có **bộ nhớ dữ liệu tách biệt hoàn toàn** với trình duyệt Safari.
> Nếu bạn đã học trong Safari trước khi cài ra màn hình chính:
> 1. Mở Safari → vào tab **Streak** → bấm **Tải file sao lưu** (tải về tệp `.json`).
> 2. Mở ứng dụng **VocabHabit** từ Màn hình chính → vào tab **Streak** → bấm **Nhập file sao lưu** và chọn tệp vừa tải để chuyển toàn bộ từ vựng & chuỗi ngày học sang.

---

### 2. Trên điện thoại Android (Chrome / Edge / Samsung Internet)
1. Mở trang web **VocabHabit** bằng trình duyệt **Google Chrome** (khuyên dùng).
2. **Cách 1 (Tự động):** Nếu thấy thanh thông báo *"Thêm VocabHabit vào Màn hình chính"* ở cuối màn hình hoặc nút **Cài đặt ngay** trong tab **Streak** của app, hãy bấm trực tiếp vào đó.
3. **Cách 2 (Thủ công):**
   - Bấm vào biểu tượng **Menu ba chấm dọc (`⋮`)** ở góc trên bên phải trình duyệt.
   - Chọn **Cài đặt ứng dụng (Install app)** hoặc **Thêm vào Màn hình chính (Add to Home screen)**.
   - Xác nhận **Cài đặt (Install)** trong hộp thoại hiện ra.
4. Chờ vài giây, ứng dụng sẽ được cài vào ngăn kéo ứng dụng (App Drawer) và màn hình chính.

---

### 3. Trên máy tính Windows / macOS (Google Chrome / Microsoft Edge)
1. Mở trang web **VocabHabit** bằng **Chrome** hoặc **Edge**.
2. Nhìn sang phía bên phải của **thanh địa chỉ (URL)**, bấm vào biểu tượng **Cài đặt ứng dụng** (hình màn hình máy tính có mũi tên tải xuống, hoặc biểu tượng dấu `+` trong vòng tròn).
   - *Hoặc vào Menu (`⋮` trên Chrome / `•••` trên Edge) → **Lưu và chia sẻ (Save and share)** → **Cài đặt VocabHabit...***
3. Bấm **Cài đặt (Install)** để xác nhận.
4. Ứng dụng sẽ mở ra trong một cửa sổ riêng biệt và được ghim vào Start Menu / Desktop (Windows) hoặc thư mục Applications / Dock (macOS).

---

## 📖 Cẩm nang sử dụng cho người dùng cuối

Ứng dụng được chia thành **4 tab chức năng chính** ở thanh điều hướng phía trên:

### 🔥 Tab 1: Streak (Theo dõi tiến độ & Sao lưu)
Đây là màn hình tổng quan giúp bạn duy trì động lực học tập mỗi ngày:
- **Chỉ số thói quen:** Hiển thị số **ngày liên tiếp** đang duy trì (`🔥`), **chuỗi dài nhất** từng đạt được và số **từ hôm nay** đã trả lời đúng. (Chỉ cần trả lời đúng tối thiểu **1 từ/ngày** để giữ chuỗi).
- **Biểu đồ nhiệt (Heatmap) theo năm:**
  - Mỗi ô vuông đại diện cho 1 ngày trong năm. Bấm vào ô bất kỳ để xem ngày đó bạn đã học được bao nhiêu từ và cần thêm bao nhiêu từ để lên mức màu đậm hơn.
  - Bấm nút `◀` / `▶` cạnh số năm để xem lại lịch sử học của các năm trước.
  - **Cơ chế chia màu thông minh:** Trong 6 ngày đầu, app dùng mốc khởi đầu (`1`, `3`, `6`, `10` từ). Từ ngày học thứ 7 trở đi, app tự động thống kê thói quen của riêng bạn và chia các ngày có học thành 4 nhóm (tứ phân vị) để tô màu công bằng nhất.
- **Xuất báo cáo PDF:** Bấm **Xuất báo cáo PDF** để tạo bảng tổng kết toàn diện (tổng quan, biểu đồ nhiệt các năm, phân bố theo thứ trong tuần, thống kê từng tháng, top 15 từ hay sai nhất, lịch sử làm bài và chi tiết trạng thái từng từ), sau đó chọn *Lưu dưới dạng PDF (Save as PDF)* trong hộp thoại in.
- **Sao lưu & Khôi phục:**
  - Nên bấm **Tải file sao lưu** định kỳ (app cũng sẽ nhẹ nhàng nhắc bạn sau mỗi 7 ngày nếu bạn chưa sao lưu).
  - Khi đổi máy hoặc đổi trình duyệt, bấm **Nhập file sao lưu** để nạp lại tệp `.json`. Dữ liệu mới sẽ được **gộp thông minh** với dữ liệu hiện tại mà không làm mất tiến trình đang có.

---

### 🧠 Tab 2: Học (Luyện tập & Kiểm tra)

Bạn có thể chuyển đổi qua lại giữa 2 nguồn từ vựng ở thanh chọn phía trên:
1. **Từ của tôi:** Học danh sách từ bạn tự thêm (có thể lọc chỉ học các từ gắn sao `★ Yêu thích`).
2. **Bộ từ có sẵn:** Học 9 bộ từ vựng biên soạn sẵn:
   - *Tiếng Trung:* HSK 1, HSK 2, HSK 3.
   - *Tiếng Anh TOEIC:* TOEIC 450, TOEIC 650, TOEIC 800.
   - *Tiếng Anh giao tiếp & chuyên ngành:* Giao tiếp cơ bản (1000 từ), Y khoa (Medical), Công nghệ thông tin (IT).

#### Các tùy chọn trước khi bắt đầu bài học:
- **Phạm vi từ (với Bộ từ có sẵn):**
  - `Từ mới`: Các từ chưa từng trả lời lần nào.
  - `Cần ôn`: Các từ đang học hoặc có tỷ lệ trả lời đúng dưới 50%.
  - `Tất cả`: Toàn bộ từ trong bộ.
  - `★ Yêu thích`: Các từ bạn đã đánh dấu sao trong bộ đó.
- **Kiểu kiểm tra:**
  - `Anh → Việt` (hoặc `Hán → Việt`): Nhìn từ ngoại ngữ, trả lời nghĩa tiếng Việt.
  - `Việt → Anh` (hoặc `Việt → Pinyin`): Nhìn nghĩa tiếng Việt, nhập từ ngoại ngữ.
  - `Ngẫu nhiên`: Trộn lẫn cả hai chiều hỏi.
- **Số câu:** Mặc định 10 câu (có thể nhập số lượng tùy ý tối đa bằng số từ hiện có).

#### Mẹo & Tính năng thông minh trong lúc làm bài:
- **Chuyển đổi nhanh chế độ trả lời:** Ngay trên thẻ câu hỏi, bạn có thể chuyển tức thì giữa **Trắc nghiệm** (chọn 1 trong 6 đáp án) và **Gõ từ** (tự gõ đáp án để nhớ sâu hơn).
- **Gõ cực kỳ thoải mái (Chấm điểm thông minh):**
  - *Khi gõ tiếng Việt:* Không cần gõ dấu thanh (ví dụ gõ `qua tao` vẫn khớp `quả táo`), không phân biệt `i` và `y` (`ky` = `kí`, `quy` = `qui`), chỉ cần gõ **1 trong các nghĩa** (ví dụ từ có nghĩa *"Cô, dì"* thì gõ `cô` hoặc `dì` đều đúng), hoặc gõ số (`10` cho *"Số mười (10)"*).
  - *Khi gõ tiếng Trung (Việt → Pinyin):* Có thể gõ Pinyin không dấu thanh (ví dụ `nihao` cho `nǐ hǎo`) hoặc gõ trực tiếp chữ Hán (`你好`).
  - *Châm chước lỗi gõ nhầm phím (Typo):* Với từ tiếng Anh dài từ 4 chữ cái trở lên, nếu bạn vô tình gõ nhầm 1 ký tự nằm ngay sát phím đúng trên bàn phím QWERTY (ví dụ gõ `acxept` thay vì `accept`), hệ thống vẫn tính đúng và gạch chân chữ bạn gõ nhầm để nhắc nhở.
- **Tự công nhận từ đồng nghĩa (Đối chiếu đáp án):** Nếu bạn gõ một nghĩa tiếng Việt hoặc từ đồng nghĩa khác với đáp án gốc nhưng vẫn đúng nghĩa, hãy bấm nút **Đối chiếu đáp án** → chọn **✓ Ý tôi đúng (lưu lại)**. Hệ thống sẽ tính điểm câu đó và tự động ghi nhớ cách diễn đạt của bạn cho những lần ôn sau!
- **Phát âm & Phiên âm IPA:**
  - Bấm nút **Nghe** (biểu tượng loa) để nghe phát âm chuẩn giọng Mỹ (`en-US`) hoặc Trung Quốc (`zh-CN`). *(Lưu ý: Khi đang ở chiều hỏi `Việt → Anh/Trung`, nút Nghe và IPA sẽ tạm khóa để tránh lộ đáp án, và tự mở ngay sau khi bạn trả lời xong).*
  - Bấm nút **IPA** để bật/tắt phiên âm quốc tế (tự động tra từ điển ~28.000 từ tiếng Anh và ký hiệu thanh điệu Chao cho tiếng Trung).
  - *Mẹo dùng âm thanh khi mất mạng:* Hãy tải sẵn gói giọng đọc ngoại tuyến (Offline Voice / Text-to-Speech) trong phần **Cài đặt** của điện thoại/máy tính để nghe phát âm không cần Internet.
- **Phím tắt tiện lợi:** Nhấn `Enter` để kiểm tra đáp án, và nhấn `Enter` thêm lần nữa ở màn hình kết quả để chuyển nhanh sang câu tiếp theo.

---

### ➕ Tab 3: Thêm từ
- Nhập **Từ tiếng Anh** (nhấn `Enter` để nhảy nhanh xuống ô dưới) và **Nghĩa tiếng Việt** (có thể nhập nhiều nghĩa cách nhau bởi dấu phẩy `,` hoặc chấm phẩy `;`).
- Tích chọn **★ Đánh dấu là từ yêu thích** nếu muốn ưu tiên ôn tập từ này.
- *(Lưu ý: Không sử dụng ký tự gạch đứng `|` vì đây là ký tự phân tách khi xuất/nhập dữ liệu).*

---

### 📋 Tab 4: Danh sách
- Xem toàn bộ từ vựng cá nhân của bạn, lọc theo **Tất cả** hoặc **★ Yêu thích**, bấm biểu tượng loa để nghe lại phát âm, bấm `★`/`☆` để gắn/bỏ sao, hoặc bấm `×` để xóa từ.
- **Sao lưu và nhập từ nhanh (dạng văn bản):**
  - Mở mục **Sao lưu và nhập từ** ở cuối trang.
  - Bạn có thể sao chép toàn bộ danh sách dạng văn bản thô (`từ|nghĩa` hoặc `từ|nghĩa|*` cho từ yêu thích), hoặc dán nội dung từ tệp `tuvung.txt` bên ngoài vào để nhập hàng loạt chỉ với 1 cú bấm.

---

## 🎨 Giao diện & Bảo mật dữ liệu

- **Tự động thích ứng Sáng / Tối (Dark Mode):** Giao diện tự động chuyển sang nền tối dịu mắt vào ban đêm theo cài đặt hệ thống của thiết bị.
- **An toàn dữ liệu tuyệt đối:** Toàn bộ dữ liệu học tập được lưu cục bộ trong `localStorage` của trình duyệt. Ứng dụng tích hợp cơ chế tự kiểm tra tính toàn vẹn dữ liệu; nếu phát hiện lỗi bất thường, phần dữ liệu gốc sẽ tự động được sao lưu riêng để tránh mất mát.

---

## 🛠️ Cấu trúc tệp & Hướng dẫn triển khai (Dành cho lập trình viên)

```text
VocabHabit/
├── index.html              # Mã nguồn ứng dụng (HTML, CSS, JS, Font Lato Base64, 9 bộ từ & từ điển IPA)
├── manifest.webmanifest    # Cấu hình PWA (tên app, chế độ standalone, màu chủ đạo #B0323A, icons)
├── sw.js                   # Service Worker quản lý cache phục vụ chạy offline
├── favicon.ico             # Biểu tượng favicon
└── icons/
    └── apple-touch-icon.png # Biểu tượng màn hình chính cho iOS/iPadOS
```

Để tự host hoặc triển khai ứng dụng:
1. Tải toàn bộ thư mục lên bất kỳ dịch vụ tĩnh nào hỗ trợ HTTPS (**GitHub Pages**, **Cloudflare Pages**, **Vercel**, **Netlify**...).
2. Nếu chạy thử trên máy cá nhân, khởi chạy một web server tĩnh (ví dụ: `python3 -m http.server 8080`) và truy cập `http://localhost:8080` để Service Worker hoạt động đầy đủ.

---

© 2026 **VocabHabit** · *Learn a little. Grow every day.*
