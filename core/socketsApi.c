#include "socketsApi.h"

struct SocketInfo* createSocketImpl(bool network, NetworkType networkType);

struct SocketInfo* createUnixSocket(const char* address, bool blocking)
{
    struct SocketInfo* socketInfo = createSocketImpl(false, Unix);
    return socketInfo;
}

struct SocketInfo* createUdpSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking)
{
    struct SocketInfo* socketInfo = createSocketImpl(true, networkType);
    return socketInfo;
}

struct SocketInfo* createTcpSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking)
{
    struct SocketInfo* socketInfo = createSocketImpl(true, networkType);
    return socketInfo;
}

struct SocketInfo* createRawSocket(const char* address, NetworkType networkType, unsigned short port, bool blocking)
{
    struct SocketInfo* socketInfo = createSocketImpl(true, networkType);
    return socketInfo;
}

struct SocketInfo* createSocketImpl(bool network, NetworkType networkType)
{
    struct SocketInfo* socketInfo = (struct SocketInfo*) malloc(sizeof(struct SocketInfo));
    socketInfo->_networkAddress = network ? (struct sockaddr_in*) malloc(sizeof(struct sockaddr_in)) : NULL;
    socketInfo->_unixAddress = !network ? (struct sockaddr_un*) malloc(sizeof(struct sockaddr_un)) : NULL;
    return socketInfo;
}

void destroySocket(struct SocketInfo* socket)
{
    if(socket == NULL)
        return;
    if(socket->_networkAddress != NULL)
        free(socket->_networkAddress);
    if(socket->_unixAddress)
        free(socket->_unixAddress);
    free(socket);
}

bool bindSocket(const struct  SocketInfo* socketInfo)
{
    return false;
}

int send(const char* data)
{
    return -1;
}

int receive(char* buffer, int bufferSize)
{
    return -1;
}

void shutsown(const struct SocketInfo, int direction)
{

}

bool openClient(const struct SocketInfo* socket)
{
    return false;
}

void closeClient(const struct SocketInfo* socket)
{

}

bool connect (const struct SocketInfo* socket, const char* remoteIp, unsigned short port)
{
    return false;
}

bool openServer(const struct SocketInfo* socket)
{
    return false;
}

void closeServer(const struct SocketInfo* socket)
{

}

void processListen(const struct SocketInfo* server, const struct ConnectionFilter* *clientsFilters, bool (*plistenInterrupt)())
{

}

bool accept(const struct ConnectionFilter* *clientsFilters)
{
    return false;
}
