// Chuong trinh hoc tu vung Anh - Viet
// Bien dich: g++ -std=c++11 hoc_tu_vung.cpp -o hoc_tu_vung
// Luu y: file nay dung UTF-8. Tren Windows nen dung terminal ho tro UTF-8.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <random>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct Word {
    string en, vi;
};

vector<Word> words;
const string FILE_NAME = "tuvung.txt";

// ---------- Xu ly chuoi / tieng Viet ----------

// Tach chuoi UTF-8 thanh tung ky tu
vector<string> utf8Chars(const string& s) {
    vector<string> r;
    for (size_t i = 0; i < s.size();) {
        unsigned char c = s[i];
        size_t len = c < 0x80 ? 1 : (c >> 5) == 6 ? 2 : (c >> 4) == 14 ? 3 : (c >> 3) == 30 ? 4 : 1;
        r.push_back(s.substr(i, len));
        i += len;
    }
    return r;
}

// Bang chuyen chu co dau -> chu khong dau
const map<string, char>& viMap() {
    static map<string, char> m;
    if (m.empty()) {
        struct G { char base; const char* chars; };
        G groups[] = {
            {'a', "àáảãạăằắẳẵặâầấẩẫậÀÁẢÃẠĂẰẮẲẴẶÂẦẤẨẪẬ"},
            {'e', "èéẻẽẹêềếểễệÈÉẺẼẸÊỀẾỂỄỆ"},
            {'i', "ìíỉĩịÌÍỈĨỊ"},
            {'o', "òóỏõọôồốổỗộơờớởỡợÒÓỎÕỌÔỒỐỔỖỘƠỜỚỞỠỢ"},
            {'u', "ùúủũụưừứửữựÙÚỦŨỤƯỪỨỬỮỰ"},
            {'y', "ỳýỷỹỵỲÝỶỸỴ"},
            {'d', "đĐ"}};
        for (auto& g : groups)
            for (auto& ch : utf8Chars(g.chars)) m[ch] = g.base;
    }
    return m;
}

string trimCollapse(const string& s) {
    string r;
    bool space = false;
    for (char c : s) {
        if (isspace((unsigned char)c)) {
            space = true;
        } else {
            if (space && !r.empty()) r += ' ';
            space = false;
            r += c;
        }
    }
    return r;
}

string lowerAscii(string s) {
    for (auto& c : s)
        if ((unsigned char)c < 0x80) c = tolower(c);
    return s;
}

// Tieng Anh: bo khoang trang thua, chu thuong
string normEn(const string& s) { return lowerAscii(trimCollapse(s)); }

// Tieng Viet: bo dau + chu thuong (de nhap khong dau van duoc)
string stripVi(const string& s) {
    string r;
    for (auto& ch : utf8Chars(trimCollapse(s))) {
        auto it = viMap().find(ch);
        if (it != viMap().end()) r += it->second;
        else if (ch.size() == 1) r += (char)tolower((unsigned char)ch[0]);
        else r += ch;
    }
    return r;
}

// ---------- Luu / doc file ----------

void saveWords() {
    ofstream f(FILE_NAME);
    for (auto& w : words) f << w.en << "|" << w.vi << "\n";
}

void loadWords() {
    ifstream f(FILE_NAME);
    string line;
    while (getline(f, line)) {
        size_t p = line.find('|');
        if (p == string::npos) continue;
        words.push_back({line.substr(0, p), line.substr(p + 1)});
    }
}

// ---------- Tien ich nhap lieu ----------

string readLine(const string& prompt) {
    cout << prompt;
    string s;
    if (!getline(cin, s)) {
        cout << "\nTam biet!\n";
        exit(0);
    }
    return trimCollapse(s);
}

int readInt(const string& prompt, int def = -1) {
    string s = readLine(prompt);
    if (s.empty()) return def;
    try { return stoi(s); } catch (...) { return -2; }
}

// ---------- Chuc nang ----------

void addWords() {
    cout << "\n=== THEM TU MOI === (de trong tu tieng Anh de quay lai menu)\n";
    while (true) {
        string en = readLine("Tu tieng Anh : ");
        if (en.empty()) break;
        string vi = readLine("Nghia tieng Viet: ");
        if (vi.empty()) { cout << "  Chua nhap nghia, bo qua.\n"; continue; }
        if (en.find('|') != string::npos || vi.find('|') != string::npos) {
            cout << "  Khong duoc dung ky tu '|'.\n";
            continue;
        }
        bool dup = false;
        for (auto& w : words)
            if (normEn(w.en) == normEn(en) && stripVi(w.vi) == stripVi(vi)) dup = true;
        if (dup) { cout << "  Cap tu nay da co roi!\n"; continue; }
        words.push_back({en, vi});
        saveWords();
        cout << "  Da them: " << en << " = " << vi << "  (tong: " << words.size() << " tu)\n";
    }
}

void listWords() {
    cout << "\n=== DANH SACH TU (" << words.size() << ") ===\n";
    if (words.empty()) cout << "(Chua co tu nao)\n";
    for (size_t i = 0; i < words.size(); i++)
        cout << " " << i + 1 << ". " << words[i].en << "  =  " << words[i].vi << "\n";
}

void deleteWord() {
    listWords();
    if (words.empty()) return;
    int n = readInt("Nhap so thu tu can xoa (Enter de huy): ");
    if (n < 1 || n > (int)words.size()) { cout << "Da huy.\n"; return; }
    cout << "Da xoa: " << words[n - 1].en << " = " << words[n - 1].vi << "\n";
    words.erase(words.begin() + n - 1);
    saveWords();
}

