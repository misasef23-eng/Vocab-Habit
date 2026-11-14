# 🚀 Vocab Recall Engine (C++ Core) HOẶC bản website chạy ngay không cần cài đặt phức tạp tại VocabHabit.pages.dev
check my website: vocabhabit.pages.dev
Một chương trình C++ tối ưu hóa cho việc học từ vựng tiếng Anh theo phương pháp **Active Recall** (Chủ động gợi nhớ). Dự án được thiết kế với lõi C++ hiệu năng cao, hỗ trợ quản lý từ vựng linh hoạt, nhập liệu đa dạng và tích hợp giao diện web hiện đại.

---

## ✨ Tính năng nổi bật

- **Active Recall Engine:** Thuật toán kích thích trí nhớ chủ động, giúp ghi nhớ từ vựng lâu hơn so với phương pháp học thụ động truyền thống.
- **Đa dạng phương thức nhập liệu:**
  - Tự động thêm từ mới trực tiếp theo nhu cầu cá nhân.
  - Nhập từ vựng theo danh sách có sẵn (pre-made lists).
  - Tự tạo và quản lý list từ vựng riêng.
  - Hỗ trợ định dạng nhập nhanh theo cặp: `English|Meaning` (Ví dụ: `Apple|quả táo`).
- **Cross-Platform & Web Integration:** Lõi C++ mạnh mẽ kết hợp cùng phiên bản Web trực quan, thân thiện với người dùng.

---

## 🛠️ Cấu trúc dự án

```text
vocab-recall-engine/
├── core/             # Lõi xử lý logic C++ (Active Recall, Quản lý dữ liệu)
├── web/              # Giao diện Web tích hợp
├── data/             # Thư mục chứa các list từ vựng mặc định (.txt / .json)
├── CMakeLists.txt    # File cấu hình build hệ thống
└── README.md
# Clone repository về máy
git clone [https://github.com/Misasef23-eng/nhin-noi-dau-da-lau-chang-thay.git](https://github.com/Misasef23-eng/nhin-noi-dau-da-lau-chang-thay.git)
cd vocab-recall-engine

# Tạo thư mục build và biên dịch
mkdir build && cd build
cmake ..
make

# Chạy chương trình
./vocab_recall

Apple|quả táo
Banana|quả chuối
Active Recall|phương pháp chủ động gợi nhớ

🤝 Đóng góp (Contributing)
Mọi đóng góp, báo lỗi (issues) hoặc ý tưởng cải thiện thuật toán Active Recall đều rất hoan nghênh! Hãy tạo một Pull Request hoặc mở Issue để chúng ta cùng thảo luận nhé.

📄 License
Dự án được phân phối dưới giấy phép MIT License.

