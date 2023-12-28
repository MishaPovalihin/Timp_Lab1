#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

class coder
{
private:
    int key1; // кол-во столбцов
public:
    coder()=delete; // запрет конструктора без параметров
    coder(const int& key) :key1(key) {}; //установка ключа
    std::wstring encrypt(const std::wstring& open_text); // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};
