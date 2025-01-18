#ifndef SERVER_HPP
#define SERVER_HPP

#include "User.hpp"
#include "Channel.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>
#include <cerrno>
#include <iomanip>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_PORT UINT16_MAX
#define MAX_BUFFER 1024
#define MAX_HOST_NAME 512

class User;
class Channel;
class Server
{
private:
	Server(void);

public:
	static const int MAX_CLIENTS = FD_SETSIZE;
	static const int BUFFER_SIZE = MAX_BUFFER;
	static std::string _password;
	static std::string _hostName;
	static std::string bufferStr;
	static char c_buffer[MAX_BUFFER];
	static char c_hostName[MAX_HOST_NAME];
	static int serverSocket;
	static int max_sd;
	static int sd;
	static int valread;
	static int _port;
	static int newSocket;
	static int curIndex;
	static int addrlen;
	static struct sockaddr_in address;
	static fd_set readfds;
	class ServerException : public std::exception
	{
		private:
			std::string _msg;
		public:
			ServerException(std::string msg) : _msg(msg) {}
			virtual ~ServerException() throw() {}
			virtual const char *what() const throw() { return _msg.c_str(); }
	};
	static std::vector<int> _fds;
	static std::vector<User> _users;
	static std::vector<Channel> _channels;
	static void openSocket(void);
	static void run(void);
	static void acceptConnection(void);
	static void handleClientMessages(void);
	static void showUsers(void);
	static void showChannels(void);
	static std::string getPassword(void);
};

#endif