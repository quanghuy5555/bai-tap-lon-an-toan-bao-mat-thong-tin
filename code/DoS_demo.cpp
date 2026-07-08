#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    cout << "Bat dau mo phong DoS..." << endl;

    for (int i = 0; i < 20; i++) {
        cout << "Gui yeu cau so " << i+1 << endl;
        // giả lập độ trễ giữa các yêu cầu
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "Ket thuc mo phong." << endl;
    return 0;
}
