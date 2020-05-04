#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int soc_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (soc_desc == -1){
		cout << "Could not create socket\n";
		return -1;	
	}
	
	struct sockaddr_in server;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (connect(soc_desc, (struct sockaddr *)&server, sizeof(server)) ==0)
		cout << "Connection successful\n";
	else {
		cout << "Can not connect\n";
		return 1;
	}
	char buff[100];
	cout << "Enter filename: ";
	cin >> buff;
	
	send(soc_desc, buff, sizeof(buff), 0);
 
	cout << "Server Reply\n";
	while (strcmp(buff, "EOF") != 0){
	        if(strcmp(buff, "File can not be fetched") == 0)
			break;
	 	recv(soc_desc, buff, sizeof(buff), 0);
		cout << buff <<endl;
	}

	return 0;
}
