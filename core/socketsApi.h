#ifnded SOCKETS_API
#define SOCKETS_API
/* Conditional heders include */
#ifdef __linux__
    #include <netinet/ip.h>
#elif _WIN32
    #include<winsock2.h>
#else
/* to do: unix? */
#endif
/* Overriding Types */
struct SocketInfo
{
    sockaddr_in _socketAddress;
    int _socket;
};

//struct ConnectionFilter;

SocketInfo createUnixSocket(const char* socketAddress, unsigned short port = -1);
SocketInfo createUdpSocket(const char* socketAddress, unsigned short port = -1);
SocketInfo createTcpSocket(const char* socketAddress, unsigned short port = -1);
SocketInfo createRawSocket(const char* socketAddress, unsigned short port = -1);

/* Both client and server functions*/
bool bindSockect(const SocketInfo* socketInfo);
int send(const char* data);
int recieve(char* buffer, int bufferSize);
/* Client functions */
bool connect (const SocketInfo* socket, const char* remoteIp, unsigned short port);
/* Server functions */
void processListen(const SocketInfo* server, ConnectionFilter;* *clientsFilters, bool (*plistebInterrupt)() = null);
bool accept(ConnectionFilter;* *clientsFilters);

#endif
