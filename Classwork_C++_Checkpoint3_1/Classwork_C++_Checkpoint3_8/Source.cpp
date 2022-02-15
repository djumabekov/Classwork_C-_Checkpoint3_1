#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

// ������� ��� ����� �����
void SetColor(WORD wAttributes) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// ������� ��� ����� �����
void SetColor(int colBkgr, int colSym) {
	int wAttributes = colBkgr * 16 + colSym;
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// ������� ��� ��������� ������� ������� ������
void SetPos(int Row, int Col) {
	COORD cd; cd.X = Col; cd.Y = Row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

// ������� ��� ������� �������
void CursorHide(BOOL bVisible, DWORD dwSize) {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = dwSize;
	cursorInfo.bVisible = bVisible;
	SetConsoleCursorInfo(hOUTPUT, &cursorInfo);
}

// �-��� ����������� �������� �������
//  ����������� ����
void GetConsolWindow(int& Width, int& Height)
{
	CONSOLE_SCREEN_BUFFER_INFO sb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sb);
	Width = sb.dwSize.X;
	Height = sb.dwSize.Y;
}


/*
12.*������� ���������, ����������� �������������.
�������� �������-������ ��� ������ � ���� ����������:
-����������� ��������������,
-��������� ������� ��������������,
����� �������������� � �������� ������� ������.
*/

// ���������, ����������� �������������
struct Rectangle {
	// ����������

	// ������
};

int main()
{
	system("chcp 1251 > nul");
	srand((unsigned int)time(0));


	cin.get(); cin.get();
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
using namespace std;
#pragma warning(disable:4996)

/*
29.*����������� ��������� "�����":
 ��������,
 �����,
 ������������,
 ����,
 ���������� �������,
 �����,
 ����.
�������� ��������� ��������� � ���������������� ������ � ���.

23. *����������� ��������� "�������":
 �����, �����, ��� �����, ���� ������.
����������� ��������� "�������":
 ���, �������, �������, "�������", ���� ��������.
*/
struct Book
{ // string name,author,publition,genre;
    string name;
    string author;
    string publition;
    string genre;
    int pages;
    int volume;
    double cost;
    void Input()
    {
        cout << "Enter name :";
        getline(cin, name);
        cout << "Enter author :";
        getline(cin, author);
        cout << "Enter genre :";
        getline(cin, genre);
        cout << "Enter publition :";
        getline(cin, publition);
        cout << "Enter page :";
        cin >> pages;
        cout << "Enter volume :";
        cin >> volume;
        cout << "Enter cost :";
        cin >> cost;
        cin.ignore();
    }
    void Print()
    {
        cout << "Name      : " << name << endl;
        cout << "Author    : " << author << endl;
        cout << "Genre     : " << genre << endl;
        cout << "Publition : " << publition << endl;
        cout << "Pages     : " << pages << endl;
        cout << "Volume    : " << volume << endl;
        cout << "Cost      : " << cost << endl;
    }
    double Money()
    {
        double res = (double)volume * cost;
        return res;
    }

};
void Input(Book& book);
void Print(Book book);

int main()
{
    system("chcp 1251 > nul");
    srand((unsigned int)time(0));
    Book book1 = { "War and Peice","Lev Tolst","Roman","Piter",
      2500,100000,5000.100, };
    //Print(book1);
    //Book book2;
    ////book2.name = "Push";
    //Input(book2);
    //Print(book2);
    //Input(book1);
    //Print(book1);
    book1.Print();
    Book book2;
    book2.Input();
    book2.Print();
    cout << " Total Cost book1 :" << book1.Money() << endl;
    cout << " Total Cost book2 :" << book2.Money() << endl;

    cin.get(); cin.get();
}

void Input(Book& book)
{
    cout << "Enter name :";
    getline(cin, book.name);
    cout << "Enter author :";
    getline(cin, book.author);
    cout << "Enter genre :";
    getline(cin, book.genre);
    cout << "Enter publition :";
    getline(cin, book.publition);
    cout << "Enter page :";
    cin >> book.pages;
    cout << "Enter volume :";
    cin >> book.volume;
    cout << "Enter cost :";
    cin >> book.cost;
    cin.ignore();
}

void Print(Book book)
{
    cout << "Name      : " << book.name << endl;
    cout << "Author    : " << book.author << endl;
    cout << "Genre     : " << book.genre << endl;
    cout << "Publition : " << book.publition << endl;
    cout << "Pages     : " << book.pages << endl;
    cout << "Volume    : " << book.volume << endl;
    cout << "Cost      : " << book.cost << endl;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
using namespace std;
#pragma warning(disable:4996)

/*
23. *����������� ��������� "�������":
 (�����, �����), ���, ��� �����, ���� ������.
����������� ��������� "�������":
 ���, �������, �������, "�������", ���� ��������.
*/

#define RAND(Min,Max) (rand()%( (Max)-(Min)+1 )+(Min))
struct Date
{
    void FillRand()
    {
        /*Day = rand() % 31 + 1;*/
        Day = RAND(1, 31);
        Month = RAND(1, 12);
        Year = RAND(1999, 2021);
    }
    int Day, Month, Year;
    void Input()
    {
        //cout << "������� ����: ";
        cin >> Day >> Month >> Year;
        cin.ignore();
    }

    void Print()
    {
        cout << setfill('0') << setw(2) << Day << "."
            << setfill('0') << setw(2) << Month << "."
            << setfill('0') << setw(4) << Year
            << setfill(' ');
    }
};
string IssuedArr[] = { "MVD RK","MU RK","Rus RK","USA RK" };
int IssuedSize = sizeof(IssuedArr) / sizeof(IssuedArr[0]);
struct Passport
{
    long long IIN;
    string IssuedBy;
    Date IssuedDay;
    void FillRand()
    {
        IIN = RAND(111111111111, 999999999999);
        IssuedBy = IssuedArr[RAND(0, IssuedSize - 1)];
        IssuedDay.FillRand();
    }
    void Input()
    {
        cout << "���: ";
        cin >> IIN;
        cin.ignore();
        cout << "����� ������: ";
        getline(cin, IssuedBy);
        cout << "���� ������: ";
        IssuedDay.Input();
    }
    void Print()
    {
        cout << "���: " << IIN << endl;
        cout << "��� ������: " << IssuedBy << endl;
        cout << "���� ������: ";
        IssuedDay.Print();
        cout << endl;
    }
};

struct Person
{
    string Name, LastName;
    int Age;
    Passport Pass;
    Date Birthday;

    void Input()
    {
        cout << "���: ";
        getline(cin, Name);
        cout << "�������: ";
        getline(cin, LastName);
        cout << "�������: ";
        cin >> Age;
        cin.ignore();
        cout << "���� ���������� ������." << endl;
        Pass.Input();
        cout << "������� ���� ��������: ";
        Birthday.Input();
    }

    void Print()
    {
        cout << "���: " << Name << endl;
        cout << "�������: " << LastName << endl;
        cout << "�������: " << Age << endl;
        cout << "���������� ������." << endl;
        Pass.Print();
        cout << "���� ��������: ";
        Birthday.Print();
        cout << endl;
    }
};


void Input(Person* arr, int size);
void Print(Person* arr, int size);
int main()
{
    system("chcp 1251 > nul");
    srand((unsigned int)time(0));



    /* Person Citizen;

     Citizen.Input();
     cout << endl;
     Citizen.Print();*/

    int size;
    cout << "������� ���������� �����: ";
    cin >> size;
    cin.ignore();

    Person* mas = new Person[size];
    Input(mas, size);
    Print(mas, size);


    cin.get(); cin.get();
}

void Input(Person* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].Input();
    }
}

void Print(Person* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].Print();
    }

}