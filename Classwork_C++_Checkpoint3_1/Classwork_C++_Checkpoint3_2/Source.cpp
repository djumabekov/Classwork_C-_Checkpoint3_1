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

template<typename T>
void FillArr(T arr[], int size, T min = 1, T max = 10);

void FillArr(float* arr, int size, float min, float max);

template<typename T>
void PrintArr(T* arr, int size);

template<typename T>
T MaxArr(T* arr, int size);

template<typename T, typename TSize = int>
TSize MinScore(T* arr, TSize size, T min);

//void DeleteFromIndex(int*& mas, int& size, int index);
template <typename T>
void DeleteFromIndex(T*& mas, int& size, int index);

template <class T>
void DeleteFromVal(T*& mas, int& size, T value);


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    // для массива типа int
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    int res;
    FillArr(arr, size);
    PrintArr(arr, size);
    res = MaxArr(arr, size);
    cout << "Max = " << res << endl;

    // удаление элеиента массива по индексу
    int index;
    cout << "Укажите индекс для удаления: ";
    cin >> index; // 0 .. size-1
    DeleteFromIndex(arr, size, index);
    PrintArr(arr, size);
    cout << endl;
    int val;
    cout << "Какое значение удалить: ";
    cin >> val;
    DeleteFromVal(arr, size, val);
    PrintArr(arr, size);
    cout << endl;

    // для массива типа float
    float* arr2 = new float[size];
    FillArr(arr2, size, 100, 200); // ---------
    PrintArr(arr2, size);
    cout << "Max = " << MaxArr(arr2, size) << endl;

    cout << "Enter minimum number: ";
    float min;
    cin >> min;
    //MinScore(arr, size, min);
    cout << "Count = " << MinScore(arr2, size, min) << endl;

    //for char

    char* str = new char[size];
    FillArr(str, size, 'А', 'Я');
    PrintArr(str, size);

    cin.get(); cin.get();
}

template<typename T>
void FillArr(T arr[], int size, T min, T max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void FillArr(float* arr, int size, float min, float max)
{
    int _min = min * 100, _max = max * 100;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (_max - _min + 1) + _min;
        arr[i] /= 100;
    }
}

template<typename T>
void PrintArr(T* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
T MaxArr(T* arr, int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
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

// - удаление из массива элемента по индексу;
template <typename T>
void DeleteFromIndex(T*& mas, int& size, int index)
{
    T* newMas = new T[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newMas[j] = mas[i];
            j++;
        }
    }
    delete[]mas; // удаление старого массива
    // обновление информации о рабочем массиве
    mas = newMas;
    size--;
}

// - удаление из массива элементов равных заданному;
//template <typename T>
template <class T>
void DeleteFromVal(T*& mas, int& size, T value)
{
    /*
    for (int i = 0; i < size; i++) {
      if (mas[i] == value) {
        DeleteFromIndex(mas, size, i);
        i--;
      }
    }
    */
    for (int i = size - 1; i >= 0; i--) {
        if (mas[i] == value) {
            DeleteFromIndex(mas, size, i);
        }
    }
}

// ф-ция для вставки в массив нового значения val
//  по индексу index
void AddMasValue(int*& mas, int& size, int val, int index)
{
    int* newMas = new int[size + 1];
    // копирование первой части до [index]
    for (int i = 0; i < index; i++) {
        newMas[i] = mas[i];
    }
    newMas[index] = val; // вставка нового элемента
    // докопирование элементов массива mas[] в newMas[]
    for (int i = index; i < size; i++) {
        newMas[i + 1] = mas[i];
    }
    delete[]mas; // удаление старого массива
    // обновление инф. о рабочем массиве
    mas = newMas;
    size++;
}
