#ifndef UDPPRINTER_H
#define UDPPRINTER_H

#include "prettyPrinter.h"
#include "commonUtils.h"

class UdpPrinter : PrettyPrinter
{
public:
    std::wstring getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData) override;
    UdpPrinter();
    ~UdpPrinter() override {};
};

#endif // UDPPRINTER_H
