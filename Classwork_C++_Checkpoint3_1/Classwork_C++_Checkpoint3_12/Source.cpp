#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
5. Дан текстовый файл.
Необходимо создать новый файл, в который переписать
из исходного файла все слова, состоящие не менее
чем из семи букв.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
Menu()

6. Дан текстовый файл.
Необходимо переписать его строки в другой файл.
Порядок строк во втором файле должен совпадать
с порядком строк в заданном файле.

18. Дан текстовый файл.
Зашифровать его, используя шифр Цезаря.
Результат записать в другой файл.
Шифр Цезаря - один из древнейших шифров.
При шифровании каждый символ заменяется другим,
отстоящим от него в алфавите на фиксированное число позиций.
Пример:
Шифрование с использованием ключа : 3
Оригинальный текст: "Съешь же ещё этих мягких французских булок, да выпей чаю"
Шифрованный текст:  "Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб"
*/

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    ofstream filewrite;
    ifstream fileread;
    string filenameread;
    string filenamewrite;
    cout << "Введите имя файла для чтения :";
    getline(cin, filenameread);
    cout << "Введите имя файла для запись :";
    getline(cin, filenamewrite);
    fileread.open(filenameread);
    if (fileread.is_open() != true)
    {
        cout << "Error file is not found" << endl;
    }
    else {
        filewrite.open(filenamewrite);
        while (!fileread.eof())
        {
            string buf;
            fileread >> buf;
            if (buf.size() >= 7) {
                cout << buf << endl;
                filewrite << buf << endl;
            }
        }
        filewrite.flush(); // сбрасывает данные на диск
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
5. Дан текстовый файл.
Необходимо создать новый файл, в который переписать
из исходного файла все слова, состоящие не менее
чем из семи букв.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
Menu()

6. Дан текстовый файл.
Необходимо переписать его строки в другой файл.
Порядок строк во втором файле должен совпадать
с порядком строк в заданном файле.

18. Дан текстовый файл.
Зашифровать его, используя шифр Цезаря.
Результат записать в другой файл.
Шифр Цезаря - один из древнейших шифров.
При шифровании каждый символ заменяется другим,
отстоящим от него в алфавите на фиксированное число позиций.
Пример:
Шифрование с использованием ключа : 3
Оригинальный текст: "Съешь же ещё этих мягких французских булок, да выпей чаю"
Шифрованный текст:  "Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб"
*/
int* Init_Arr(int& size);
bool Save_to_file(string filename, int* arr, int size);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    int size;
    int* parr = Init_Arr(size);
    cout << "Введите имя файла :";
    string name;
    getline(cin, name);
    if (Save_to_file(name, parr, size)) {
        cout << "Запись прошла успешно" << endl;
    }
    else {
        cout << "Ошибка во время записи" << endl;
    }
    cin.get(); cin.get();
}

int* Init_Arr(int& size)
{
    cout << "Введите размер массива :";
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
bool Save_to_file(string filename, int* arr, int size)
{
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error , cant create file " << endl;
        return false;
    }
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file << endl;
    return true;
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
5. Дан текстовый файл.
Необходимо создать новый файл, в который переписать
из исходного файла все слова, состоящие не менее
чем из семи букв.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
Menu()

6. Дан текстовый файл.
Необходимо переписать его строки в другой файл.
Порядок строк во втором файле должен совпадать
с порядком строк в заданном файле.

18. Дан текстовый файл.
Зашифровать его, используя шифр Цезаря.
Результат записать в другой файл.
Шифр Цезаря - один из древнейших шифров.
При шифровании каждый символ заменяется другим,
отстоящим от него в алфавите на фиксированное число позиций.
Пример:
Шифрование с использованием ключа : 3
Оригинальный текст: "Съешь же ещё этих мягких французских булок, да выпей чаю"
Шифрованный текст:  "Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб"
*/
int* Init_Arr(int& size);
bool Save_to_file(string filename, int* arr, int size);
int* ReadFromFile(string filename, int& size);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    int size;
    int* parr = Init_Arr(size);
    cout << "Введите имя файла :";
    string name;
    getline(cin, name);
    if (Save_to_file(name, parr, size)) {
        cout << "Запись прошла успешно" << endl;
    }
    else {
        cout << "Ошибка во время записи" << endl;
    }
    int size2 = 0;
    int* arr2 = ReadFromFile(name, size2);
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Size2 : " << size2;
    cout << endl;
    cin.get(); cin.get();
    delete[]parr;
    delete[]arr2;
}

int* Init_Arr(int& size)
{
    cout << "Введите размер массива :";
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
bool Save_to_file(string filename, int* arr, int size)
{
    ofstream file(filename);
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

  ifstream ifile;       // обьект файл
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
  ifile.seekg(0, ios::beg); // seekg - смещение по байтам  внутри файла
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    ifile >> arr[i];
  }
  return arr;
}
*/

int* ReadFromFile(string filename, int& size)
{ // формат файла
    ifstream ifile;       // обьект файл
    ifile.open(filename);
    if (!ifile.is_open())
    {
        cout << "error file is not found" << endl;
        return nullptr;
    }
    ifile >> size;
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
#include "Win10.h"
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
5. Дан текстовый файл.
Необходимо создать новый файл, в который переписать
из исходного файла все слова, состоящие не менее
чем из семи букв.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
Menu()

6. Дан текстовый файл.
Необходимо переписать его строки в другой файл.
Порядок строк во втором файле должен совпадать
с порядком строк в заданном файле.

18. Дан текстовый файл.
Зашифровать его, используя шифр Цезаря.
Результат записать в другой файл.
Шифр Цезаря - один из древнейших шифров.
При шифровании каждый символ заменяется другим,
отстоящим от него в алфавите на фиксированное число позиций.
Пример:
Шифрование с использованием ключа : 3
Оригинальный текст: "Съешь же ещё этих мягких французских булок, да выпей чаю"
Шифрованный текст:  "Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб"
*/
int* Init_Arr(int& size);
bool Save_to_file(string filename, int* arr, int size);
int* ReadFromFile(string filename, int& size);

int Menu(string Items[], int Size, // массив пунктов меню
    int Row, int Col, // экранные координаты меню
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
        case 1: cout << "Enter size array "; cin >> size;
            cin.ignore();
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
            break;
        case 4:
        {
            int size2 = 0;
            int* arr2 = ReadFromFile(filename, size2);
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
    cout << "Введите размер массива :";
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
bool Save_to_file(string filename, int* arr, int size)
{
    ofstream file(filename);
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

  ifstream ifile;       // обьект файл
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
  ifile.seekg(0, ios::beg); // seekg - смещение по байтам  внутри файла
  int* arr = new int[size];
  for (int i = 0; i < size; i++) {
    ifile >> arr[i];
  }
  return arr;
}
*/

int* ReadFromFile(string filename, int& size)
{ // формат файла
    ifstream ifile;       // обьект файл
    ifile.open(filename);
    if (!ifile.is_open())
    {
        cout << "error file is not found" << endl;
        return nullptr;
    }
    ifile >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        ifile >> arr[i];
    }
    return arr;
}