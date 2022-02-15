#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

/*
  Ќаписание функций поиска и удалени€ пробелов
LTrim() - удаление пробельных символов слева - ведущие пробелы
RTrim() - удаление пробельных символов справа - конечные пробелы
Trim()  - удаление пробельных символов справа и слева

TrimAll() - удаление всех   лишних   пробелов
            удаление всех лишних пробелов
"     асенов     ∆анат     ћаратович           "
" асенов ∆анат ћаратович"
*/

// ѕрототипы
// ‘-ци€ удалени€ ведущих (слева) пробелов в строке
char* LTrim(char* str);
// ‘-ци€ удалени€ хвостовых (справа) пробелов в строке
char* RTrim(char* str);
// ‘-ци€ удалени€ ведущих и хвостовых пробелов в строке
char* Trim(char* str);
// ‘-ци€ удалени€ всех лишних пробелов в строке
char* TrimAll(char* str);
#define SIZE 200
int main()
{
    system("chcp 1251 > nul");
    char str[SIZE];
    cout << "¬ведите строку: ";
    cin.getline(str, SIZE);
    cout << "str:   \"" << str << "\"\n";
    cout << "RTrim: \"" << RTrim(str) << "\"" << endl;

    cin.get(); cin.get();
}

// "‘-ци€ удалени€ хвостовых пробелов           "
// "‘-ци€ удалени€ хвостовых пробелов"
char* RTrim(char* str)
{
    if (str[0] == '\0') { return str; } // выход из-за пустой строки
    //if (!*str) { return str; } // выход из-за пустой строки
    int len = strlen(str); // текуща€ длина строки
    //if (len == 0) { return str; } // выход из-за пустой строки
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            //break;
            return str;
        }
    }
    str[0] = '\0'; // строка из пробелов ==> пуста€ строка
    return str;
}
