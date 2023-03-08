#include "tcpPrinter.h"

std::wstring TcpPrinter::getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData)
{
    if (!rawData.has_value() || sizeof(rawData.value()) < 20)
    {
        CommonUtils::showError("Trying to represent incorrect data");
        return L"";
    }

    std::wstring dataStr = L"TCP HEADER\n" + CommonUtils::numbersHeader;
    dataStr.reserve(192);
    auto bitVector = CommonUtils::getBoolVectorFromBytes(rawData.value());

    std::map<int, std::wstring> firstLineMap = {{0, L"Порт отправки"},
                                               {16, L"Порт назначения"}
                                              };
    dataStr += *CommonUtils::formatHeaderUtil(firstLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 0);

    std::map<int, std::wstring> secondLineMap = {{0, L"Порядковый номер"}};
    dataStr += *CommonUtils::formatHeaderUtil(secondLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 32);

    std::map<int, std::wstring> thirdLineMap = {{0, L"Номер подтверждения"}};
    dataStr += *CommonUtils::formatHeaderUtil(thirdLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 64);

    std::map<int, std::wstring> fourthLineMap = {{0, L"Смещение"},
                                                {4, L"Зарезервировано"},
                                                {8, L"CWR"},
                                                {9, L"ECE"},
                                                {10, L"URG"},
                                                {11, L"ACK"},
                                                {12, L"PSH"},
                                                {13, L"RST"},
                                                {14, L"SYN"},
                                                {15, L"FIN"},
                                                {16, L"Размер окна"}
                                               };
    dataStr += *CommonUtils::formatHeaderUtil(fourthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 96);

    std::map<int, std::wstring> fifthLineMap = {{0, L"Контрольная сумма"},
                                               {16, L"Указатель важности"}
                                              };
    dataStr += *CommonUtils::formatHeaderUtil(fifthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 128);

    std::map<int, std::wstring> sixthLineMap = {{0, L"Опции"}};
    dataStr += *CommonUtils::formatHeaderUtil(sixthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 160);

    return dataStr;
}
