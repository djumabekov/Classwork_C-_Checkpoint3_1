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
    cout << "RTrim: \"" << RTrim(str) << "\"" << endl;

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
