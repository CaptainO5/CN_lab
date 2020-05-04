#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	int soc_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (soc_desc == -1)
		cout << "Could not create socket\n";
	else
		cout << "Socket created succesfully\n";

	struct sockaddr_in server, client;
	int c, new_soc;

	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (bind(soc_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
		cout << "Bind failed\n";
	else
		cout << "Binded\n";

	listen(soc_desc, 1);
	cout << "Listening...\n";

	c = sizeof(struct sockaddr_in);
	
	new_soc = accept(soc_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (new_soc < 0)
		cout << "Error Accepting\n";
	else
		cout << "Connection accepted\n";

	char buf[100];
	recv(new_soc, buf, 100, 0);
	
	cout << "Client Request: " << buf << endl;

	FILE *f = fopen(buf, "r");
	if (f == NULL)
		strcpy(buf, "File can not be fetched");
	else{
		fstream f;
		f.open(buf, fstream::in);
		string line;
		while(getline (f, line)){
			strcpy(buf, line.c_str());
			send(new_soc, buf, sizeof(buf), 1);
			cout << line << endl;
		}
		strcpy(buf, "EOF");
	}
	send(new_soc, buf, sizeof(buf), 0);
	
	return 0;
}
