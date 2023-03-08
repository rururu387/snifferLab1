#include "ipPrinter.h"

std::wstring IpPrinter::getPrettyHeaderStr(std::optional<std::vector<std::byte>> rawData)
{
    if (!rawData.has_value() || sizeof(rawData.value()) < 20)
    {
        CommonUtils::showError("Trying to represent incorrect data");
        return L"";
    }

    std::wstring dataStr = L"IP HEADER\n" + CommonUtils::numbersHeader;
    dataStr.reserve(192);
    auto bitVector = CommonUtils::getBoolVectorFromBytes(rawData.value());

    std::map<int, std::wstring> firstLineMap = {{0, L"Версия"},
                                               {4, L"Размер заголовка"},
                                               {8, L"DSCP"},
                                               {14, L"ECN"},
                                               {16, L"Размер пакета"}};
    dataStr += *CommonUtils::formatHeaderUtil(firstLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 0);

    std::map<int, std::wstring> secondLineMap = {{0, L"Идентификатор"},
                                                {16, L"Флаги"},
                                                {19, L"Смещение фрагмента"}
                                               };
    dataStr += *CommonUtils::formatHeaderUtil(secondLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 32);

    std::map<int, std::wstring> thirdLineMap = {{0, L"Время жизни пакета"},
                                                {8, L"Протокол"},
                                                {16, L"Контрольная сумма заголовка"}
                                               };
    dataStr += *CommonUtils::formatHeaderUtil(thirdLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 64);

    std::map<int, std::wstring> fourthLineMap = {{0, L"IP-адрес источника"}};
    dataStr += *CommonUtils::formatHeaderUtil(fourthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 96);

    std::map<int, std::wstring> fifthLineMap = {{0, L"IP-адрес назначения"}};
    dataStr += *CommonUtils::formatHeaderUtil(fifthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 128);

    std::map<int, std::wstring> sixthLineMap = {{0, L"Опции"}};
    dataStr += *CommonUtils::formatHeaderUtil(sixthLineMap) + L"\n";
    dataStr += *CommonUtils::formatLine(bitVector, 160);

    return dataStr;
}
