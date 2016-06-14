#include "socketsApi.h"


struct SocketInfo* createUnixSocket(const char* address, bool blocking)
{
	struct SocketInfo* socketInfo = createSocketImpl(false);
    return socketInfo;
}

struct SocketInfo* createUdpSocket(const char* address, unsigned short port, bool blocking)
{
	struct SocketInfo* socketInfo = createSocketImpl(true);
    return socketInfo;
}

struct SocketInfo* createTcpSocket(const char* address, unsigned short port, bool blocking)
{
	struct SocketInfo* socketInfo = createSocketImpl(true);
    return socketInfo;
}

struct SocketInfo* createRawSocket(const char* address, unsigned short port, bool blocking)
{
	struct SocketInfo* socketInfo = createSocketImpl(true);
    return socketInfo;
}

struct SocketInfo* createSocketImpl(bool network)
{
	struct SocketInfo* socketInfo = (struct SocketInfo*) malloc(sizeof(struct SocketInfo));
    // socketInfo->_networkAddress = network ? (struct sockaddr_in*) malloc(sizeof(struct sockaddr_in)) : NULL;
    // socketInfo->_unixAddress = !network ? (struct sockaddr_un*) malloc(sizeof(struct sockaddr_un)) : NULL;
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
