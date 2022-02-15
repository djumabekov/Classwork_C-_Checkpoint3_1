#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
#include "Win10.h"
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
Menu()

6. ��� ��������� ����.
���������� ���������� ��� ������ � ������ ����.
������� ����� �� ������ ����� ������ ���������
� �������� ����� � �������� �����.

18. ��� ��������� ����.
����������� ���, ��������� ���� ������.
��������� �������� � ������ ����.
���� ������ - ���� �� ���������� ������.
��� ���������� ������ ������ ���������� ������,
��������� �� ���� � �������� �� ������������� ����� �������.
������:
���������� � �������������� ����� : 3
������������ �����: "����� �� ��� ���� ������ ����������� �����, �� ����� ���"
����������� �����:  "����� �� ��� ���� ����� ����������� �����, �� ����� ���"
*/
int* Init_Arr(int& size);
bool Save_to_file(string filename, int* arr, int size,
    bool isapp = false);
int* ReadFromFile(string filename, int& size, int number);

int Menu(string Items[], int Size, // ������ ������� ����
    int Row, int Col, // �������� ���������� ����
    int Select = 0);

string Menu_Items[] = {
"Set File Name",
"Init Array",
"Save to File rewrite" ,
"Save to File append",
"Read from File" ,
"Exit",
};
int cnt_Menu_Items = sizeof(Menu_Items) / sizeof(Menu_Items[0]);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    int select = 0;
    int* arr = nullptr, size = 0;
    string filename;
    bool Exit = false;
    while (!Exit)
    {
        system("cls");
        select = Menu(Menu_Items, cnt_Menu_Items, 5, 5, select);
        system("cls");
        switch (select)
        {
        case 0:cout << "Enter File Name"; getline(cin, filename);
            break;
        case 1: /*cout << "Enter size array "; cin >> size;
          cin.ignore();*/
            delete[]arr;
            arr = Init_Arr(size);
            system("pause");
            break;
        case 2:
            if (Save_to_file(filename, arr, size)) {
                cout << "Ok" << endl;
            }
            else {
                cout << "Error " << endl;
            }
            system("pause");
            break;
        case 3:
            if (Save_to_file(filename, arr, size, true)) {
                cout << "Ok" << endl;
            }
            else {
                cout << "Error " << endl;
            }
            system("pause");
            break;
        case 4:
        {
            int size2 = 0;
            cout << "������� ����� ������� : ";
            int number;
            cin >> number; cin.ignore();
            int* arr2 = ReadFromFile(filename, size2, number);
            if (arr2 == nullptr) {
                cout << "Error read" << endl;
                system("pause");
                break;
            }
            cout << size2 << " : ";
            for (int i = 0; i < size2; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;
            system("pause");
            delete[]arr2;
        }
        break;
        case 5: case-1: Exit = true; break;
        }
    }

    cin.get();
}

int* Init_Arr(int& size)
{
    cout << "������� ������ ������� :";
    cin >> size;
    cin.ignore();
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = RAND(1, 10);
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr;
}
bool Save_to_file(string filename, int* arr, int size, bool isapp)
{
    //ofstream file(filename);
    ofstream file;
    if (isapp == true) {
        file.open(filename, ios::app);
    }
    else {
        file.open(filename);
    }
    if (!file.is_open()) {
        cout << "Error , cant create file " << endl;
        return false;
    }
    file << size << "\t";
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file << endl;
    return true;
}
/*
int* ReadFromFile(string filename,int &size)
{

  ifstream ifile;       // ������ ����
  ifile.open(filename);
  if (!ifile.is_open())
  {
    cout << "error file is not found" << endl;
    return nullptr;
  }
  size = 0;
  while (!ifile.eof())
  {
    int temp;
    ifile >> temp;
    size++;
  }
  ifile.clear();
  ifile.seekg(0, ios::beg); // seekg - �������� �� ������  ������ �����
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    ifile >> arr[i];
  }
  return arr;
}
*/

int* ReadFromFile(string filename, int& size, int number)
{ // ������ �����
    ifstream ifile;       // ������ ����
    ifile.open(filename);
    if (!ifile.is_open()) {
        cout << "error file is not found" << endl;
        return nullptr;
    }
    string buf;
    for (int i = 0; i < number; i++) {
        getline(ifile, buf);
    }
    if (ifile.eof()) {
        cout << "Error EOF" << endl;
        return nullptr;
    }
    size = 0;
    ifile >> size;
    if (size == 0) {
        cout << "Error eof" << endl;
        return nullptr;
    }
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        ifile >> arr[i];
    }
    return arr;
}


#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
*/

