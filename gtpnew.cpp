#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    // 初始化socket
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 創建socket
    SOCKET hClient = socket(PF_INET, SOCK_STREAM, 0); // IPv4, TCP, 協定的細項

    // 設定IP & port
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET; // IPv4
    serverAddr.sin_addr.s_addr = inet_addr("192.168.1.107"); // Server IP address
    serverAddr.sin_port = htons(6666); // Server port
    connect(hClient, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

    int receivedNumber;
    char buf[1000];
    while (true) {
        memset(buf, 0, sizeof(buf)); // 清空緩衝區
        recv(hClient, buf, sizeof(buf), 0); // 接收數字

        receivedNumber = atoi(buf); // char轉int
        //printf("Received number: %d\n", receivedNumber);
        if(receivedNumber == 1) {
            system("shutdown /s /t 0");
        } 
        else if (receivedNumber == 2) {
            // 打開瀏覽器並訪問 Google
            char url[] = "https://www.google.com";
            char command[80];
            sprintf(command, "start %s", url);
            system(command);
        } 
        else {
            printf("無效的選項。\n");
        }
    }

    // 關閉
    closesocket(hClient);
    WSACleanup();
    return 0;
}
