#pragma once
#pragma once
#include <ws2tcpip.h>
#include <string>
using namespace std;
#define MAXCLIENT 100


class Server
{
private:
	SOCKET listening;
	sockaddr_in hint, clien;
	string error[10100];						// bağlantı hatası nedenleri
	fd_set copy;								
	char buf[4096];								// Clientten gelen data

public:
	SOCKET sock;								// yeni bir giriş yada çıkış yapan client'ın socket numarası
	SOCKET sockArray[MAXCLIENT];				// Bütün clientların socket numaralarını tutan array
	int errorMessage;							// Bağlantı hatası kodu
	fd_set master;								
	char host[NI_MAXHOST];						// yeni giriş yapan client'ın host name
	char service[NI_MAXHOST];					// yeni giriş yapan client'ın servis numarası
	string ip;									// ip Adresi
	int bytesin;								// Client'tan gelen data sayısı							
	int oldValueNumberOfClient;					// yeni bir giriş yada çıkış yapılmadan önceki Client Sayısı
	int numberofclient;							// Güncel Client sayısı


			// find string from text file
	string findipAddress = "Ip Address:";
	string findbiosVersion = "Bios Version:";
	string findOsName = "OS Name:";
	string findSystemManufacturer = "System Manufacturer:";
	string findmemory = "Total Pysical Memory:";
	string findethernet = "Ethernet:";
	string findwifi = "Wifi:";


			// return string to keep new value
	string ipAddress;
	string physicalMemory;
	string OsName;
	string systemManufacturer;
	string biosVersion;
	string ethernet;
	string wifi;


	int initializeWinsock();
	SOCKET createdSocket();
	string errorMessageCreateSocket();
	void ConnectIpAndPort();
	void BindListening();
	void listenSocket();
	void loadConfig();
	void Sendip();
	void ListeningMaster();
	void ErrorMessage();
	string yazdirError();
	void GetHostAndService();
	void CleanHostAndService();
	SOCKET ClientAcceptance();
	int SocketCount();
	int GetIp(SOCKET);
	string ReceivingFromText(string, string);

};

struct Config {
	string serverOfIpAddress;						// Server'ın ip Addresi config.txt'den
	int serverPort;									// Server'ın dinleyeceği port numarası config.txt'den
};