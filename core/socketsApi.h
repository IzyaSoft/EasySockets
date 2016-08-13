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
    Unix = 0,
    IPv4 = 1,
    IPv6 = 2
};

/* Common Types */
struct SocketInfo
{
    struct sockaddr_in* _networkAddress;
    struct sockaddr_in6* _network6Address;
    struct sockaddr_un* _unixAddress;
    int _socket;
    bool _isBlocking;
};

struct ConnectionFilter
{
    bool (*pFiltrate)(const struct SocketInfo* server, int client);
};

struct SocketInfo* createUnixSocket(const char* address, bool blocking = false);
struct SocketInfo* createUdpSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking = false);
struct SocketInfo* createTcpSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking = false);
struct SocketInfo* createRawSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking = false);
void freeSocket(struct SocketInfo* socket);

/* Both client and server functions*/
bool bindSocket(const struct  SocketInfo* socketInfo);
int send(const char* data);
int receive(char* buffer, int bufferSize);
void shutsown(const struct SocketInfo, int direction);
/* Client functions */
bool connect (const struct SocketInfo* socket, const char* remoteIp, unsigned short port);
bool openClient(const struct SocketInfo* socket);
void closeClient(const struct SocketInfo* socket);
/* Server functions */
bool openServer(const struct SocketInfo* socket);
void closeServer(const struct SocketInfo* socket);
void processListen(const struct SocketInfo* server, const struct ConnectionFilter* *clientsFilters, bool (*plistenInterrupt)() = NULL);
bool accept(const struct ConnectionFilter* *clientsFilters);

#endif
