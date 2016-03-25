#ifnded SOCKETS_API
#define SOCKETS_API
/* Overriding Types */
struct SocketInfo;
struct ConnectionFilter;
/* Platform specific include*/

SocketInfo createSocket();

SocketInfo createUdpSocket();
SocketInfo createTcpSocket();
SocketInfo createRawSocket();

/* Both client and server functions*/
bool bindSockect(const SocketInfo* socketInfo);
int send(const char* data);
int recieve(char* buffer, int bufferSize);
/* Client functions */
bool connect (const SocketInfo* socket, char* remoteIp, unsigned int port);
/* Server functions */
void processListen(const SocketInfo* server, ConnectionFilter;* *clientsFilters, bool (*plistebInterrupt)() = null);
bool accept(ConnectionFilter;* *clientsFilters);

#endif
