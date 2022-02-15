#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
1. ������� ��������� ���� � �������� � ���� �����
"����������, ���!".

3. �������� ������ ����� � ����, ���������� ������
������� ������� �� ��������� ������ � ����������� �������.

4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
*/

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    // �������� � ������ � ��������� ����
    // ofstream - Output File Stream
    ofstream ofile; // ���������� ���������� ��� ������ � ����
                    // �������� ������ ��� ������
    ofile.open("File1.txt"); // ��������/������������ � �������� ������ ����� � ������ "File1.txt"
    if (ofile.is_open() == true) {
        // �������� � �������� ����� ������ ��������
        ofile << "Hello World!" << endl;
        cout << "Hello World!" << endl;
        ofile << "���� ����� �����!" << endl;
        cout << "���� ����� �����!" << endl;
        ofile.close(); // �������������� �������� �����
    }
    else {
        cout << "������ �������� � �������� ����� ��� ������!" << endl;
    }
    // ������ �����
    // ifstream - Input File Stream
    // 1 ���������� ���������� ifile ��� ������ �� �����
    // 2 �������� ����� ��� ������
    ifstream ifile("File1.txt"); // ���������� � ������
    if (ifile.is_open()) {
        // OK
        string buffer; // ��������� ����� ��� ������ �� ������

        getline(ifile, buffer); // ������ ������ �� �����
        //getline(cin, buffer); // ������ ������ �� �������
        cout << buffer << endl;

        ifile >> buffer; // ������ ������ ����� �� ����������� �� �����
        //cin >> buffer; // ������ ������ ����� �� ����������� � �������
        cout << buffer << endl;
        ifile >> buffer; // ������ ������ ����� �� �����������
        cout << buffer << endl;
    }
    else {
        cout << "������ �������� ���� ��� ������ - "
            " ���� �� ������!" << endl;
    }

    cin.get(); cin.get();
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
3. �������� ������ ����� � ����, ���������� ������
������� ������� �� ��������� ������ � ����������� �������.

4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
*/
void WriteToFile(string fName);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // ��� �����
    cout << "������� ��� �����: ";
    getline(cin, FileName); // ������ ����� �����

    // �-��� ��� ������ ����� � ���� FileName
    WriteToFile(FileName);
    PrintFile(FileName); // ������ ���� ����� ����� �� �����

    cin.get(); cin.get();
}

// �-��� ��� ������ ����� � ���� FileName
void WriteToFile(string fName)
{
    ofstream file(fName);
    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "������ �������� � �������� ����� \""
            << fName << "\" ��� �����!" << endl;
        return; // ����� �� �-��� �� ������
    }
    cout << "������� ������. ��� ���������� ����� ������ FINISH" << endl;
    string buf; // ��������� �����
    int cnt = 0; // ������� �����
    while (true) {
        getline(cin, buf); // ������ � �������
        if (buf == "FINISH") {
            break; // ���������� ����� �����
        }
        // ������ � ����
        if (cnt == 0) { file << buf; } // ����� ������
        else { file << endl << buf; } // ��������� ������
        cnt++; // ������� ��������� ������
    }
    cout << "���� ����� �������" << endl << endl;
}

// �-��� ������ ���� ����� ����� �� �����
void PrintFile(string fName)
{
    ifstream file(fName); // �������� ����� ��� ������
    if (!file.is_open()) {
        cout << "������ �������� ����� \"" << fName
            << "\" ��� ������ - ���� �� ������!" << endl;
        return; // ����� �� ������
    }
    string buf; // ��������� ����� ��� ������ �� �����
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // ���� ���� �� ����� �����
    {
        getline(file, buf); // ������ ������ �� �����
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "� ����� " << i << " �����\n";
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
3. �������� ������ ����� � ����, ���������� ������
������� ������� �� ��������� ������ � ����������� �������.

4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
*/
void WriteToFile(string fName);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // ��� �����
    cout << "������� ��� �����: ";
    getline(cin, FileName); // ������ ����� �����

    // �-��� ��� ������ ����� � ���� FileName
    //WriteToFile(FileName);
    PrintFile(FileName); // ������ ���� ����� ����� �� �����

    cin.get(); cin.get();
}

// �-��� ��� ������ ����� � ���� FileName
void WriteToFile(string fName)
{
    ofstream file(fName);
    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "������ �������� � �������� ����� \""
            << fName << "\" ��� �����!" << endl;
        return; // ����� �� �-��� �� ������
    }
    cout << "������� ������. ��� ���������� ����� ������ FINISH" << endl;
    string buf; // ��������� �����
    int cnt = 0; // ������� �����
    while (true) {
        getline(cin, buf); // ������ � �������
        if (buf == "FINISH") {
            break; // ���������� ����� �����
        }
        // ������ � ����
        if (cnt == 0) { file << buf; } // ����� ������
        else { file << endl << buf; } // ��������� ������
        cnt++; // ������� ��������� ������
    }
    cout << "���� ����� �������" << endl << endl;
}

