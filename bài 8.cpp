#include <iostream>   // cin, cout
#include <string>     // kiểu string
#include <cstdlib>    // rand, srand
#include <ctime>      // time
#include <cctype>     // tolower
using namespace std;

// Hàm vẽ hình người treo cổ theo số lần đoán sai (từ 0 đến 6)
void veHinh(int soLanSai) {
    cout << "\n";
    cout << "  +---+\n";
    cout << "  |   |\n";

    // Dòng 3: cái đầu (sai từ 1 lần trở lên)
    if (soLanSai >= 1) cout << "  O   |\n";
    else               cout << "      |\n";

    // Dòng 4: thân và hai tay
    if (soLanSai <= 1)      cout << "      |\n";   // chưa có thân
    else if (soLanSai == 2) cout << "  |   |\n";   // thân
    else if (soLanSai == 3) cout << " /|   |\n";   // thân + tay trái
    else                    cout << " /|\\  |\n";   // thân + 2 tay

    // Dòng 5: hai chân
    if (soLanSai <= 4)      cout << "      |\n";   // chưa có chân
    else if (soLanSai == 5) cout << " /    |\n";   // chân trái
    else                    cout << " / \\  |\n";   // 2 chân

    cout << "      |\n";
    cout << "=========\n";
}

int main() {
    // BƯỚC 1: Chuẩn bị dữ liệu
    srand(time(0));   // để mỗi lần chạy random ra từ khác nhau

    string danhSach[5] = {"python", "banana", "computer", "hangman", "program"};
    string tuBiMat = danhSach[rand() % 5];   // chọn ngẫu nhiên 1 từ trong 5 từ

    int doDai = tuBiMat.length();            // số chữ cái của từ bí mật
    string hienThi(doDai, '_');              // ví dụ từ 6 chữ -> "______"
    string daDoan = "";                      // lưu các chữ cái đã đoán
    int soLanSai = 0;                        // số lần đoán sai
    const int TOI_DA = 6;                    // sai tối đa 6 lần thì thua

    cout << "=== TRO CHOI HANGMAN ===\n";
    cout << "Tu bi mat co " << doDai << " chu cai.\n";

    // BƯỚC 2: Vòng lặp chính
    // Chơi tiếp khi: chưa sai đủ 6 lần VÀ chưa đoán ra hết từ
    while (soLanSai < TOI_DA && hienThi != tuBiMat) {

        // 2a. In hình người và từ bí mật hiện tại
        veHinh(soLanSai);
        cout << "\nTu bi mat: ";
        for (int i = 0; i < doDai; i++) {
            cout << hienThi[i] << " ";
        }
        cout << "\nSo lan sai: " << soLanSai << "/" << TOI_DA << "\n";

        // 2b. Cho người chơi nhập một chữ cái
        string nhap;
        cout << "Nhap mot chu cai: ";
        if (!(cin >> nhap)) {
            return 0;   // hết dữ liệu nhập thì thoát chương trình
        }

        // Kiểm tra chỉ nhập đúng 1 ký tự và đó là chữ cái
        if (nhap.length() != 1 || !isalpha(nhap[0])) {
            cout << "-> Chi duoc nhap MOT chu cai (a-z)!\n";
            continue;   // quay lại đầu vòng lặp, không bị tính là sai
        }

        char chu = tolower(nhap[0]);   // đổi thành chữ thường: 'A' -> 'a'

        // Kiểm tra chữ này đã đoán rồi chưa
        if (daDoan.find(chu) != string::npos) {
            cout << "-> Ban da doan chu '" << chu << "' roi!\n";
            continue;
        }
        daDoan = daDoan + chu;   // ghi nhớ chữ vừa đoán

        // 2c. Kiểm tra chữ cái có nằm trong từ bí mật không
        bool doanDung = false;
        for (int i = 0; i < doDai; i++) {
            if (tuBiMat[i] == chu) {
                hienThi[i] = chu;    // hiện chữ cái ở đúng vị trí
                doanDung = true;
            }
        }

        if (doanDung) {
            cout << "-> Chinh xac! Co chu '" << chu << "'.\n";
        } else {
            soLanSai = soLanSai + 1;   // sai thì mất một lượt, vẽ thêm một bộ phận
            cout << "-> Sai roi! Khong co chu '" << chu << "'.\n";
        }
    }

    // BƯỚC 3: Kết thúc, thông báo thắng hay thua
    veHinh(soLanSai);
    if (hienThi == tuBiMat) {
        cout << "\nTu bi mat: " << tuBiMat << "\n";
        cout << "*** BAN DA THANG!! ***\n";
    } else {
        cout << "\nBan da thua! Tu bi mat la: " << tuBiMat << "\n";
    }

    return 0;
}