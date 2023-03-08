#include "icmpPrinter.h"

IcmpPrinter::IcmpPrinter()
{

}

std::wstring IcmpPrinter::getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData)
{
    if (!rawData.has_value() || sizeof(rawData.value()) < 20)
    {
        CommonUtils::showError("Trying to represent incorrect data");
        return L"";
    }

    std::wstring dataStr = L"ICMP HEADER\n" + CommonUtils::numbersHeader;
    dataStr.reserve(96);
    auto bitVector = CommonUtils::getBoolVectorFromBytes(rawData.value());

    std::map<int, std::wstring> firstLineMap = {{0, L"Тип"},
                                               {8, L"Код"},
                                               {16, L"Контрольная сумма"}
                                              };
    dataStr += *CommonUtils::formatHeaderUtil(firstLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 0);
    dataStr += L"\n";

    std::map<int, std::wstring> secondLineMap = {{0, L"Зарезервировано (unused)"}};
    dataStr += *CommonUtils::formatHeaderUtil(secondLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 32);

    return dataStr;
}
