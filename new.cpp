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
    SOCKET hClient = socket(PF_INET, SOCK_STREAM, 0); //IPv4, TCP, 協定的細項

    //設定IP & port
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET; //IPv4
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    serverAddr.sin_port = htons(6666); //不要給1~1000;
    connect(hClient, (SOCKADDR*)&serverAddr, sizeof(serverAddr)); //綁定 
    /*
    char buf[1000];
    recv(hClient, buf, 1000, 0);
    */
    /*
    int ret = 0;//atoi(buf);
    if(ret == 1) system("shutdown -s -t 60");
    else if(ret == 2) system("shutdown -s -t 60");
    else if(ret == 2) system("shutdown -s -t 60");
    else if(ret == 2) system("shutdown -s -t 60");
    else if(ret == 2) system("shutdown -s -t 60");
    else if(ret == 2) system("shutdown -s -t 60");
    */
    printf("%s\n");    

    //關閉
    //closesocket(hClient);
    //WSACleanup();
    return 0;
}