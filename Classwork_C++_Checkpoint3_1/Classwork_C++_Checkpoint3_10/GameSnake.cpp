// GameSnake.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Win10.h" // SetColor/SetPos
#include "GameSnake.h"
using namespace std;
#pragma warning(disable:4996)

// глобальные переменные игры
int poleRow, poleCol; // экранные координаты игрового поля
int poleHeight, poleWidth; // размеры поля
char** Pole = nullptr; // указатель на массив указателей для динамического двумерного массива

// координаты змейки относительно поля
int snRow, snCol;
int snSize; // длина, размер змейки
int rndRow, rndCol; // отступы от границ для области случ. появления змейки
// массив координат элементов змейки
Coord* Snake = nullptr;

int FRow, FCol; // координаты видимого фрукта
bool isFVisible; // фрукт виден или нет

// иниц-ция глобальных переменных игры
void InitSnake() {
  poleRow = 4;  poleCol = 9; // коорд. поля на экране
  poleHeight = 12; poleWidth = 30; // размеры поля
  // создание двумерного динамического массива для холста игрового поля
  // 1 создание массива указателей на строки
  Pole = new char* [poleHeight];
  // 2 создание строк двумерного массива
  for (int i = 0; i < poleHeight; i++) {
    // создание i-ой строки двум. дин. массива
    Pole[i] = new char[poleWidth + 1]; // +1 для '\0'
    // очистить строки массива
    for (int j = 0; j < poleWidth; j++) {
      Pole[i][j] = ' '; // пробел в (i,j)-ю позицию
    }
    Pole[i][poleWidth] = '\0'; // завершаем строку
  }

  // отступы для диапазона случ. появления змейки
  rndRow = 3; rndCol = 4;
  // координаты змейки относительно поля и ее длина
  //  по центру поля
  //snRow = poleHeight / 2;
  //snCol = poleWidth / 2;
  // змейка появляется случ. в области
  snRow = RAND(rndRow, poleHeight - rndRow);
  snCol = RAND(rndCol, poleWidth  - rndCol);
  snSize = RAND(2, 5); // =3 длина змейки
  // создание массива для координат змейки
  Snake = new Coord[poleHeight * poleWidth];
  // координаты головы змейки
  Snake[0].row = snRow;
  Snake[0].col = snCol;
  // тело змейки
  for (int i = 1; i < snSize; i++) {
    Snake[i].row = snRow;
    Snake[i].col = snCol - i;
    //Snake[i].row = Snake[i - 1].row;
    //Snake[i].col = Snake[i - 1].col - 1;
  }
  // фрукт - случ. координаты
  FRow = RAND(0, poleHeight - 1);
  FCol = RAND(0, poleWidth  - 1);
  isFVisible = true; // фрукт виден сразу с начала игры
}

// массив строк меню
string mainMenu[] = {
  "Начать новую игру",
  "Продолжить игру",
  "Настройки игры",
  "Об авторах и игре",
  "Рекорды",
  "Выход"
};
// вычисляемый размер статического массива mainMenu
int sizeMenu = sizeof(mainMenu) / sizeof(mainMenu[0]);
// экранные координаты главного меню игры
int menuRow = 5, menuCol = 12;

// ф-ция запуска программы Игра-Змейка
void GameSnake()
{
  InitSnake(); // переменные в начальные состояния
  // основной цикл программы Игра-Змейка
  int choose = 0;
  bool isExit = false; // сигнал о выходе из цикла главного программы

  while( !isExit ) // while (isExit == false)
  {
    // вывод главного меню игры
    choose = Menu( mainMenu, sizeMenu,
                   menuRow, menuCol, choose);
    // обработка выбранного пункта меню
    switch (choose) {
      case 0: // начать новую игру
        StartGame(); // ф-ция старта новой игры
        break;
      case 1: // продолжить игру
        ResumeGame(); // ф-ция продолжения игры
        break;
      case 2: // настройки
        Settings(); // настройки
        break;
      case 3: // об авторах
        About();
        break;
      case 4: // рекорды
        ShowTop(); // вывод рекордов на экран
        break;
      case 5:   // "Выход"
      case -1:  // отказ от выбора - выход из главного меню
        isExit = true; // сигнал о выходе из программы
        break;
    } // switch (choose)
  } // while(!isExit);
  // 
  system("cls"); // очистиь экран
  SetPos(4, 10);
  cout << "До свидания!";
  SetPos(5, 10);
  system("pause");
} // GameSnake()

