﻿#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include<iostream>

#pragma warning(disable: 4996)

int main(int args, char* argv[])
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.1.204");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		std::cout << "Error: failed connect to sever.\n";
		return 1;
	}
	else
	{
		std::cout << "Connect done!";
	}

	system("pause");
	return 0;
}