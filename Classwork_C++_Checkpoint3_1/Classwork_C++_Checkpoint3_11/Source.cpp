#include <iostream> // Input Outup Stream
#include <iomanip>
#include <fstream>  // File Stream: ofstream, ifstream, fstream
#include <string>   // string, getline()
#include <time.h>
using namespace std;
#pragma warning(disable:4996)

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))

/*
1. Создать текстовый файл и записать в него фразу
"Здравствуй, мир!".

3. Записать массив строк в файл, расположив каждый
элемент массива на отдельной строке с сохранением порядка.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
*/

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    // создание и запись в текстовый файл
    // ofstream - Output File Stream
    ofstream ofile; // объявление переменной для записи в файл
                    // файловый объект для записи
    ofile.open("File1.txt"); // создание/пересоздание и открытие нового файла с именем "File1.txt"
    if (ofile.is_open() == true) {
        // создание и открытие файла прошло успешной
        ofile << "Hello World!" << endl;
        cout << "Hello World!" << endl;
        ofile << "Меня зовут Жанат!" << endl;
        cout << "Меня зовут Жанат!" << endl;
        ofile.close(); // принудительное закрытие файла
    }
    else {
        cout << "Ошибка создания и открытия файла для записи!" << endl;
    }
    // чтение файла
    // ifstream - Input File Stream
    // 1 объявление переменной ifile для чтения из файла
    // 2 открытие файла для чтения
    ifstream ifile("File1.txt"); // объявление и чтение
    if (ifile.is_open()) {
        // OK
        string buffer; // строковый буфер для чтения из потока

        getline(ifile, buffer); // чтение строки из файла
        //getline(cin, buffer); // чтение строки из консоли
        cout << buffer << endl;

        ifile >> buffer; // чтение одного слова до разделителя из файла
        //cin >> buffer; // чтение одного слова до разделителя с консоли
        cout << buffer << endl;
        ifile >> buffer; // чтение одного слова до разделителя
        cout << buffer << endl;
    }
    else {
        cout << "Ошибка открытия фала для чтения - "
            " файл не найден!" << endl;
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
3. Записать массив строк в файл, расположив каждый
элемент массива на отдельной строке с сохранением порядка.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
*/
void WriteToFile(string fName);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // имя файла
    cout << "Введите имя файла: ";
    getline(cin, FileName); // чтение имени файла

    // ф-ция для записи строк в файл FileName
    WriteToFile(FileName);
    PrintFile(FileName); // печать всех строк файла на экран

    cin.get(); cin.get();
}

// ф-ция для записи строк в файл FileName
void WriteToFile(string fName)
{
    ofstream file(fName);
    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "Ошибка создания и открытия файла \""
            << fName << "\" для файла!" << endl;
        return; // выход из ф-ции по ошибке
    }
    cout << "Вводите строки. Для завершения введи строки FINISH" << endl;
    string buf; // строковый буфер
    int cnt = 0; // счетчик строк
    while (true) {
        getline(cin, buf); // чтение с консоли
        if (buf == "FINISH") {
            break; // завершение ввода строк
        }
        // запись в файл
        if (cnt == 0) { file << buf; } // певая строка
        else { file << endl << buf; } // следующие строки
        cnt++; // считаем введенные строки
    }
    cout << "Ввод строк окончен" << endl << endl;
}

// ф-ция печати всех строк файла на экран
void PrintFile(string fName)
{
    ifstream file(fName); // открытие файла для чтения
    if (!file.is_open()) {
        cout << "Ошибка открытия файла \"" << fName
            << "\" для чтения - файл не найден!" << endl;
        return; // выход по ошибке
    }
    string buf; // строковый буфер для чтения из файла
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // цикл пока не конец файла
    {
        getline(file, buf); // чтение строки из файла
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "В файле " << i << " строк\n";
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
3. Записать массив строк в файл, расположив каждый
элемент массива на отдельной строке с сохранением порядка.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
*/
void WriteToFile(string fName);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // имя файла
    cout << "Введите имя файла: ";
    getline(cin, FileName); // чтение имени файла

    // ф-ция для записи строк в файл FileName
    //WriteToFile(FileName);
    PrintFile(FileName); // печать всех строк файла на экран

    cin.get(); cin.get();
}

// ф-ция для записи строк в файл FileName
void WriteToFile(string fName)
{
    ofstream file(fName);
    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "Ошибка создания и открытия файла \""
            << fName << "\" для файла!" << endl;
        return; // выход из ф-ции по ошибке
    }
    cout << "Вводите строки. Для завершения введи строки FINISH" << endl;
    string buf; // строковый буфер
    int cnt = 0; // счетчик строк
    while (true) {
        getline(cin, buf); // чтение с консоли
        if (buf == "FINISH") {
            break; // завершение ввода строк
        }
        // запись в файл
        if (cnt == 0) { file << buf; } // певая строка
        else { file << endl << buf; } // следующие строки
        cnt++; // считаем введенные строки
    }
    cout << "Ввод строк окончен" << endl << endl;
}

