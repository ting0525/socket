#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main(){
    //初始化socket
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    //創建socket
    SOCKET hServer = socket(PF_INET, SOCK_STREAM, 0); //IPv4, TCP, 協定的細項

    //設定IP & port
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET; //IPv4
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); //my ip address
    serverAddr.sin_port = htons(6666); //不要給1~1000;
    bind(hServer, (SOCKADDR*)&serverAddr, sizeof(serverAddr)); //綁定 

    //監聽
    listen(hServer, 5); //連接數量5

    //連接口
    SOCKET hClient;
    SOCKADDR_IN clientAddr;
    int clientSize = sizeof(clientAddr);
    hClient = accept(hServer, (SOCKADDR*)&clientAddr, &clientSize);

    printf("%s success", inet_ntoa(clientAddr.sin_addr));

    int choise;
    char buf[1000];
    while(true){
        system("cls");
        printf("1.close\n");
        printf("2.delete\n");
        printf("3.restart\n");
        printf("4.haha\n");
        printf("5.come on\n");
        printf("6.close client\n");
        scanf("%d", &choise);

        if(choise < 1 || choise > 6) continue;

        //int轉char
        _itoa(choise, buf, 10);
        send(hClient, buf, 1000, 0);
    }
    

    //關閉
    closesocket(hClient);
    closesocket(hServer);
    WSACleanup();
    return 0;
}