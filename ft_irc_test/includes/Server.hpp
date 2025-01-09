#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/event.h>
#include <fcntl.h>
#include <unistd.h>
#include <map>

class Server{

private:
	const int _port;
    const std::string _password;
    const int _server_fd;
    const int _kqueue_fd;
    std::string _created_time;
	struct sockaddr_in _server_addr;

	void	initServerInfo();
public:
	Server(void);
    Server(int, std::string);
    ~Server();
    Server(const Server &obj);
    Server& operator=(const Server &obj);

	void run();
};

#endif