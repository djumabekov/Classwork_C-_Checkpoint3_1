#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
Перегрузка функций. Шаблоны функций - только C++, в языке C - этих механизмов нет

1) Механизмы полиморфизма - только C++, в языке C - этих механизмов нет:
 - Перегрузка функций
 - Шаблоны функций
2) Прототипы функций.
3) Параметры по умолчанию.

Реализовать перегруженные варианты функции для заданий ниже.
Реализовать шаблоны функции для заданий ниже.

17. Написать перегруженные функции sum,
  находящие сумму двух вещественных либо двух целых чисел.
18. Написать перегруженные функции, возвращающие максимальное значение из двух, трех и четырех целых значений.
15. Написать функцию, которая принимает одномерный массив целых чисел и возвращает значения максимального числа в этом массиве.
20. Напишите функцию, которая определяет количество элементов передаваемого массива, которые меньше определенного числа, это число тоже передается в функцию.
Реализовать перегрузки для различных типов массивов.
27. Напишите ряд функций функций для работы с массивом:
- инициализация массива с консоли или случайными значениями в заданном диапазоне;
- вывод элементов массива на экран;
- суммирование элементов двух массивов в третий массив;
- удаление из массива элементов равных заданному;
- удаление из массива элемента по индексу;
a) Реализовать перегрузки для целых и вещественных чисел.
b) Реализовать функции в виде шаблонов.
*/

// глобальные прототипы ф-ций - декларация ф-ций
int   Sum(int a, int b); // прототип ф-ции Sum(int, int)
float Sum(float, float); // прототип ф-ции Sum(float, float)
void  Sum(int v1, int v2, int v3); // прототип ф-ции Sum(int, int, int)

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // вызов ф-ции Sum() с целочисленными параметрами
    int a = 1, b = 2;
    cout << a << " + " << b << " = "
        << Sum(a, b) << endl;
    //
    float f1 = 1.1, f2 = 2.2;
    cout << f1 << " + " << f2 << " = "
        << Sum(f1, f2) << endl;

    Sum(1, 2, 3); // void Sum(int, int, int);

    cout << Sum(a, (int)f1) << endl; // int + float ==> int
    cout << Sum(f1, float(a)) << endl; // float + int ==> float

    cin.get(); cin.get();
}

// перегруженная ф-ция сложения двух целых чисел
int Sum(int a, int b)
{
    return a + b;
}

// перегруженная ф-ция сложения трех целых чисел
void Sum(int v1, int v2, int v3)
{
    cout << v1 << "+" << v2 << "+" << v3
        << " = " << v1 + v2 + v3 << endl;
}

// перегруженная ф-ция сложения двух чисел типа float
float Sum(float a, float b)
{
    return a + b;
}


#include <iostream>
#include <iomanip>
#include <string> // class string
#include <time.h>
using namespace std;

/*
Перегрузка функций. Шаблоны функций - только C++, в языке C - этих механизмов нет

1) Механизмы полиморфизма - только C++, в языке C - этих механизмов нет:
 - Перегрузка функций
 - Шаблоны функций
2) Прототипы функций.
3) Параметры по умолчанию.

Реализовать перегруженные варианты функции для заданий ниже.
Реализовать шаблоны функции для заданий ниже.

17. Написать перегруженные функции sum,
  находящие сумму двух вещественных либо двух целых чисел.
18. Написать перегруженные функции, возвращающие максимальное значение из двух, трех и четырех целых значений.
15. Написать функцию, которая принимает одномерный массив целых чисел и возвращает значения максимального числа в этом массиве.
20. Напишите функцию, которая определяет количество элементов передаваемого массива, которые меньше определенного числа, это число тоже передается в функцию.
Реализовать перегрузки для различных типов массивов.
27. Напишите ряд функций функций для работы с массивом:
- инициализация массива с консоли или случайными значениями в заданном диапазоне;
- вывод элементов массива на экран;
- суммирование элементов двух массивов в третий массив;
- удаление из массива элементов равных заданному;
- удаление из массива элемента по индексу;
a) Реализовать перегрузки для целых и вещественных чисел.
b) Реализовать функции в виде шаблонов.
*/

// глобальные прототипы ф-ций - декларация ф-ций
//int   Sum(int a, int b); // прототип ф-ции Sum(int, int)
//float Sum(float, float); // прототип ф-ции Sum(float, float)
//void  Sum(int v1, int v2, int v3); // прототип ф-ции Sum(int, int, int)

template <typename MyType>
MyType Sum(MyType a, MyType b);

int main() {

    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // вызов ф-ции Sum() с целочисленными параметрами
    int a = 1, b = 2;
    cout << a << " + " << b << " = "
        << Sum(a, b) << endl;
    swap(a, b);
    //
    float f1 = 1.1, f2 = 2.2;
    cout << f1 << " + " << f2 << " = "
        << Sum(f1, f2) << endl;

    //Sum(1, 2, 3); // void Sum(int, int, int);

    cout << Sum(a, (int)f1) << endl; // int + float ==> int
    cout << Sum(f1, float(a)) << endl; // float + int ==> float

    string s1 = "Hello ", s2 = "World!";
    cout << Sum(s1, s2) << endl;

    cin.get(); cin.get();
}
/*
// перегруженная ф-ция сложения двух целых чисел
int Sum(int a, int b)
{
  return a + b;
}

// перегруженная ф-ция сложения трех целых чисел
void Sum(int v1, int v2, int v3)
{
  cout << v1 << "+" << v2 << "+" << v3
    << " = " << v1 + v2 + v3 << endl;
}

// перегруженная ф-ция сложения двух чисел типа float
float Sum(float a, float b)
{
  return a + b;
}

// перегруженная ф-ция сложения двух чисел типа long
long Sum(long a, long b)
{
  return a + b;
}
*/

