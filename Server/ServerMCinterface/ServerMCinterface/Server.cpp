//#include <iostream>
#include <ws2tcpip.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Server.h"

#pragma comment (lib, "ws2_32.lib")

using namespace std;
using namespace System;
Config config;

int Server::initializeWinsock()
{
	
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	errorMessage = WSAStartup(ver, &data);
	return errorMessage;
}

void Server::ErrorMessage()
{
	error[0]     = "Winsock initialized.";
	error[10004] = "Interrupted function call";
	error[10009] = "WSAEBADF";
	error[10013] = "WSAEACCES";
	error[10014] = "Bad address";
	error[10022] = "Invalid argument";
	error[10024] = "Too many open files";
	error[10035] = "Operation would block";
	error[10036] = "Operation now in progress";
	error[10037] = "Operation already in progress";
	error[10038] = "Socket operation on non - socket";
	error[10039] = "Destination address required";
	error[10060] = "Connection timed out";
	error[10061] = "Connection refused";
}

string Server::yazdirError()
{
	return error[errorMessage];
}

SOCKET Server::createdSocket()
{
	listening = socket(AF_INET, SOCK_STREAM, 0);
	return listening;
}

string Server::errorMessageCreateSocket() {
	string createSocketMessage;
	if (listening == INVALID_SOCKET) {
		createSocketMessage = "Can't create a socket! Quitting";
		WSACleanup(); }
	else {
		createSocketMessage = "Socket is created."; }
	return createSocketMessage;
}

void Server::ConnectIpAndPort() {
	hint.sin_family = AF_INET;
	hint.sin_port = htons(config.serverPort);
	inet_pton(AF_INET, config.serverOfIpAddress.c_str(), &hint.sin_addr);
}

void Server::BindListening()
{
	bind(listening, (sockaddr*)&hint, sizeof(Server::hint));
}

void Server::listenSocket() {
	listen(listening, SOMAXCONN);
}

void Server::loadConfig() {
	ifstream findTxt("config.txt");
	string line;
	while (getline(findTxt, line)) {
		istringstream sin(line.substr(line.find("=") + 1));
		if (line.find("serverOfIpAddress") != -1)
			sin >> config.serverOfIpAddress;
		else if (line.find("serverPort") != -1)
			sin >> config.serverPort;
	}
}

void Server::ListeningMaster()
{
	FD_ZERO(&master);
	FD_SET(listening, &master);
}

void Server::GetHostAndService()
{
	getnameinfo((sockaddr*)&clien, sizeof(clien), host, NI_MAXHOST, service, NI_MAXSERV, 0);
}

SOCKET Server::ClientAcceptance()
{
	int clientsize = sizeof(clien);
	SOCKET client = accept(listening, (sockaddr*)&clien, &clientsize);
	return client;
}

void Server::CleanHostAndService()
{
	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);
}

int Server::SocketCount()
{
	copy = master;
	int socketcount = select(0, &copy, nullptr, nullptr, nullptr);
	return socketcount;
}

int Server::GetIp(SOCKET sock)
{
	ZeroMemory(buf, 4096);
	bytesin = recv(sock, buf, 4096, 0); 
	return bytesin;
}

string Server::ReceivingFromText(string findword, string word)
{
	ifstream NewFile;
	NewFile.open("deneme.txt");
	string line;
	if (NewFile.is_open())
	{
		while (!NewFile.eof())
		{
			getline(NewFile, line);
			if ((line.find(findword)) != string::npos)
			{
				line.erase(0, size(findword));
				word = line;
				NewFile.close();
				return word;
			}
		}
	}
}

void Server::Sendip()
{
	int socketcount = SocketCount();
	for (int i = 0; i < socketcount; i++)
	{
		sock = copy.fd_array[i];
		if (sock == listening)
		{
			SOCKET client = ClientAcceptance();
			CleanHostAndService();
			GetHostAndService();
			FD_SET(client, &master);
			string welcomemsg = "welcome to the awesome server!";
			send(client, welcomemsg.c_str(), welcomemsg.size() + 1, 0);
		}
		else
		{
			GetIp(sock);
			if (bytesin <= 0)
			{
				closesocket(sock);
				FD_CLR(sock, &master);
			}
			else
			{
				ip = string(buf, 0, bytesin);
				ofstream dosya;
				dosya.open("deneme.txt");
				dosya << ip;
				dosya.close();

				sockArray[numberofclient] = sock;

				ipAddress = ReceivingFromText(findipAddress, ipAddress);
				biosVersion = ReceivingFromText(findbiosVersion, biosVersion);
				OsName = ReceivingFromText(findOsName, OsName);
				systemManufacturer = ReceivingFromText(findSystemManufacturer, systemManufacturer);
				physicalMemory = ReceivingFromText(findmemory, physicalMemory);
				ethernet = ReceivingFromText(findethernet, ethernet);
				wifi = ReceivingFromText(findwifi, wifi);
			}
		}
	}
}






