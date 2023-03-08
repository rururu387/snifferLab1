#include "commonUtils.h"

CommonUtils::CommonUtils()
{
}

void CommonUtils::showError(std::string error)
{
    QMessageBox errorBox;
    errorBox.setText(error.c_str());
    errorBox.exec();
}

std::shared_ptr<std::wstring> CommonUtils::formatHeaderUtil(std::map<int, std::wstring> headerMap)
{
    std::wstring* str = new std::wstring();
    str->reserve(32 * 6);
    for (auto header : headerMap)
    {
        while (str->size() <= header.first * 6)
        {
            str->append(L" ");
        }

        str->resize(header.first * 6);

        for (int i = 0; i < 3 && str->size() != 0; i++)
        {
            str->pop_back();
        }

        str->append(L"|  ");
        str->append(header.second);
    }

    return std::make_shared<std::wstring>(*str);
}

std::vector<bool> CommonUtils::getBoolVectorFromBytes(std::vector<std::byte> byteVector)
{
//    std::vector<bool> a = {true, false, true, false};

//    auto a0 = a.at(0).operator bool();
//    auto a1 = a.at(1).operator bool();
//    auto a2 = a.at(2).operator bool();
//    auto a3 = a.at(3).operator bool();

//    for (auto&& aIt : a)
//    {
//        auto dad = aIt;
//        auto f = dad.operator bool();
//        auto f1 = 1;
//    }

    std::vector<bool> bitVector;
    bitVector.reserve(8 * byteVector.size());

    for (auto byte : byteVector)
    {
        bitVector.push_back((byte & std::byte{0b10000000}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b01000000}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00100000}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00010000}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00001000}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00000100}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00000010}) != std::byte{0});
        bitVector.push_back((byte & std::byte{0b00000001}) != std::byte{0});
    }
    return bitVector;
}

std::shared_ptr<std::wstring> CommonUtils::formatLine(std::vector<bool> bitVector, int indexToCopyFrom)
{
    auto dataStr = new std::wstring();
    for (auto index = indexToCopyFrom; index < indexToCopyFrom + 32; index++) {
        char currentBitChar = bitVector[index].operator bool() ? '1' : '0';
        *dataStr += currentBitChar;
        dataStr->append(L"     ");
    }
    *dataStr += L"\n";
    return std::make_shared<std::wstring>(*dataStr);
}
