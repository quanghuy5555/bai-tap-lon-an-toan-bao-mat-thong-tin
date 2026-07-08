#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    for (int i = 0; i < 100; i++) {
        cout << "Gửi yêu cầu số " << i+1 << endl;
        // giả lập độ trễ giữa các request
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "Hoan thanh viec gia lap." << endl;
    return 0;
}
