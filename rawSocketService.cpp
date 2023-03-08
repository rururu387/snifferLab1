#include "rawSocketService.h"

RawSocketService::RawSocketService()
{

}

int RawSocketService::initializeRawConnection()
{
    return socket(AF_INET , SOCK_RAW , IPPROTO_TCP);
}

std::optional<std::vector<std::byte>> RawSocketService::getPacket()
{
    auto rawSocket = initializeRawConnection();

    if(rawSocket < 0)
    {
        CommonUtils::showError("Socket error");
        return std::nullopt;
    }

    int dataSize;
    struct sockaddr sAddr;
    struct in_addr in;

    auto sAddrSize = (socklen_t) sizeof(sAddr);

    std::vector<std::byte> buffer;
    buffer.resize(65536);


    dataSize = recvfrom(rawSocket, buffer.data(), 65536, 0, &sAddr, &sAddrSize);

    if(dataSize < 0)
    {
        CommonUtils::showError("Recvfrom error, failed to get packets\n");
        close(rawSocket);
        return std::nullopt;
    }

    return std::make_optional(buffer);
}