// �-��� ������ ���� ����� ����� �� �����
void PrintFile(string fName)
{
    ifstream file(fName); // �������� ����� ��� ������
    if (!file.is_open()) {
        cout << "������ �������� ����� \"" << fName
            << "\" ��� ������ - ���� �� ������!" << endl;
        return; // ����� �� ������
    }
    string buf; // ��������� ����� ��� ������ �� �����
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // ���� ���� �� ����� �����
    {
        getline(file, buf); // ������ ������ �� �����
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "� ����� " << i << " �����\n";
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
3. �������� ������ ����� � ����, ���������� ������
������� ������� �� ��������� ������ � ����������� �������.

4. �������� ������������� ������ � ����.
�������� ������ �� �����.
int * mas = new int[size];
*/
void WriteToFile(string fName, int mode = 1);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // ��� �����
    cout << "������� ��� �����: ";
    getline(cin, FileName); // ������ ����� �����

    cout << "������� ����� ������ � ����:\n";
    cout << "1 - ���������� - ������ ������ ���������\n";
    cout << "2 - �������� - ������ ������ �����������\n";
    int choose;
    cin >> choose; cin.ignore();
    // �-��� ��� ������ ����� � ���� FileName
    WriteToFile(FileName, choose);
    PrintFile(FileName); // ������ ���� ����� ����� �� �����
    cin.get(); cin.get();
}

// �-��� ����������� ������� �����
// long long, size_t
int GetFileSize(string fName) {
    ifstream file(fName);
    if (!file.is_open()) { return 0; }
    file.seekg(0, ios::end); // ������ � ����� �����
    int size = file.tellg(); // �������� ������� ������� � �����
    return size; // ������� ������ �����
} // file.close();

// �-��� ��� ������ ����� � ���� FileName
void WriteToFile(string fName, int mode /* = 1 */)
{
    int Size = GetFileSize(fName); // �������� ������ ����� � ������
    ofstream file;
    if (mode == 1) {
        file.open(fName); // ������� ��� ����������
    }
    else if (mode == 2) {
        // ios::app - ����, ���� ��� ������� ������ append - ��������, ��������������
        file.open(fName, ios::app); // ������� ��� ��������
        //if (Size > 0) { file << endl; }
    }
    else {
        cout << "������: �������� ����� ������ �����!\n";
        return;
    }

    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "������ �������� � �������� ����� \""
            << fName << "\" ��� �����!" << endl;
        return; // ����� �� �-��� �� ������
    }
    if (mode == 2 && Size > 0) {
        file << endl; // ��������� ������ � ����� ������ endl-��
    }

    cout << "������� ������. ��� ���������� ����� ������ FINISH" << endl;
    string buf; // ��������� �����
    int cnt = 0; // ������� �����
    while (true) {
        getline(cin, buf); // ������ � �������
        if (buf == "FINISH") {
            break; // ���������� ����� �����
        }
        // ������ � ����
        if (cnt == 0) { file << buf; } // ����� ������
        else { file << endl << buf; } // ��������� ������
        cnt++; // ������� ��������� ������
    }
    cout << "���� ����� �������" << endl << endl;
}

// �-��� ������ ���� ����� ����� �� �����
void PrintFile(string fName)
{
    ifstream file(fName); // �������� ����� ��� ������
    if (!file.is_open()) {
        cout << "������ �������� ����� \"" << fName
            << "\" ��� ������ - ���� �� ������!" << endl;
        return; // ����� �� ������
    }
    string buf; // ��������� ����� ��� ������ �� �����
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // ���� ���� �� ����� �����
    {
        getline(file, buf); // ������ ������ �� �����
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "� ����� " << i << " �����\n";
}