void StartGame() {
  InitSnake();  // сброс переменных игры в исходное состояние
  ResumeGame(); // продолжить игру с начальными значениями переменнхы
}
// вывести границы, бордюр поля
void DrawBorder() {
  char sym = '*';
  // верхняя граница поля
  SetPos(poleRow - 1, poleCol - 1);
  for (int i = 0; i < poleWidth + 2; i++) {
    cout << sym;
  }
  // боковые границы
  for (int i = 0; i < poleHeight; i++) {
    // левая граница
    SetPos(poleRow + i, poleCol - 1);
    cout << sym;
    // правая граница
    SetPos(poleRow + i, poleCol + poleWidth);
    cout << sym;
  }
  // нижняя граница
  SetPos(poleRow + poleHeight, poleCol - 1);
  for (int i = 0; i < poleWidth + 2; i++) {
    cout << sym;
  }
}
void ResumeGame() {
  CursorHide();
  system("cls"); // очистка экрана
  DrawBorder(); // вывести границы, бордюр поля
  // вывод змейки
  char symHead = '@', symBody = 'o';
  // вывод головы на поле
  Pole[ Snake[0].row ][ Snake[0].col ] = symHead;
  // вывод тела змейки на поле
  for (int i = 1; i < snSize; i++) {
    int r = Snake[i].row;
    int c = Snake[i].col;
    Pole[r][c] = symBody;
  }
  // основной цикл игры
  int dir = 0; // направления движения змейки
  bool isGameOver = false;
  while (!isGameOver) // while (isGameOver == false)
  {
    // вывод фрукта на поле
    if (isFVisible == true) {
      Pole[FRow][FCol] = 'F';
    }
    // вывод игрового поля
    for (int i = 0; i < poleHeight; i++) {
      SetPos(poleRow + i, poleCol);
      cout << Pole[i]; // вывод i-ой строки поля
    }
    //   обработка комант управления змейкой с клавиатуры
    if ( _kbhit() ) // проверка нажатия клавиатуре
    { 
      int key = _getch(); // код нажатой кнопки
      switch (key) {
        case _KEY::UP:    dir = 1; break; // вверх
        case _KEY::DOWN:  dir = 2; break; // вниз
        case _KEY::LEFT:  dir = 3; break; // влево
        case _KEY::RIGHT: dir = 4; break; // вправо
        case _KEY::SPACE: dir = 0; break; // пауза игры
        case _KEY::ESC: // выход в главное меню
          return;
      }
    } // if ( _kbhit() )
    // движение змейки
    if (dir != 0) { // змейка не стоит в паузе
      // цикл копирования координат тела змейки
      for (int i = snSize - 1; i >= 0; i--) {
        Snake[i + 1] = Snake[i];
      }
      if (dir == 1) { // вверх
        if (Snake[0].row > 0) { Snake[0].row--; }
        else { isGameOver = true; }
      }
      if (dir == 2) { // вниз
        if (Snake[0].row < poleHeight - 1) { Snake[0].row++; }
        else { isGameOver = true; }
      }
      if (dir == 3) { // влево
        if (Snake[0].col > 0) { Snake[0].col--; }
        else { isGameOver = true; }
      }
      if (dir == 4) { // вправо
        if (Snake[0].col < poleWidth - 1) { Snake[0].col++; }
        else { isGameOver = true; }
      }
      Pole[Snake[0].row][Snake[0].col] = symHead; // голова
      Pole[Snake[1].row][Snake[1].col] = symBody; // шея змейки
      if (FRow == Snake[0].row && FCol == Snake[0].col) {
        snSize++; // фрукт съден, змейка удлинилась
        // новые координаты для фрукта, нужно проверить
        //  чтобы они не пересеклись с телом змейки
        FRow = RAND(0, poleHeight);
        FCol = RAND(0, poleWidth);
      }
      else {
        int r = Snake[snSize].row;
        int c = Snake[snSize].col;
        Pole[r][c] = ' '; // стереть один элемент старого хвоста
      }
    } // if (dir != 0)
    Sleep(200);
  } // while(!iSGameOver)
} // StartGame()

void Settings() {

}

void About() {

}

void ShowTop() {

}