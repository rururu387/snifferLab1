#ifndef IPPRINTER_H
#define IPPRINTER_H

#include "prettyPrinter.h"
#include "commonUtils.h"
#include <map>

class IpPrinter : PrettyPrinter
{
public:
    std::wstring getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData) override;
    ~IpPrinter() override {};
};

#endif // IPPRINTER_H
