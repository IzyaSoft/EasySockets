#ifndef SOCKETS_API
#define SOCKETS_API

#include <stdlib.h>
#include <stdbool.h>
/* Conditional headers include */
#ifdef __linux__
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <sys/un.h>
#elif _WIN32
    #include<winsock2.h>
#else
/* to do: unix? */
#endif

enum NetworkType
{
    IPv4 = 0,
    IPv6 = 1
};

/* Common Types */
struct SocketInfo
{
    struct sockaddr_in* _networkAddress;
    struct sockaddr_in6* _network6Address;
    struct sockaddr_un* _unixAddress;
    int _socket;
};

struct ConnectionFilter
{
    bool (*pFiltrate)(const struct SocketInfo* server, int client);
};

struct SocketInfo* createUnixSocket(const char* address, bool blocking = false);
// todo: umv: type of IP: v4 or v6
struct SocketInfo* createUdpSocket(const char* address, unsigned short port, bool blocking = false);
// todo: umv: type of IP: v4 or v6
struct SocketInfo* createTcpSocket(const char* address, unsigned short port, bool blocking = false);
// todo: umv: type of IP: v4 or v6
struct SocketInfo* createRawSocket(const char* address, unsigned short port, bool blocking = false);
// todo: umv: type of IP: v4 or v6
struct SocketInfo* createSocketImpl(bool network);
void freeSocket(struct SocketInfo* socket);

/* Both client and server functions*/
bool bindSocket(const struct  SocketInfo* socketInfo);
int send(const char* data);
int receive(char* buffer, int bufferSize);
/* Client functions */
bool connect (const struct SocketInfo* socket, const char* remoteIp, unsigned short port);
/* Server functions */
void processListen(const struct SocketInfo* server, const struct ConnectionFilter* *clientsFilters, bool (*plistenInterrupt)() = NULL);
bool accept(const struct ConnectionFilter* *clientsFilters);

#endif
