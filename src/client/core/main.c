#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
	//create tcp socket
	int net_socket;
	net_socket = socket(AF_INET, SOCK_STREAM, 0);

	//TODO: Take user input for server destination.
    //printf("Server IP: ");
	//scanf("%d", &serverIp);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(28600);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	//Check for connection errors
	if (connection_status == -1){
		printf('There was an error connecting to the server.');
	}

	char server_response[256];
	recv(net_socket, &server_response, sizeof(server_response), 0);

	printf('The server sent this data: %s\n', server_response);

	close(net_socket);

	return 0;
}