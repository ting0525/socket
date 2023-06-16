#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    // 初始化 Winsock 库
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    // 建立 socket
    SOCKET hServer = socket(PF_INET, SOCK_STREAM, 0); // IPv4, TCP, 協定的細項

    // 設定IP & port
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET; // IPv4
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // my ip address
    serverAddr.sin_port = htons(6666); // 不要給1~1000;
    bind(hServer, (SOCKADDR*)&serverAddr, sizeof(serverAddr)); // 綁定 

    // 監聽
    listen(hServer, 5); // 連接數量5

    // 連接口
    SOCKET hClient;
    SOCKADDR_IN clientAddr;
    int clientSize = sizeof(clientAddr);
    hClient = accept(hServer, (SOCKADDR*)&clientAddr, &clientSize);

    printf("%s success\n", inet_ntoa(clientAddr.sin_addr));

    int choice;
    char buf[1000];
    while (true) {
        system("cls");
        printf("1.close\n");
        printf("2.delete\n");
        printf("3.restart\n");
        printf("4.haha\n");
        printf("5.come on\n");
        printf("6.close client\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) continue;

        // int 轉 char
        _itoa(choice, buf, 10);
        send(hClient, buf, sizeof(buf), 0);

        // 接收來自客戶端的回應
        char response[1000];
        memset(response, 0, sizeof(response));
        recv(hClient, response, sizeof(response), 0);
        printf("收到回應：%s\n", response);
    }

    // 關閉
    closesocket(hClient);
    closesocket(hServer);
    WSACleanup();
    return 0;
}
