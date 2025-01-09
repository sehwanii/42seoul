#include "../includes/Server.hpp"

Server::Server(int port, std::string password)
	:_port(port),
	_password(password),
	_server_fd(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)),
	_kqueue_fd(kqueue())
{
	if (_server_fd < 0) {
        throw std::runtime_error("Socket creation failed");
    }
    if (_kqueue_fd < 0) {
        throw std::runtime_error("Kqueue creation failed");
    }
	initServerInfo();
	if (fcntl(_server_fd, F_SETFL, O_NONBLOCK) < 0){
        throw std::runtime_error("non blocking socket create failed");
    }
    // client의 요청을 기다리기 시작
    if (listen(_server_fd, 5) < 0) {
        throw std::runtime_error("Listen failed");
    }

    time_t now = time(0);
    _created_time = asctime(gmtime(&now));

    std::cout << "IRC server is running on port: " << _port << "\n";
}

Server::~Server() {
    // close(_server_fd);
    // close(_kqueue_fd);

    // for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
    //     delete it->second;
    // }
    // for (std::set<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
    //     delete *it;
    // }
}

void Server::initServerInfo() {
    // SOL_SOCKET의 SO_REUSEADDR은 커널에서 이미 바인딩한 주소를 재사용 하게 해줌 (에러 방지)
    int opt = 1;
    if (setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        throw std::runtime_error("Setsockopt failed");
    }

    memset(&_server_addr, 0, sizeof(_server_addr));
    _server_addr.sin_family = AF_INET;                   // 주소체계: ipv4
    _server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // INADDR_ANY 자신의 모든 랜카드로 ip를 받을 수 있음
    _server_addr.sin_port = htons(_port);                // Server ip의 PORT번호 지정

    // socket과 ip를 연결하는 작업
    if (bind(_server_fd, (struct sockaddr *)&_server_addr, sizeof(_server_addr)) < 0) {
        throw std::runtime_error("Bind failed");
    }
}

void Server::run() {
    // kqueue에 server_socket 등록
    // EVFILT_READ: 읽기 이벤트
    // EV_ADD: 이벤트 등록
    // EV_ENABLE: 이벤트 활성화
    struct kevent change_event;
    EV_SET(&change_event, _server_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    if (kevent(_kqueue_fd, &change_event, 1, NULL, 0, NULL) < 0) {
        throw std::runtime_error("Kevent registration failed");
    }

    while (true) {
        // 발생한 event가 반환될 배열
        struct kevent events[10];
        int new_events = kevent(_kqueue_fd, NULL, 0, events, 10, NULL);
        std::cout << new_events << "\n";
        if (new_events < 0) {
            throw std::runtime_error("Kevent failed");
        }

        for (int i = 0; i < new_events; ++i) {
            if ((int)events[i].ident == _server_fd) {
                std::cout <<"!!!";
				//connectNewClient();
            } else if (events[i].filter == EVFILT_READ) {
                std::cout <<"???";
				//handleClientEvent(events[i]);
            }
        }
    }
}