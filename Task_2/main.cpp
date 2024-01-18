#include  "coder.cpp"
#include <locale>
using namespace std;

bool isValid(const wstring& s)
{

    for (auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout<<L"Введи ключ (целое число): ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<L"ключ недействителен.\n";
        return 0;
    }

    coder cipher(key);
    do {
        wcout<<L"Введи операцию (0-завершить, 1-зашифровать, 2-расшифровать): ";
        wcin>>op;
        if (op != 0 and op != 1 and op != 2) {
            wcout<<L"Нeзаконная операция!\n";
        } else if (op >0) {
            wcout<<L"Введи текст(без пробелов и капсом): ";
            wcin.ignore(); 
            getline(wcin, text);
            if (isValid(text)) {
                if (op == 1) {
                    wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else if (op == 2){
                    wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Операция прервана.... неверный текст....\n";
            }
        }
    } while (op != 0);
    return 0;
}
