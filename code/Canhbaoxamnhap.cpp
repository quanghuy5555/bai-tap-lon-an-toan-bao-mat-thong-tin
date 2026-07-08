#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Ham lay thoi gian hien tai
string getCurrentTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

// Ham ghi canh bao vao file
void logAlert(string srcIP, string dstIP, string protocol, int port, string description) {
    ofstream alertFile("dos_ddos_alert.txt", ios::app); // mo file ghi them
    if (alertFile.is_open()) {
        alertFile << "[ALERT] Possible DoS/DDoS Attack Detected\n";
        alertFile << "Time: " << getCurrentTime() << "\n";
        alertFile << "Source IP: " << srcIP << "\n";
        alertFile << "Destination IP: " << dstIP << "\n";
        alertFile << "Protocol: " << protocol << "\n";
        alertFile << "Port: " << port << "\n";
        alertFile << "Description: " << description << "\n";
        alertFile << "Action Taken: Connection temporarily blocked\n\n";
        alertFile.close();
    }
}

int main() {
    // Gia lap phat hien tan cong
    string srcIP = "192.168.1.100";
    string dstIP = "192.168.1.10";
    string protocol = "TCP";
    int port = 80;
    string description = "Abnormal traffic volume detected (5000 requests/sec)";

    // In canh bao ra man hinh
    cout << "=============================\n";
    cout << "[ALERT] DoS/DDoS Attack Detected!\n";
    cout << "Time: " << getCurrentTime() << "\n";
    cout << "Source IP: " << srcIP << "\n";
    cout << "Destination IP: " << dstIP << "\n";
    cout << "Protocol: " << protocol << "\n";
    cout << "Port: " << port << "\n";
    cout << "Description: " << description << "\n";
    cout << "Action Taken: Connection temporarily blocked\n";
    cout << "=============================\n";

    // Ghi canh bao vao file
    logAlert(srcIP, dstIP, protocol, port, description);

    cout << "\nCanh bao da duoc ghi vao file dos_ddos_alert.txt\n";

    return 0;
}
