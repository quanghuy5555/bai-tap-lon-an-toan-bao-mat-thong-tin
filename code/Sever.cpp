#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    int c;

    WSAStartup(MAKEWORD(2,2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(serverSocket, (struct sockaddr *)&server, sizeof(server));
    listen(serverSocket, 3);

    std::cout << "Server dang cho ket noi..." << std::endl;

    c = sizeof(struct sockaddr_in);
    while ((clientSocket = accept(serverSocket, (struct sockaddr *)&client, &c)) != INVALID_SOCKET) {
        std::cout << "Nhan ket noi tu client!" << std::endl;
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
