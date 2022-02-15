#include <iostream>
#include <iomanip>
#include <string> // class string
#include <time.h>
using namespace std;

/*
���������� �������. ������� ������� - ������ C++, � ����� C - ���� ���������� ���

1) ��������� ������������ - ������ C++, � ����� C - ���� ���������� ���:
 - ���������� �������
 - ������� �������
2) ��������� �������.
3) ��������� �� ���������.

����������� ������������� �������� ������� ��� ������� ����.
����������� ������� ������� ��� ������� ����.

15. �������� �������, ������� ��������� ����������
������ ����� ����� � ���������� �������� �������������
����� � ���� �������.

20. �������� �������, ������� ���������� ����������
��������� ������������� �������, ������� ������
������������� �����, ��� ����� ���� ����������
� �������.
����������� ���������� ��� ��������� ����� ��������.

27. �������� ��� ������� ������� ��� ������ � ��������:
- ������������� ������� � ������� ��� ����������
 ���������� � �������� ���������;
- ����� ��������� ������� �� �����;
- ������������ ��������� ���� �������� � ������ ������;
- �������� �� ������� ��������� ������ ���������;
- �������� �� ������� �������� �� �������;
a) ����������� ���������� ��� ����� � ������������ �����.
b) ����������� ������� � ���� ��������.
*/
// ���������� ��������� �-��� - ���������� �-���

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
    // ��� ������� ���� int
    int size;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    int res;
    FillArr(arr, size);
    PrintArr(arr, size);
    res = MaxArr(arr, size);
    cout << "Max = " << res << endl;

    // �������� �������� ������� �� �������
    int index;
    cout << "������� ������ ��� ��������: ";
    cin >> index; // 0 .. size-1
    DeleteFromIndex(arr, size, index);
    PrintArr(arr, size);
    cout << endl;
    int val;
    cout << "����� �������� �������: ";
    cin >> val;
    DeleteFromVal(arr, size, val);
    PrintArr(arr, size);
    cout << endl;

    // ��� ������� ���� float
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
    FillArr(str, size, '�', '�');
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

// - �������� �� ������� �������� �� �������;
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
    delete[]mas; // �������� ������� �������
    // ���������� ���������� � ������� �������
    mas = newMas;
    size--;
}

// - �������� �� ������� ��������� ������ ���������;
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

// �-��� ��� ������� � ������ ������ �������� val
//  �� ������� index
void AddMasValue(int*& mas, int& size, int val, int index)
{
    int* newMas = new int[size + 1];
    // ����������� ������ ����� �� [index]
    for (int i = 0; i < index; i++) {
        newMas[i] = mas[i];
    }
    newMas[index] = val; // ������� ������ ��������
    // ������������� ��������� ������� mas[] � newMas[]
    for (int i = index; i < size; i++) {
        newMas[i + 1] = mas[i];
    }
    delete[]mas; // �������� ������� �������
    // ���������� ���. � ������� �������
    mas = newMas;
    size++;
}
