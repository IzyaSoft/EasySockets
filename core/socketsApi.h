#ifndef SOCKETS_API
#define SOCKETS_API

#include <stdlib.h>
#include <stdbool.h>
/* Conditional headers include */
#ifdef __linux__
    #include <sys/types.h>
    #include <sys/socket.h>
#elif _WIN32
    #include<winsock2.h>
#else
/* to do: unix? */
#endif

/* Common Types */
struct SocketInfo
{
    struct sockaddr_in* _networkAddress;
    struct sockaddr_un* _unixAddress;
    int _socket;
};

// struct ConnectionFilter;

struct SocketInfo* createUnixSocket(const char* address, bool blocking = false);
struct SocketInfo* createUdpSocket(const char* address, unsigned short port, bool blocking = false);
struct SocketInfo* createTcpSocket(const char* address, unsigned short port, bool blocking = false);
struct SocketInfo* createRawSocket(const char* address, unsigned short port, bool blocking = false);
struct SocketInfo* createSocketImpl(bool network);
void freeSocket(struct SocketInfo* socket);

/* Both client and server functions*/
bool bindSockect(const struct  SocketInfo* socketInfo);
int send(const char* data);
int recieve(char* buffer, int bufferSize);
/* Client functions */
bool connect (const struct SocketInfo* socket, const char* remoteIp, unsigned short port);
/* Server functions */
// void processListen(const SocketInfo* server, ConnectionFilter* *clientsFilters, bool (*plistebInterrupt)() = null);
// bool accept(ConnectionFilter;* *clientsFilters);

#endif
