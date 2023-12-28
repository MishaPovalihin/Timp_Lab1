#include  "coder.h"

using namespace std;

wstring coder::encrypt(const std::wstring& open_text) // шифрование
{
    wstring tabl = open_text;
    int len, nstrok, index, x;
    len = open_text.length(); // введенный текст
    nstrok = (len - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < len) {
                tabl[x] = open_text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

wstring coder::decrypt(const std::wstring& cipher_text) // расшифрование
{
    wstring tabl = cipher_text;
    int len, nstrok, index, x;
    len = cipher_text.length();
    nstrok = (len - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < len) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}
