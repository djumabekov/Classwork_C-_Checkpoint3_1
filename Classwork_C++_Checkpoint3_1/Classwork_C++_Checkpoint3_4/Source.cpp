#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
���������

9) ������� ������ �� 10 ����� �����. ��������� ������ ��������� �������.
��������� ���������� �� ������ ����� �����, ���������
����� ��������� ������� � ���������� �������� 7.
(����� ������������ ������ ������ ������� �
����� ���������)

11) ��������� ���������, ��������� � ����� �����������
������� ������ ������������� �������.

7) �������� ���������, ������� ��������� ����� ������
��������� �������, ��������� ��� ��������� �� ������
����� �����.
������ ��������� ��������� � ������ �������, ������ - � �����.

8) �������� ���������, ������� ��������� ����� ���������
������� � ������� ��������, ��������� ��� ���������
�� ������ ����� �����.
������ ��������� ��������� � ������ �������, ������ - � �����.
*/
int FuncSum(int* arr, int size, int var_num = 7);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << "������� ������ �������:";
    cin >> size;
    int* arr = new int[size];
    //cout << "������� ����� ��������� :";
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
    cout << "������� ����� ��������� :";
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
    // 2 �������
    sum = 0;
    while (size--) { // size - ���-�� (�����)
      /*
      if (*parr++ % 7 == 0) {
        sum +=parr [-1];
        //����������� �� ���� ��� �����
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
���������

9) ������� ������ �� 10 ����� �����. ��������� ������ ��������� �������.
��������� ���������� �� ������ ����� �����, ���������
����� ��������� ������� � ���������� �������� 7.
(����� ������������ ������ ������ ������� �
����� ���������)

11) ��������� ���������, ��������� � ����� �����������
������� ������ ������������� �������.

7) �������� ���������, ������� ��������� ����� ������
��������� �������, ��������� ��� ��������� �� ������
����� �����.
������ ��������� ��������� � ������ �������, ������ - � �����.

8) �������� ���������, ������� ��������� ����� ���������
������� � ������� ��������, ��������� ��� ���������
�� ������ ����� �����.
������ ��������� ��������� � ������ �������, ������ - � �����.
*/

int FuncSum(int* arr, int size, int var_num = 7);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << "������� ������ �������:";
    cin >> size;
    int* arr = new int[size];
    //cout << "������� ����� ��������� :";
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
    cout << "������� ����� ��������� :";
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
    // 2 �������
    sum = 0;
    while (size--) { // size - ���-�� (�����)
      /*
      if (*parr++ % 7 == 0) {
        sum +=parr [-1];
        //����������� �� ���� ��� �����
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
���������
7) �������� ���������, ������� ��������� ����� ������
��������� �������, ��������� ��� ��������� �� ������
����� �����.
������ ��������� ��������� � ������ �������,
������ - � �����.

8) �������� ���������, ������� ��������� ����� ���������
������� � ������� ��������, ��������� ��� ���������
�� ������ ����� �����.
������ ��������� ��������� � ������ �������,
������ - � �����.
*/

int FuncSum(int* arr, int size);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << " ������� ������ �������:";
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
���������
8) �������� ���������, ������� ��������� ����� ���������
������� � ������� ��������, ��������� ��� ���������
�� ������ ����� �����.
������ ��������� ��������� � ������ �������,
������ - � �����.
*/

int FuncSum8(int* arr, int size);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size;
    cout << " ������� ������ �������:";
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
* ���������. ����������� ������������ �������
1) �������� ���������, ������� ������� ����������
������ � ��������� ��� �� ���������� ��������:
������������ ������ ����� (��������, 3) ������
������� ������� ��������� �������� ����� �����,
����������� ������� ������� ��������� ��������
����� ����� ����������� �� 2 (�.�. 6 ��� ������
�������), ������ ������� ������� ���������� �������
���������� �� 2 (�.�. 6*2=12 ��� ������ �������).
��������� ������ ������� �� �����.
*/
void PrintMas2D(int** mas, int row, int col);
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int row, col;
    cout << "������� ������� ������� (row,col): ";
    cin >> row >> col;
    // ��� ���������� ���. ������� ����� ��������� �� ���������
    int** mas;
    // ������ ��������� �� ������ ���������� �������
    mas = new int* [row];
    // ���� �������� ����� ����. ���. �������
    for (int i = 0; i < row; i++) {
        mas[i] = new int[col]; // �������� i-�� ������
    }
    int a;
    cout << "������� ������ �����: ";
    cin >> a;
    // ���� ���������� ����. ������������� �������
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mas[i][j] = a;
            a *= 2; // ������ ����. ������� � ��� ���� ������ �����������
            //a++;// ������ ����. ������� �� 1 ������ �����������
        }
    }
    // �-��� ������ ����. ���. �������
    PrintMas2D(mas, row, col);

    // �������� ����. ���. �������
    // 1) �������� ����� � �����
    for (int i = 0; i < row; i++) {
        delete[]mas[i]; // �������� i-�� ������
    }
    // 2) �������� ������� ����������
    delete[]mas; // �������� ������� ����������

    cin.get(); cin.get();
}

void PrintMas2D(int** mas, int row, int col) {
    // ������� ���� ������ ����. �������
    for (int i = 0; i < row; i++) {
        // ���� ������ ������
        for (int j = 0; j < col; j++) {
            cout << setw(5) << mas[i][j] << " ";
        }
        cout << endl;
    }
}