// ф-ция печати всех строк файла на экран
void PrintFile(string fName)
{
    ifstream file(fName); // открытие файла для чтения
    if (!file.is_open()) {
        cout << "Ошибка открытия файла \"" << fName
            << "\" для чтения - файл не найден!" << endl;
        return; // выход по ошибке
    }
    string buf; // строковый буфер для чтения из файла
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // цикл пока не конец файла
    {
        getline(file, buf); // чтение строки из файла
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "В файле " << i << " строк\n";
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
3. Записать массив строк в файл, расположив каждый
элемент массива на отдельной строке с сохранением порядка.

4. Записать целочисленный массив в файл.
Прочесть массив из файла.
int * mas = new int[size];
*/
void WriteToFile(string fName, int mode = 1);
void PrintFile(string fName);

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));

    string FileName; // имя файла
    cout << "Введите имя файла: ";
    getline(cin, FileName); // чтение имени файла

    cout << "Введите режим записи в файл:\n";
    cout << "1 - перезапись - старые данные удаляются\n";
    cout << "2 - дозапись - старые данные сохраняются\n";
    int choose;
    cin >> choose; cin.ignore();
    // ф-ция для записи строк в файл FileName
    WriteToFile(FileName, choose);
    PrintFile(FileName); // печать всех строк файла на экран
    cin.get(); cin.get();
}

// ф-ция определения размера файла
// long long, size_t
int GetFileSize(string fName) {
    ifstream file(fName);
    if (!file.is_open()) { return 0; }
    file.seekg(0, ios::end); // встать в конец файла
    int size = file.tellg(); // получить текущую позицию в файле
    return size; // вернуть размер файла
} // file.close();

// ф-ция для записи строк в файл FileName
void WriteToFile(string fName, int mode /* = 1 */)
{
    int Size = GetFileSize(fName); // получить размер файла в байтах
    ofstream file;
    if (mode == 1) {
        file.open(fName); // открыть для перезаписи
    }
    else if (mode == 2) {
        // ios::app - флаг, ключ для укзания режима append - дозапись, журналирование
        file.open(fName, ios::app); // открыть для дозаписи
        //if (Size > 0) { file << endl; }
    }
    else {
        cout << "Ошибка: Неверный режим записи файла!\n";
        return;
    }

    if (!file.is_open()) { // if( file.is_open() == false )
        cout << "Ошибка создания и открытия файла \""
            << fName << "\" для файла!" << endl;
        return; // выход из ф-ции по ошибке
    }
    if (mode == 2 && Size > 0) {
        file << endl; // разделить старые и новые данные endl-ом
    }

    cout << "Вводите строки. Для завершения введи строки FINISH" << endl;
    string buf; // строковый буфер
    int cnt = 0; // счетчик строк
    while (true) {
        getline(cin, buf); // чтение с консоли
        if (buf == "FINISH") {
            break; // завершение ввода строк
        }
        // запись в файл
        if (cnt == 0) { file << buf; } // певая строка
        else { file << endl << buf; } // следующие строки
        cnt++; // считаем введенные строки
    }
    cout << "Ввод строк окончен" << endl << endl;
}

// ф-ция печати всех строк файла на экран
void PrintFile(string fName)
{
    ifstream file(fName); // открытие файла для чтения
    if (!file.is_open()) {
        cout << "Ошибка открытия файла \"" << fName
            << "\" для чтения - файл не найден!" << endl;
        return; // выход по ошибке
    }
    string buf; // строковый буфер для чтения из файла
    int i = 0;
    // eof - End Of File
    while (!file.eof()) // цикл пока не конец файла
    {
        getline(file, buf); // чтение строки из файла
        cout << i + 1 << ") " << buf << endl;
        i++;
    }
    cout << "В файле " << i << " строк\n";
}
