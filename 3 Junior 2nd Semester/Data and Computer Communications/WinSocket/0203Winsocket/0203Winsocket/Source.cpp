#include <winsock2.h>
#include <ws2tcpip.h>
#include<iostream>
using namespace std;

#pragma comment(lib, "Ws2_32.lib")

int main()
{

	WORD wVersion = MAKEWORD(2, 2); // Used to request version 2.2 of Windows sockets
	WSADATA wsaData; // Data loaded by WSAStartup
	int iResult; // Error check if WSAStartup successful

	// Initialize Winsock
	iResult = WSAStartup(wVersion, &wsaData);
	if (iResult != 0)
	{
		cout<< "WSAStartup failed: " << iResult << endl;
		return 1;
	}

	//To get local hostname
	char host_name[128];
	gethostname(host_name, sizeof(host_name));
	cout << host_name << endl;
		
	//To get IP address of specific host
	struct hostent *remoteHost;
	struct in_addr addr;
	DWORD dwError;
	char **pAlias;
	int i=0;
	
	remoteHost = gethostbyname("www.google.com");
	if (remoteHost == NULL) 
	{
		dwError = WSAGetLastError();
		if (dwError != 0)
		{
			if (dwError == WSAHOST_NOT_FOUND) 
			{
				cout << "Host not found\n";
				return 1;
			}
			else if (dwError == WSANO_DATA)
			{
				cout << "No data record found\n";
			}
			else 
			{
				cout << "Function failed with error: " << dwError << endl;
				return 1;
			}
		}
	}
	else
	{
		cout << "Function returned:\n";
		cout << "Official name: " << remoteHost->h_name << endl;

		for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++) 
		{
			cout << "Alternate name #" << ++i << ": " << *pAlias << endl;
		}
		cout << "\tAddress type: ";
		switch (remoteHost->h_addrtype)
		{
			case AF_INET:
				cout << "AF_INET\n";
				break;
			case AF_NETBIOS:
				cout << "AF_NETBIOS\n";
				break;
			default:
				cout << remoteHost->h_addrtype << endl;
				break;
		}
		cout << "\tAddress length: " << remoteHost->h_length << endl;
		i = 0;
		if (remoteHost->h_addrtype == AF_INET)
		{
			while (remoteHost->h_addr_list[i] != 0) 
			{

				addr.s_addr = *(u_long *)remoteHost->h_addr_list[i++];
				cout << "\tIP Address #" << i << ": " << inet_ntoa(addr) << endl;
			}
		}
		else if (remoteHost->h_addrtype == AF_NETBIOS)
		{
			cout << "NETBIOS address was returned\n";
		}
	}
	WSACleanup(); //to close windows sockets
	return 0;
}