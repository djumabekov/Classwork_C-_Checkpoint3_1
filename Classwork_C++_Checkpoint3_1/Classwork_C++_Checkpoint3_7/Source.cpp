#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

/*
  Написание функций поиска и удаления пробелов
LTrim() - удаление пробельных символов слева - ведущие пробелы
RTrim() - удаление пробельных символов справа - конечные пробелы
Trim()  - удаление пробельных символов справа и слева

TrimAll() - удаление всех   лишних   пробелов
            удаление всех лишних пробелов
"    Касенов     Жанат     Маратович           "
"Касенов Жанат Маратович"
*/

// Прототипы
// Ф-ция удаления ведущих (слева) пробелов в строке
char* LTrim(char* str);
// Ф-ция удаления хвостовых (справа) пробелов в строке
char* RTrim(char* str);
// Ф-ция удаления ведущих и хвостовых пробелов в строке
char* Trim(char* str);
// Ф-ция удаления всех лишних пробелов в строке
char* TrimAll(char* str);
#define SIZE 200
int main()
{
    system("chcp 1251 > nul");
    char str[SIZE];
    cout << "Введите строку: ";
    cin.getline(str, SIZE);
    cout << "str:   \"" << str << "\"\n";
    //cout << "RTrim: \"" << RTrim(str) << "\"" << endl;
    //cout << "LTrim: \"" << LTrim(str) << "\"" << endl;
    cout << "TrimAll: \"" << TrimAll(str) << "\"" << endl;

    cin.get(); cin.get();
}

// "Ф-ция удаления хвостовых пробелов           "
// "Ф-ция удаления хвостовых пробелов"
char* RTrim(char* str)
{
    if (str[0] == '\0') { return str; } // выход из-за пустой строки
    //if (!*str) { return str; } // выход из-за пустой строки
    int len = strlen(str); // текущая длина строки
    //if (len == 0) { return str; } // выход из-за пустой строки
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            //break;
            return str;
        }
    }
    str[0] = '\0'; // строка из пробелов ==> пустая строка
    return str;
}

char* LTrim(char* str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            break;
        }
    }
    int j = 0;
    for (; str[i] != '\0'; j++, i++) {
        str[j] = str[i];
    }
    str[j] = '\0';
    return str;
}

char* Trim(char* str)
{
    //LTrim(str);
    //RTrim(str);
    //return str;
    return LTrim(RTrim(str));
    //return RTrim(LTrim(str));
}
char* TrimAll(char* str)
{
    Trim(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            LTrim(str + i + 1);
            //LTrim(&str[i + 1]);
        }
    }
    return str;
}


#include <iostream>
#include <string> // для класса string
using namespace std;
#pragma warning(disable: 4996)

/*
Структуры

14. *Создайте структуру, описывающую точку в двумерной
системе координат (x, y).
С помощью этой структуры задайте две точки.
Напишите функцию, которая вычисляет расстояние
между этими двумя точками?

10.*Создать структуру, описывающую товар.
В структуру входят:
название товара, цена, описание, фирма изготовитель.
Реализовать функции для иллюстрации работы с этой структурой.

5. **Описать структуру Одежда (название, цвет, размер, длина).
Создать массив экземпляров структуры Одежда и написать программу, позволяющую:
- динамически изменять размер массива;
- выводить список одежды с размером больше или равно заданным;
- выводить список одежды с длиной больше или равно заданной;
- сортировать список одежды по размеру или длине;
- сортировать список одежды по названию;
*/
// Объявление структуры Point
struct Point { // PointXY, Point2D, Point3D
  // тело структуры, в нем
  // переменные, поля, элементы структуры
    string Name;  // название точки
    int x, y;     // координаты точки
};

void Input(Point& pt);
void Print(Point pt);

int main()
{
    system("chcp 1251 > nul");
    // объявление переменных типа Point
    Point a; // a - экземпляр структуры Point
    Point b = { "Точка B", 1, 2 }; // иниц-ция структурной переменной списком
    // поэлементная иниц-ция полей структурной переменной a
    a.Name = "Точка A";
    a.x = 10;
    a.y = 20;
    // печать полей структурной переменной a
    cout << "Поля переменной a:" << endl;
    cout << "Point::Name = " << a.Name << endl;
    cout << "Point::x    = " << a.x << endl;
    cout << "Point::y    = " << a.y << endl;
    // A(1;2)
    cout << b.Name << "("
        << b.x << ";"
        << b.y << ")\n";
    // чтение и печать для переменны a и b
    Input(a);
    Print(a);

    Input(b);
    Print(b);
    // локальный прототип ф-ции Distance()
    double Distance(Point p1, Point p2);
    cout << "Расстояние между a и b = " << Distance(a, b) << endl;
    cout << "Расстояние между b и a = " << Distance(b, a) << endl;

    cin.get(); cin.get();
}
// Ф-ция вычисления расстояния между двумя точками типа Point
double Distance(Point p1, Point p2)
{
    double a = p1.y - p2.y; // a = y1 - y2
    double b = p1.x - p2.x; // b = x1 - x2
    // sqrt() - ф-ция извлечения квадратного корня
    double c = sqrt(a * a + b * b);
    return c;
}

// Ф-ция чтения с консоли и заполнение полей структуры
//  типа Point
void Input(Point& pt) {
    cout << "Введите название точки: ";
    //cin >> pt.Name; // чтение с консоли одного слова
    getline(cin, pt.Name); // чтение с консоли целой строки
    cout << "Введите координаты x,y: ";
    cin >> pt.x >> pt.y; // <ENTER>
    cin.ignore(); // убрать символ <ENTER> после работы cin>>
    //cin.get();
}

// Вывод на экран содержимого переменной типа Point
//  в формате A(1;2)
void Print(Point pt) {
    cout << pt.Name << "("
        << pt.x << ";"
        << pt.y << ")\n";
}
