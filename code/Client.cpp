#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2,2), &wsa);

    for (int i = 0; i < 100; i++) {
        s = socket(AF_INET, SOCK_STREAM, 0);
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        server.sin_port = htons(8888);

        if (connect(s, (struct sockaddr *)&server, sizeof(server)) == 0) {
            std::cout << "Gui ket noi thu " << i+1 << std::endl;
        }
        closesocket(s);
    }

    WSACleanup();
    return 0;
}
