#include <iostream>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<string>> sities;
multimap<string, string> capitals;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Print()
{
    system("cls"); string country;
    SetColor(Yellow, Black);
    cout << setw(15) << "Страна" << setw(15) << "Города:" << endl;
    SetColor(White, Black);
    map<string, vector<string>>::iterator it;
    for (it = sities.begin(); it != sities.end(); it++)
    {
        sort(sities[it->first].begin(), sities[it->first].end());
        SetColor(LightCyan, Black);
        cout << setw(15) << it->first; country = it->first;
        SetColor(White, Black);
        for (string n : it->second)
            cout << setw(15) << n;
        SetColor(Yellow, Black);
        cout << endl << "Столица: ";
        SetColor(LightRed, Black); 
        multimap<string, string>::iterator i;
        if (capitals.find(country) != capitals.end()) {
            i = capitals.find(country);
            cout << i->second << endl;
        }
        SetColor(White, Black);
    }
}

void NewSities()
{
    string c; string s;
    cout << "Введите страну: "; cin >> c; 
    cout << "Введите город: "; cin >> s;
    sities[c].push_back(s);
    sort(sities[c].begin(), sities[c].end());
}
void NewSities(string c, string s)
{
    sities[c].push_back(s);
    sort(sities[c].begin(), sities[c].end());
}

template<typename... Arguments>
void NewSities(string c, string s, Arguments... args)
{
    NewSities(c, s);
    NewSities(c, args...);
}

void FindCap()
{
    string cap; int a = 0;
    cout << "Введите столицу: "; cin >> cap;
    multimap<string, string>::iterator it;
    for (it = capitals.begin(); it != capitals.end(); it++)
    {
        if ((it->second) == cap)
        {
            cout << "Это столица страны: " << it->first << endl;
            a++;
            break;
        }
    }
    if (a == 0)
        cout << "Не найдено!" << endl;
}

void FindSit()
{
    string sit; int a = 0;
    cout << "Введите город: "; cin >> sit;
    map<string, vector<string>>::iterator it;
    for (it = sities.begin(); it != sities.end(); it++)
    {
        for (string n : it->second)
        {
            if (n == sit)
            {
                cout << "Это город в стране: " << it->first << endl;
                a++;
                break;
            }
        }
    }
    if (a == 0)
        cout << "Не найдено!" << endl;
}

void FindCon()
{
    string con;
    cout << "Введите страну: "; cin >> con;
    map<string, vector<string>>::iterator it;
    multimap<string, string>::iterator i;
    cout << "Города: ";
    it = sities.find(con);
    i = capitals.find(con);
    for (string n : it->second)
        cout << setw(15) << n;
    cout << endl << "Столица: " << i->second << endl;

}

int main()
{
    system("mode con cols=140 lines=30");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char v, t;
 
    sities["Россия"] = { "Астрахань" };
    capitals.insert(pair<string, string>("Россия", "Москва"));
    NewSities("Россия", "Самара");
    NewSities("Россия", "Тамбов", "Омск", "Казань");

    sities["США"] = {"Лос-Анджелес", "Чикаго", "Финикс", "Даллас"};
    capitals.insert(pair<string, string>("США", "Вашингтон"));

    sities["Мексика"] = { "Сапопан", "Монтеррей", "Тихуана", "Чиуауа" };
    capitals.insert(pair<string, string>("Мексика", "Мехико"));

    sities["Украина"] = { "Харьков", "Одесса", "Николаев", "Львов", "Черновцы", "Сумы"};
    capitals.insert(pair<string, string>("Украина", "Киев"));

    sities["Китай"] = { "Сиань", "Ухань", "Шанхай", "Чанша" };
    capitals.insert(pair<string, string>("Китай", "Пекин"));

    while (true)
    {
        Print(); v = ' ';
        cout << "Выберите дальнейшее действие:\n1. Найти все города в стране:  ";
        cout << "2. Найти страну по столице\n3. Найти страну по городу      4. Новый город                    ";
        SetColor(DarkGray, Black); cout << "5. Выход из программы\n "; SetColor(White, Black); cout << " >> ";
        cin >> v;
        switch (v)
        {
        case '1':   FindCon(); break;
        case '2':   FindCap(); break;
        case '3':   FindSit(); break;
        case '4': NewSities(); break;
        case '5':     exit(0); break;
        }
        cout << "Введите что угодно для продолжения: ";
        cin >> t;
    }
}
