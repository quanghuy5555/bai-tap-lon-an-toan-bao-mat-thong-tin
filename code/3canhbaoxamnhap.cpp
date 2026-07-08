#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

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

// Ham in canh bao ra man hinh
void printAlert(string srcIP, string dstIP, string protocol, int port, string description) {
    cout << "=============================\n";
    cout << "[ALERT] DoS/DDoS Attack Detected!\n";
    cout << "Time: " << getCurrentTime() << "\n";
    cout << "Source IP: " << srcIP << "\n";
    cout << "Destination IP: " << dstIP << "\n";
    cout << "Protocol: " << protocol << "\n";
    cout << "Port: " << port << "\n";
    cout << "Description: " << description << "\n";
    cout << "Action Taken: Connection temporarily blocked\n";
    cout << "=============================\n\n";
}

int main() {
    // Tao danh sach canh bao gia lap
    vector<string> srcIPs = {"192.168.1.100", "10.0.0.55", "172.16.0.200"};
    vector<string> dstIPs = {"192.168.1.10", "192.168.1.20", "192.168.1.30"};
    vector<string> descriptions = {
        "Abnormal traffic volume detected (5000 requests/sec)",
        "Multiple SYN packets flood detected",
        "UDP flood suspected with high packet rate"
    };

    string protocol = "TCP";
    int port = 80;

    // Sinh nhieu canh bao
    for (int i = 0; i < srcIPs.size(); i++) {
        printAlert(srcIPs[i], dstIPs[i], protocol, port, descriptions[i]);
        logAlert(srcIPs[i], dstIPs[i], protocol, port, descriptions[i]);
    }

    cout << "Tat ca canh bao da duoc ghi vao file dos_ddos_alert.txt\n";

    return 0;
}
