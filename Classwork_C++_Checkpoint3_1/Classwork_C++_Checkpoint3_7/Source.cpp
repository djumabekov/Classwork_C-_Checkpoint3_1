#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

/*
  ��������� ������� ������ � �������� ��������
LTrim() - �������� ���������� �������� ����� - ������� �������
RTrim() - �������� ���������� �������� ������ - �������� �������
Trim()  - �������� ���������� �������� ������ � �����

TrimAll() - �������� ����   ������   ��������
            �������� ���� ������ ��������
"    �������     �����     ���������           "
"������� ����� ���������"
*/

// ���������
// �-��� �������� ������� (�����) �������� � ������
char* LTrim(char* str);
// �-��� �������� ��������� (������) �������� � ������
char* RTrim(char* str);
// �-��� �������� ������� � ��������� �������� � ������
char* Trim(char* str);
// �-��� �������� ���� ������ �������� � ������
char* TrimAll(char* str);
#define SIZE 200
int main()
{
    system("chcp 1251 > nul");
    char str[SIZE];
    cout << "������� ������: ";
    cin.getline(str, SIZE);
    cout << "str:   \"" << str << "\"\n";
    //cout << "RTrim: \"" << RTrim(str) << "\"" << endl;
    //cout << "LTrim: \"" << LTrim(str) << "\"" << endl;
    cout << "TrimAll: \"" << TrimAll(str) << "\"" << endl;

    cin.get(); cin.get();
}

// "�-��� �������� ��������� ��������           "
// "�-��� �������� ��������� ��������"
char* RTrim(char* str)
{
    if (str[0] == '\0') { return str; } // ����� ��-�� ������ ������
    //if (!*str) { return str; } // ����� ��-�� ������ ������
    int len = strlen(str); // ������� ����� ������
    //if (len == 0) { return str; } // ����� ��-�� ������ ������
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            //break;
            return str;
        }
    }
    str[0] = '\0'; // ������ �� �������� ==> ������ ������
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
#include <string> // ��� ������ string
using namespace std;
#pragma warning(disable: 4996)

/*
���������

14. *�������� ���������, ����������� ����� � ���������
������� ��������� (x, y).
� ������� ���� ��������� ������� ��� �����.
�������� �������, ������� ��������� ����������
����� ����� ����� �������?

10.*������� ���������, ����������� �����.
� ��������� ������:
�������� ������, ����, ��������, ����� ������������.
����������� ������� ��� ����������� ������ � ���� ����������.

5. **������� ��������� ������ (��������, ����, ������, �����).
������� ������ ����������� ��������� ������ � �������� ���������, �����������:
- ����������� �������� ������ �������;
- �������� ������ ������ � �������� ������ ��� ����� ��������;
- �������� ������ ������ � ������ ������ ��� ����� ��������;
- ����������� ������ ������ �� ������� ��� �����;
- ����������� ������ ������ �� ��������;
*/
// ���������� ��������� Point
struct Point { // PointXY, Point2D, Point3D
  // ���� ���������, � ���
  // ����������, ����, �������� ���������
    string Name;  // �������� �����
    int x, y;     // ���������� �����
};

void Input(Point& pt);
void Print(Point pt);

int main()
{
    system("chcp 1251 > nul");
    // ���������� ���������� ���� Point
    Point a; // a - ��������� ��������� Point
    Point b = { "����� B", 1, 2 }; // ����-��� ����������� ���������� �������
    // ������������ ����-��� ����� ����������� ���������� a
    a.Name = "����� A";
    a.x = 10;
    a.y = 20;
    // ������ ����� ����������� ���������� a
    cout << "���� ���������� a:" << endl;
    cout << "Point::Name = " << a.Name << endl;
    cout << "Point::x    = " << a.x << endl;
    cout << "Point::y    = " << a.y << endl;
    // A(1;2)
    cout << b.Name << "("
        << b.x << ";"
        << b.y << ")\n";
    // ������ � ������ ��� ��������� a � b
    Input(a);
    Print(a);

    Input(b);
    Print(b);
    // ��������� �������� �-��� Distance()
    double Distance(Point p1, Point p2);
    cout << "���������� ����� a � b = " << Distance(a, b) << endl;
    cout << "���������� ����� b � a = " << Distance(b, a) << endl;

    cin.get(); cin.get();
}
// �-��� ���������� ���������� ����� ����� ������� ���� Point
double Distance(Point p1, Point p2)
{
    double a = p1.y - p2.y; // a = y1 - y2
    double b = p1.x - p2.x; // b = x1 - x2
    // sqrt() - �-��� ���������� ����������� �����
    double c = sqrt(a * a + b * b);
    return c;
}

// �-��� ������ � ������� � ���������� ����� ���������
//  ���� Point
void Input(Point& pt) {
    cout << "������� �������� �����: ";
    //cin >> pt.Name; // ������ � ������� ������ �����
    getline(cin, pt.Name); // ������ � ������� ����� ������
    cout << "������� ���������� x,y: ";
    cin >> pt.x >> pt.y; // <ENTER>
    cin.ignore(); // ������ ������ <ENTER> ����� ������ cin>>
    //cin.get();
}

// ����� �� ����� ����������� ���������� ���� Point
//  � ������� A(1;2)
void Print(Point pt) {
    cout << pt.Name << "("
        << pt.x << ";"
        << pt.y << ")\n";
}
