#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int	main(int agrc, char** agrv)
{
	int	sock_server = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_server == -1)
	{
		std::cerr << "INVALID SOCKET" << std::endl;
		return 0;
	}

	int					port = 4444;
	struct sockaddr_in	address;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if (bind(sock_server, (struct sockaddr *)&address, sizeof(address)) == -1)
	{
		std::cerr << "BIND ERROR" << std::endl;
		close(sock_server);
		return 0;
	}
	std::cout << "Successful socket binding, port : " << port << std::endl;
	if (listen(sock_server, 3) == -1)
	{
		std::cerr << "LISTEN ERROR" << std::endl;
		close(sock_server);
		return 0;
	}
	std::cout << "Waiting for a connection on port : " << port << std::endl;
	fd_set	readfds;
	while (true)
	{
		FD_ZERO(&readfds);
		FD_SET(sock_server, &readfds);
	}
}