// ���������� ��������� Point
struct Point {
    string Name;  // �������� �����
    int x, y;     // ���������� �����
    // ����� ������ � ������� � ���������� ����� ��������� ���� Point
    void Input() {
        cout << "������� �������� �����: ";
        getline(cin, Name);
        cout << "������� ���������� x,y: ";
        cin >> x >> y; cin.ignore();
    }
    // ����� ������ �� ����� ����������� ����������
    //  ���� Point � ������� A(1;2)
    void Print() {
        cout << Name << "(" << x << ";" << y << ")\n";
    }
    void SaveToFile(string filename) {
        ofstream file;
        file.open(filename);
        if (file.is_open() != true) {
            cout << "Error create of file!" << endl;
            return;
        }
        file << x << " " << y << " " << Name << endl;
    }
    void ReadFromFile(string filename)
    {
        ifstream file(filename);
        if (file.is_open() != true) {
            cout << "Error not found!" << endl;
            return;
        }
        file >> x >> y; file.ignore();
        getline(file, Name);
    }
};

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    Point a;
    Point b = { "����� B", 1, 2 };

    a.Input();
    b.Input();
    a.Print();
    b.Print();
    a.SaveToFile("pointA.txt");
    b.ReadFromFile("pointA.txt");
    a.Print();
    b.Print();
    cin.get();
}


#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
#include "Win10.h"
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
Menu()

6. ��� ��������� ����.
���������� ���������� ��� ������ � ������ ����.
������� ����� �� ������ ����� ������ ���������
� �������� ����� � �������� �����.

18. ��� ��������� ����.
����������� ���, ��������� ���� ������.
��������� �������� � ������ ����.
���� ������ - ���� �� ���������� ������.
��� ���������� ������ ������ ���������� ������,
��������� �� ���� � �������� �� ������������� ����� �������.
������:
���������� � �������������� ����� : 3
������������ �����: "����� �� ��� ���� ������ ����������� �����, �� ����� ���"
����������� �����:  "����� �� ��� ���� ����� ����������� �����, �� ����� ���"
*/
int* Init_Arr(int& size);
bool Save_to_file(string filename, int* arr, int size,
    bool isapp = false);
int* ReadFromFile(string filename, int& size, int number);

int Menu(string Items[], int Size, // ������ ������� ����
    int Row, int Col, // �������� ���������� ����
    int Select = 0);

string Menu_Items[] = {
"Set File Name",
"Init Array",
"Save to File rewrite" ,
"Save to File append",
"Read from File" ,
"Exit",
};
int cnt_Menu_Items = sizeof(Menu_Items) / sizeof(Menu_Items[0]);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    int select = 0;
    int* arr = nullptr, size = 0;
    string filename;
    bool Exit = false;
    while (!Exit)
    {
        system("cls");
        select = Menu(Menu_Items, cnt_Menu_Items, 5, 5, select);
        system("cls");
        switch (select)
        {
        case 0:cout << "Enter File Name"; getline(cin, filename);
            break;
        case 1: /*cout << "Enter size array "; cin >> size;
          cin.ignore();*/
            delete[]arr;
            arr = Init_Arr(size);
            system("pause");
            break;
        case 2:
            if (Save_to_file(filename, arr, size)) {
                cout << "Ok" << endl;
            }
            else {
                cout << "Error " << endl;
            }
            system("pause");
            break;
        case 3:
            if (Save_to_file(filename, arr, size, true)) {
                cout << "Ok" << endl;
            }
            else {
                cout << "Error " << endl;
            }
            system("pause");
            break;
        case 4:
        {
            int size2 = 0;
            cout << "������� ����� ������� : ";
            int number;
            cin >> number; cin.ignore();
            int* arr2 = ReadFromFile(filename, size2, number);
            if (arr2 == nullptr) {
                cout << "Error read" << endl;
                system("pause");
                break;
            }
            cout << size2 << " : ";
            for (int i = 0; i < size2; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;
            system("pause");
            delete[]arr2;
        }
        break;
        case 5: case-1: Exit = true; break;
        }
    }

    cin.get();
}

int* Init_Arr(int& size)
{
    cout << "������� ������ ������� :";
    cin >> size;
    cin.ignore();
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = RAND(1, 10);
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr;
}
bool Save_to_file(string filename, int* arr, int size, bool isapp)
{
    //ofstream file(filename);
    ofstream file;
    if (isapp == true) {
        file.open(filename, ios::app);
    }
    else {
        file.open(filename);
    }
    if (!file.is_open()) {
        cout << "Error , cant create file " << endl;
        return false;
    }
    file << size << "\t";
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file << endl;
    return true;
}
/*
int* ReadFromFile(string filename,int &size)
{

  ifstream ifile;       // ������ ����
  ifile.open(filename);
  if (!ifile.is_open())
  {
    cout << "error file is not found" << endl;
    return nullptr;
  }
  size = 0;
  while (!ifile.eof())
  {
    int temp;
    ifile >> temp;
    size++;
  }
  ifile.clear();
  ifile.seekg(0, ios::beg); // seekg - �������� �� ������  ������ �����
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    ifile >> arr[i];
  }
  return arr;
}
*/

int* ReadFromFile(string filename, int& size, int number)
{ // ������ �����
    ifstream ifile;       // ������ ����
    ifile.open(filename);
    if (!ifile.is_open()) {
        cout << "error file is not found" << endl;
        return nullptr;
    }
    string buf;
    for (int i = 0; i < number; i++) {
        getline(ifile, buf);
    }
    if (ifile.eof()) {
        cout << "Error EOF" << endl;
        return nullptr;
    }
    size = 0;
    ifile >> size;
    if (size == 0) {
        cout << "Error eof" << endl;
        return nullptr;
    }
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        ifile >> arr[i];
    }
    return arr;
}