// шаблон ф-ции Sum()
template <typename MyType>
MyType Sum(MyType a, MyType b)
{
    MyType res = a + b; // промежуточная переменная типа MyType
    return res;
    // return a + b;
}

/*
// Sum(a, b) ==> Sum(int, int) ==> [MyType = int]
int Sum(int a, int b)
{
  int res = a + b; // промежуточная переменная типа MyType
  return res;
  // return a + b;
}

// Sum(f1, f2) ==> Sum(float, float) ==> [MyType = float]
float Sum(float a, float b)
{
  float res = a + b; // промежуточная переменная типа MyType
  return res;
  // return a + b;
}
*/


#include <iostream>
#include <iomanip>
#include <string> // class string
#include <time.h>
using namespace std;

/*
Перегрузка функций. Шаблоны функций - только C++, в языке C - этих механизмов нет

1) Механизмы полиморфизма - только C++, в языке C - этих механизмов нет:
 - Перегрузка функций
 - Шаблоны функций
2) Прототипы функций.
3) Параметры по умолчанию.

Реализовать перегруженные варианты функции для заданий ниже.
Реализовать шаблоны функции для заданий ниже.

15. Написать функцию, которая принимает одномерный
массив целых чисел и возвращает значения максимального
числа в этом массиве.

20. Напишите функцию, которая определяет количество
элементов передаваемого массива, которые меньше
определенного числа, это число тоже передается
в функцию.
Реализовать перегрузки для различных типов массивов.

27. Напишите ряд функций функций для работы с массивом:
- инициализация массива с консоли или случайными
 значениями в заданном диапазоне;
- вывод элементов массива на экран;
- суммирование элементов двух массивов в третий массив;
- удаление из массива элементов равных заданному;
- удаление из массива элемента по индексу;
a) Реализовать перегрузки для целых и вещественных чисел.
b) Реализовать функции в виде шаблонов.
*/
// глобальные прототипы ф-ций - декларация ф-ций

void FillArr(int arr[], int size, int min = 1, int max = 10);
void PrintArr(int* arr, int size);
int MaxArr(int* arr, int size);
int MinScore(int* arr, int size, int min);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    int res;
    FillArr(arr, size);
    PrintArr(arr, size);
    res = MaxArr(arr, size);
    cout << "Max = " << res << endl;

    FillArr(arr, size, 100, 200);
    PrintArr(arr, size);
    cout << "Max = " << MaxArr(arr, size) << endl;

    cout << "Enter minimum number: ";
    int min;
    cin >> min;
    //MinScore(arr, size, min);
    cout << "Count = " << MinScore(arr, size, min) << endl;

    cin.get(); cin.get();
}

void FillArr(int arr[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void PrintArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int MaxArr(int* arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int MinScore(int* arr, int size, int min)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            count++;
        }
    }
    return count;
}

#include <iostream>
#include <iomanip>
#include <string> // class string
#include <time.h>
using namespace std;

/*
Перегрузка функций. Шаблоны функций - только C++, в языке C - этих механизмов нет

1) Механизмы полиморфизма - только C++, в языке C - этих механизмов нет:
 - Перегрузка функций
 - Шаблоны функций
2) Прототипы функций.
3) Параметры по умолчанию.

Реализовать перегруженные варианты функции для заданий ниже.
Реализовать шаблоны функции для заданий ниже.

15. Написать функцию, которая принимает одномерный
массив целых чисел и возвращает значения максимального
числа в этом массиве.

20. Напишите функцию, которая определяет количество
элементов передаваемого массива, которые меньше
определенного числа, это число тоже передается
в функцию.
Реализовать перегрузки для различных типов массивов.

27. Напишите ряд функций функций для работы с массивом:
- инициализация массива с консоли или случайными
 значениями в заданном диапазоне;
- вывод элементов массива на экран;
- суммирование элементов двух массивов в третий массив;
- удаление из массива элементов равных заданному;
- удаление из массива элемента по индексу;
a) Реализовать перегрузки для целых и вещественных чисел.
b) Реализовать функции в виде шаблонов.
*/
// глобальные прототипы ф-ций - декларация ф-ций

void FillArr(int arr[], int size, int min = 1, int max = 10);
void PrintArr(int* arr, int size);
int MaxArr(int* arr, int size);
//int MinScore(int* arr, int size, int min);

void PrintArr(float* arr, int size);
float MaxArr(float* arr, int size);

template<typename T, typename TSize = int>
TSize MinScore(T* arr, TSize size, T min);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    int res;
    FillArr(arr, size);
    PrintArr(arr, size);
    res = MaxArr(arr, size);
    cout << "Max = " << res << endl;

    // для float
    float* arr2 = new float[size];
    FillArr(arr2, size, 100, 200);
    PrintArr(arr2, size);
    cout << "Max = " << MaxArr(arr2, size) << endl;

    cout << "Enter minimum number: ";
    float min;
    cin >> min;
    //MinScore(arr, size, min);
    cout << "Count = " << MinScore(arr2, size, min) << endl;

    cin.get(); cin.get();
}

void FillArr(int arr[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void PrintArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int MaxArr(int* arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
template<typename T, typename TSize = int>
TSize MinScore(T* arr, TSize size, T min)
{
    TSize count = 0;
    for (TSize i = 0; i < size; i++) {
        if (arr[i] < min) {
            count++;
        }
    }
    return count;
}

// float
void PrintArr(float* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

float MaxArr(float* arr, int size)
{
    float max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
