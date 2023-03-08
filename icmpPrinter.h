#ifndef ICMPPRINTER_H
#define ICMPPRINTER_H

#include "prettyPrinter.h"
#include "commonUtils.h"

class IcmpPrinter : PrettyPrinter
{
public:
    std::wstring getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData) override;
    IcmpPrinter();
    ~IcmpPrinter() override {};
};
#endif // ICMPPRINTER_H
