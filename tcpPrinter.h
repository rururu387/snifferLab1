#ifndef TCPPRINTER_H
#define TCPPRINTER_H

#include "prettyPrinter.h"
#include "commonUtils.h"

class TcpPrinter : PrettyPrinter
{
public:
    std::wstring getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData) override;
    ~TcpPrinter() override {};
};

#endif // IPPRINTER_H