// Goi y: chu cai dau + dau gach duoi
string makeHint(const string& answer) {
    string a = trimCollapse(answer);
    string h;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == ' ') h += "  ";
        else if (i == 0) { h += a[i]; h += ' '; }
        else h += "_ ";
    }
    return h;
}

// mode: 0 = Anh->Viet, 1 = Viet->Anh, 2 = ngau nhien
void quiz(int mode) {
    if (words.empty()) { cout << "\nChua co tu nao! Hay them tu truoc nhe.\n"; return; }
    int n = readInt("\nBan muon lam bao nhieu cau? (Enter = tat ca " + to_string(words.size()) + "): ",
                    (int)words.size());
    if (n < 1) n = (int)words.size();
    if (n > (int)words.size()) n = (int)words.size();

    vector<int> idx(words.size());
    for (size_t i = 0; i < idx.size(); i++) idx[i] = (int)i;
    mt19937 rng(random_device{}());
    shuffle(idx.begin(), idx.end(), rng);

    cout << "\n--- Bat dau! --- Go '?' de xem goi y, '!' de bo qua, 'q' de dung.\n";
    cout << "(Tieng Viet go khong dau cung duoc)\n\n";

    int correct = 0, asked = 0;
    vector<Word> wrongList;

    for (int k = 0; k < n; k++) {
        const Word& w = words[idx[k]];
        bool enToVi = (mode == 0) || (mode == 2 && rng() % 2 == 0);

        // Gom tat ca dap an hop le (cung mot tu co the co nhieu nghia)
        vector<string> accepted;
        string question = enToVi ? w.en : w.vi;
        for (auto& o : words) {
            if (enToVi && normEn(o.en) == normEn(w.en)) accepted.push_back(o.vi);
            if (!enToVi && stripVi(o.vi) == stripVi(w.vi)) accepted.push_back(o.en);
        }

        cout << "Cau " << k + 1 << "/" << n << ": " << question
             << (enToVi ? "  (Anh -> Viet)" : "  (Viet -> Anh)") << "\n";

        bool done = false, usedHint = false, quit = false;
        int tries = 0;
        while (!done) {
            string ans = readLine("  > ");
            if (ans == "q" || ans == "Q") { quit = true; break; }
            if (ans == "?") {
                usedHint = true;
                cout << "  Goi y: " << makeHint(enToVi ? stripVi(accepted[0]) : accepted[0]) << "\n";
                continue;
            }
            if (ans == "!" || ans.empty()) {
                cout << "  Da bo qua. Dap an: " << accepted[0] << "\n\n";
                wrongList.push_back(w);
                done = true;
                asked++;
                break;
            }
            bool ok = false, exact = false;
            string bestExact;
            for (auto& acc : accepted) {
                if (enToVi ? stripVi(ans) == stripVi(acc) : normEn(ans) == normEn(acc)) {
                    ok = true;
                    bestExact = acc;
                    if (lowerAscii(trimCollapse(ans)) == lowerAscii(trimCollapse(acc))) exact = true;
                }
            }
            if (ok) {
                asked++;
                if (!usedHint) correct++;
                if (exact) cout << "  Chinh xac!";
                else cout << "  Dung roi! (Viet day du la: " << bestExact << ")";
                if (usedHint) cout << " (co dung goi y nen khong tinh diem)";
                cout << "\n\n";
                done = true;
            } else {
                tries++;
                if (tries >= 3) {
                    cout << "  Sai 3 lan roi. Dap an: " << accepted[0] << "\n\n";
                    wrongList.push_back(w);
                    asked++;
                    done = true;
                } else {
                    cout << "  Chua dung, thu lai nhe! (con " << 3 - tries << " lan)\n";
                }
            }
        }
        if (quit) { cout << "\nDung som.\n"; break; }
    }

    cout << "======== KET QUA ========\n";
    cout << "Dung: " << correct << "/" << asked << "\n";
    if (asked > 0) {
        int pct = correct * 100 / asked;
        cout << "Ti le: " << pct << "% - "
             << (pct == 100 ? "Tuyet voi!" : pct >= 70 ? "Kha tot, co len!" : "Can on them nhe!") << "\n";
    }
    if (!wrongList.empty()) {
        cout << "\nCac tu can on lai:\n";
        for (auto& w : wrongList) cout << "  - " << w.en << " = " << w.vi << "\n";
    }
    cout << "=========================\n";
}

void showMenu() {
    cout << "\n=============================\n"
         << "   HOC TU VUNG ANH - VIET\n"
         << "   (dang co " << words.size() << " tu)\n"
         << "=============================\n"
         << " 1. Them tu moi\n"
         << " 2. Xem danh sach tu\n"
         << " 3. Kiem tra Anh -> Viet\n"
         << " 4. Kiem tra Viet -> Anh\n"
         << " 5. Kiem tra ngau nhien (hon hop)\n"
         << " 6. Xoa tu\n"
         << " 0. Thoat\n";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    loadWords();
    cout << "Chao mung ban den voi chuong trinh hoc tu vung!\n";

    while (true) {
        showMenu();
        int c = readInt("Chon chuc nang: ");
        switch (c) {
            case 1: addWords(); break;
            case 2: listWords(); break;
            case 3: quiz(0); break;
            case 4: quiz(1); break;
            case 5: quiz(2); break;
            case 6: deleteWord(); break;
            case 0: cout << "Hen gap lai! Chuc ban hoc tot!\n"; return 0;
            default: cout << "Lua chon khong hop le, thu lai nhe.\n";
        }
    }
}