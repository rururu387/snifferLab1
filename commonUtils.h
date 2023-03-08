#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include <QMessageBox>
#include <string>

class CommonUtils
{
public:
    CommonUtils();
    static void showError(std::string error);
    static std::shared_ptr<std::wstring> formatHeaderUtil(std::map<int, std::wstring> headerMap);
    static std::vector<bool> getBoolVectorFromBytes(std::vector<std::byte> byteVector);
    static std::shared_ptr<std::wstring> formatLine(std::vector<bool> bitVector, int indexToCopyFrom);
    inline static const std::wstring numbersHeader = L"0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31\n";
};

#endif // COMMONUTILS_H
