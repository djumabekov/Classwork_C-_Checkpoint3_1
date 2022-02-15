#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
Указатели

9) Создать массив из 10 целых чисел. Заполнить массив случайным образом.
Пользуясь указателем на массив целых чисел, посчитать
сумму элементов массива с элементами кратными 7.
(Пусть пользователь задает размер массива и
число кратности)

11) Используя указатели, перенести в хвост одномерного
массива первый отрицательный элемент.

7) Написать программу, которая вычисляет сумму четных
элементов массива, используя ДВА указателя на массив
целых чисел.
Первый указатель двигается с начала массива, второй - с конца.

8) Написать программу, которая вычисляет сумму элементов
массива с четными номерами, используя ДВА указателя
на массив целых чисел.
Первый указатель двигается с начала массива, второй - с конца.
*/
int FuncSum(int* arr, int size, int var_num = 7);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << "Введите размер массива:";
    cin >> size;
    int* arr = new int[size];
    //cout << "Введите число кратности :";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1;
    }
    int* p = arr;
    //int* p = &arr[0];
    for (int i = 0; i < size; i++) {
        //cout << p[i] << " ";
        //cout << *(p + i) << " ";
        cout << *p << " ";
        p++;
    }
    cout << endl;
    cout << "sum = " << FuncSum(arr, size) << endl;
    cout << "Введите число кратности :";
    int temp = 0;
    cin >> temp;
    cout << "sum = " << FuncSum(arr, size, temp) << endl;
    cin.get(); cin.get();
}
int FuncSum(int* arr, int size, int var_num)
{
    int sum = 0;
    int* parr = arr;
    for (int i = 0; i < size; i++) {
        /*if (arr[i] % var_num == 0) {
          sum += arr[i];
        }*/
        if (*parr % var_num == 0) {
            sum += *parr;
        }
        parr++;
    }
    return sum;
    // 2 вариант
    sum = 0;
    while (size--) { // size - кол-во (штуки)
      /*
      if (*parr++ % 7 == 0) {
        sum +=parr [-1];
        //индексируем на один шаг назад
      }*/
        if (*parr % var_num == 0) {
            sum += *parr;
        }
        parr++;
    }
    return sum;
}


#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
Указатели

9) Создать массив из 10 целых чисел. Заполнить массив случайным образом.
Пользуясь указателем на массив целых чисел, посчитать
сумму элементов массива с элементами кратными 7.
(Пусть пользователь задает размер массива и
число кратности)

11) Используя указатели, перенести в хвост одномерного
массива первый отрицательный элемент.

7) Написать программу, которая вычисляет сумму четных
элементов массива, используя ДВА указателя на массив
целых чисел.
Первый указатель двигается с начала массива, второй - с конца.

8) Написать программу, которая вычисляет сумму элементов
массива с четными номерами, используя ДВА указателя
на массив целых чисел.
Первый указатель двигается с начала массива, второй - с конца.
*/

int FuncSum(int* arr, int size, int var_num = 7);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << "Введите размер массива:";
    cin >> size;
    int* arr = new int[size];
    //cout << "Введите число кратности :";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1;
    }
    int* p = arr;
    //int* p = &arr[0];
    for (int i = 0; i < size; i++) {
        //cout << p[i] << " ";
        //cout << *(i + p) << " ";
        //cout << i[p] << " "; // *(i + p)
        cout << *p << " ";
        p++;
    }
    cout << endl;
    //cout << 0[arr] << endl;
    cout << "sum = " << FuncSum(arr, size) << endl;
    cout << "Введите число кратности :";
    int temp = 0;
    cin >> temp;
    cout << "sum = " << FuncSum(arr, size, temp) << endl;
    cin.get(); cin.get();
}
int FuncSum(int* arr, int size, int var_num)
{
    int sum = 0;
    int* parr = arr;
    for (int i = 0; i < size; i++) {
        /*if (arr[i] % var_num == 0) {
          sum += arr[i];
        }*/
        if (*parr % var_num == 0) {
            sum += *parr;
        }
        parr++;
    }
    return sum;
    // 2 вариант
    sum = 0;
    while (size--) { // size - кол-во (штуки)
      /*
      if (*parr++ % 7 == 0) {
        sum +=parr [-1];
        //индексируем на один шаг назад
      }*/
        if (*parr % var_num == 0) {
            sum += *parr;
        }
        parr++;
    }
    return sum;
}

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
Указатели
7) Написать программу, которая вычисляет сумму четных
элементов массива, используя ДВА указателя на массив
целых чисел.
Первый указатель двигается с начала массива,
второй - с конца.

