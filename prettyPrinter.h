#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H

#include <string>
#include <memory>
#include <optional>
#include <vector>

class PrettyPrinter
{
public:
    PrettyPrinter();
    virtual std::wstring getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData) = 0;
    virtual ~PrettyPrinter() {};
};

#endif // PRETTYPRINTER_H
