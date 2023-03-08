#include "udpPrinter.h"

UdpPrinter::UdpPrinter()
{

}

std::wstring UdpPrinter::getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData)
{
    if (!rawData.has_value() || sizeof(rawData.value()) < 20)
    {
        CommonUtils::showError("Trying to represent incorrect data");
        return L"";
    }

    std::wstring dataStr = L"UDP HEADER\n" + CommonUtils::numbersHeader;
    dataStr.reserve(96);
    auto bitVector = CommonUtils::getBoolVectorFromBytes(rawData.value());

    std::map<int, std::wstring> firstLineMap = {{0, L"Порт отправки"},
                                                {16, L"Порт назначения"}
                                               };
    dataStr += *CommonUtils::formatHeaderUtil(firstLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 0);

    std::map<int, std::wstring> secondLineMap = {{0, L"Длина"},
                                                 {16, L"Контрольная сумма"}
                                                };
    dataStr += *CommonUtils::formatHeaderUtil(secondLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 0);

    return dataStr;
}
