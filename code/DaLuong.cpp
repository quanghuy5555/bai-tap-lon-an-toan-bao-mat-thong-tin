#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

// Hàm giả lập xử lý yêu cầu
void xuLyYeuCau(int id) {
    cout << "Dang xu ly yeu cau " << id << endl;
    this_thread::sleep_for(chrono::milliseconds(500)); // giả lập thời gian xử lý
    cout << "Hoan thanh yeu cau " << id << endl;
}

int main() {
    cout << "=== Mo phong he thong binh thuong (xu ly tuan tu) ===" << endl;
    for (int i = 1; i <= 5; i++) {
        xuLyYeuCau(i);
    }

    cout << "\n=== Mo phong DoS (xu ly nhieu yeu cau dong thoi) ===" << endl;
    const int NUM_REQUESTS = 20;
    vector<thread> threads;

    for (int i = 1; i <= NUM_REQUESTS; i++) {
        threads.push_back(thread(xuLyYeuCau, i));
    }

    for (auto &t : threads) {
        t.join();
    }

    cout << "\nKet thuc mo phong." << endl;
    return 0;
}
