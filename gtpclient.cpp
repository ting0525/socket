#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>

int main() {
    // 初始化 Winsock 库
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "1" << std::endl;
        return 1;
    }

    // 建立 socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "2" << std::endl;
        WSACleanup();
        return 1;
    }

    // 設定伺服器位址
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);  // 與伺服器端相同的連接埠

    // 轉換伺服器位址
    if (inet_ntoa(serverAddress.sin_family, "127.0.0.1", &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "3" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // 嘗試連線到伺服器
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "4" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "5" << std::endl;

    // 發送資料到伺服器
    const char* message = "Hello, server!";
    int bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1) {
        std::cerr << "6" << std::endl;
    } else {
        std::cout << "7" << std::endl;
    }

    // 關閉連線
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