8) Написать программу, которая вычисляет сумму элементов
массива с четными номерами, используя ДВА указателя
на массив целых чисел.
Первый указатель двигается с начала массива,
второй - с конца.
*/

int FuncSum(int* arr, int size);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << " Введите размер массива:";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "sum = " << FuncSum(arr, size) << endl;


    cin.get(); cin.get();
}
int FuncSum(int* arr, int size)
{
    int sum = 0;
    int* pleftarr = &arr[0];
    // int *pleftarr = arr;
    int* prightarr = &arr[size - 1];
    // int *prightarr = arr + (size - 1);
    for (int i = 0; i < size / 2; i++) {
        if (*pleftarr % 2 == 0) {
            sum += *pleftarr;
        }
        if (*prightarr % 2 == 0) {
            sum += *prightarr;
        }
        pleftarr++;
        prightarr--;
    }

    //if (size % 2 != 0) 
    if (pleftarr == prightarr) {
        if (*pleftarr % 2 == 0) {
            sum += *pleftarr;
        }
    }
    return sum;
}

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
Указатели
8) Написать программу, которая вычисляет сумму элементов
массива с четными номерами, используя ДВА указателя
на массив целых чисел.
Первый указатель двигается с начала массива,
второй - с конца.
*/

int FuncSum8(int* arr, int size);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << " Введите размер массива:";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "sum = " << FuncSum8(arr, size) << endl;

    cin.get(); cin.get();
}

int FuncSum8(int* arr, int size)
{
    int* p1, * p2;
    int sum = 0;
    p1 = &arr[0];
    p2 = &arr[size - 1];
    if (size % 2 == 0) {
        p2--;
    }
    while (p1 < p2) {
        sum += *p1 + *p2;
        p1 += 2;
        p2 -= 2;
    }
    if (p1 == p2) {
        sum += *p1;
    }
    return sum;
}

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
* Указатели. Многомерные динамические массивы
1) Напишите программу, которая создает двухмерный
массив и заполняет его по следующему принципу:
пользователь вводит число (например, 3) первый
элемент массива принимает значение этого числа,
последующий элемент массива принимает значение
этого числа умноженного на 2 (т.е. 6 для нашего
примера), третий элемент массива предыдущий элемент
умноженный на 2 (т.е. 6*2=12 для нашего примера).
Созданный массив вывести на экран.
*/
void PrintMas2D(int** mas, int row, int col);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int row, col;
    cout << "Введите размеры массива (row,col): ";
    cin >> row >> col;
    // для двумерного дин. массива нужен указатель на указатель
    int** mas;
    // массив укзателей на строки двумерного массива
    mas = new int* [row];
    // цикл создания строк двум. дин. массива
    for (int i = 0; i < row; i++) {
        mas[i] = new int[col]; // создание i-ой строки
    }
    int a;
    cout << "Введите первое число: ";
    cin >> a;
    // цикл заполнения двум. динамического массива
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mas[i][j] = a;
            a *= 2; // каждый след. элемент в два раза больше предыдущего
            //a++;// каждый след. элемент на 1 больше предыдущего
        }
    }
    // ф-ция печати двум. дин. массива
    PrintMas2D(mas, row, col);

    // удаление двум. дин. массива
    // 1) удаление строк в цикле
    for (int i = 0; i < row; i++) {
        delete[]mas[i]; // удаление i-ой строки
    }
    // 2) удаление массива указателей
    delete[]mas; // удаление массива указателей

    cin.get(); cin.get();
}

void PrintMas2D(int** mas, int row, int col) {
    // двойной цикл обхода двум. массива
    for (int i = 0; i < row; i++) {
        // цикл печати строки
        for (int j = 0; j < col; j++) {
            cout << setw(5) << mas[i][j] << " ";
        }
        cout << endl;
    }
}



