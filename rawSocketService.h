#ifndef RAWSOCKETSERVICE_H
#define RAWSOCKETSERVICE_H

#include <memory>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include "commonUtils.h"

class RawSocketService
{
public:
    RawSocketService();

    std::optional<std::vector<std::byte>> getPacket();

private:
    int initializeRawConnection();
};

#endif // RAWSOCKETSERVICE_H
