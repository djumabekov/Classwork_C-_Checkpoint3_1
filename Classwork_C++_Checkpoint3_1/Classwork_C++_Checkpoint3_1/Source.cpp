#include <iostream>
#include <iomanip>
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

17. �������� ������������� ������� sum,
  ��������� ����� ���� ������������ ���� ���� ����� �����.
18. �������� ������������� �������, ������������ ������������ �������� �� ����, ���� � ������� ����� ��������.
15. �������� �������, ������� ��������� ���������� ������ ����� ����� � ���������� �������� ������������� ����� � ���� �������.
20. �������� �������, ������� ���������� ���������� ��������� ������������� �������, ������� ������ ������������� �����, ��� ����� ���� ���������� � �������.
����������� ���������� ��� ��������� ����� ��������.
27. �������� ��� ������� ������� ��� ������ � ��������:
- ������������� ������� � ������� ��� ���������� ���������� � �������� ���������;
- ����� ��������� ������� �� �����;
- ������������ ��������� ���� �������� � ������ ������;
- �������� �� ������� ��������� ������ ���������;
- �������� �� ������� �������� �� �������;
a) ����������� ���������� ��� ����� � ������������ �����.
b) ����������� ������� � ���� ��������.
*/

// ���������� ��������� �-��� - ���������� �-���
int   Sum(int a, int b); // �������� �-��� Sum(int, int)
float Sum(float, float); // �������� �-��� Sum(float, float)
void  Sum(int v1, int v2, int v3); // �������� �-��� Sum(int, int, int)

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // ����� �-��� Sum() � �������������� �����������
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

// ������������� �-��� �������� ���� ����� �����
int Sum(int a, int b)
{
    return a + b;
}

// ������������� �-��� �������� ���� ����� �����
void Sum(int v1, int v2, int v3)
{
    cout << v1 << "+" << v2 << "+" << v3
        << " = " << v1 + v2 + v3 << endl;
}

// ������������� �-��� �������� ���� ����� ���� float
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
���������� �������. ������� ������� - ������ C++, � ����� C - ���� ���������� ���

1) ��������� ������������ - ������ C++, � ����� C - ���� ���������� ���:
 - ���������� �������
 - ������� �������
2) ��������� �������.
3) ��������� �� ���������.

����������� ������������� �������� ������� ��� ������� ����.
����������� ������� ������� ��� ������� ����.

17. �������� ������������� ������� sum,
  ��������� ����� ���� ������������ ���� ���� ����� �����.
18. �������� ������������� �������, ������������ ������������ �������� �� ����, ���� � ������� ����� ��������.
15. �������� �������, ������� ��������� ���������� ������ ����� ����� � ���������� �������� ������������� ����� � ���� �������.
20. �������� �������, ������� ���������� ���������� ��������� ������������� �������, ������� ������ ������������� �����, ��� ����� ���� ���������� � �������.
����������� ���������� ��� ��������� ����� ��������.
27. �������� ��� ������� ������� ��� ������ � ��������:
- ������������� ������� � ������� ��� ���������� ���������� � �������� ���������;
- ����� ��������� ������� �� �����;
- ������������ ��������� ���� �������� � ������ ������;
- �������� �� ������� ��������� ������ ���������;
- �������� �� ������� �������� �� �������;
a) ����������� ���������� ��� ����� � ������������ �����.
b) ����������� ������� � ���� ��������.
*/

// ���������� ��������� �-��� - ���������� �-���
//int   Sum(int a, int b); // �������� �-��� Sum(int, int)
//float Sum(float, float); // �������� �-��� Sum(float, float)
//void  Sum(int v1, int v2, int v3); // �������� �-��� Sum(int, int, int)

template <typename MyType>
MyType Sum(MyType a, MyType b);

int main() {

    setlocale(LC_ALL, "Rus");
    srand(time(0));

    // ����� �-��� Sum() � �������������� �����������
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
// ������������� �-��� �������� ���� ����� �����
int Sum(int a, int b)
{
  return a + b;
}

// ������������� �-��� �������� ���� ����� �����
void Sum(int v1, int v2, int v3)
{
  cout << v1 << "+" << v2 << "+" << v3
    << " = " << v1 + v2 + v3 << endl;
}

// ������������� �-��� �������� ���� ����� ���� float
float Sum(float a, float b)
{
  return a + b;
}

// ������������� �-��� �������� ���� ����� ���� long
long Sum(long a, long b)
{
  return a + b;
}
*/

// ������ �-��� Sum()
template <typename MyType>
MyType Sum(MyType a, MyType b)
{
    MyType res = a + b; // ������������� ���������� ���� MyType
    return res;
    // return a + b;
}

/*
// Sum(a, b) ==> Sum(int, int) ==> [MyType = int]
int Sum(int a, int b)
{
  int res = a + b; // ������������� ���������� ���� MyType
  return res;
  // return a + b;
}

// Sum(f1, f2) ==> Sum(float, float) ==> [MyType = float]
float Sum(float a, float b)
{
  float res = a + b; // ������������� ���������� ���� MyType
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

    // ��� float
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
