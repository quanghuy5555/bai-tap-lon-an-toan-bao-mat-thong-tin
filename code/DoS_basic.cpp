#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Hàm giả lập xử lý yêu cầu
void xuLyYeuCau(int id) {
    cout << "Dang xu ly yeu cau " << id << endl;
    this_thread::sleep_for(chrono::milliseconds(500)); // giả lập thời gian xử lý
    cout << "Hoan thanh yeu cau " << id << endl;
}

int main() {
    cout << "=== Mo phong he thong binh thuong ===" << endl;
    for (int i = 1; i <= 5; i++) {
        xuLyYeuCau(i);
    }

    cout << "\n=== Mo phong DoS (qua tai) ===" << endl;
    for (int i = 1; i <= 20; i++) {
        xuLyYeuCau(i);
    }

    cout << "\nKet thuc mo phong." << endl;
    return 0;
}
