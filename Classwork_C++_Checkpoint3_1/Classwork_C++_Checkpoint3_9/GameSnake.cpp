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

// координаты змейки относительно поля
int snRow, snCol;
int snSize; // длина, размер змейки
int rndRow, rndCol; // отступы от границ для области случ. появления змейки

int FRow, FCol; // координаты видимого фрукта
bool isFVisible; // фрукт виден или нет

// иниц-ция глобальных переменных игры
void InitSnake() {
  poleRow = 4;  poleCol = 9; // коорд. поля на экране
  poleHeight = 12; poleWidth = 30; // размеры поля
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
    choose = Menu(mainMenu, sizeMenu,
                      menuRow, menuCol, choose);
    // обработка выбранного пункта меню
    switch (choose) {
      case 0: // начать новую игру
        //StartGame(); // ф-ция старта новой игры
        break;
      case 1: // продолжить игру
        //ResumeGame(); // ф-ция продолжения игры
        break;
      case 2: // настройки
        //Settings(); // настройки
        break;
      case 3: // об авторах
        //About();
        break;
      case 4: // рекорды
        //ShowTop(); // вывод рекордов на экран
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

