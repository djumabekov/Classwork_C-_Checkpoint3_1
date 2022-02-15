// Menu.cpp
#include <iostream>
#include <string>
#include "Win10.h"  // SetPos/SetColor
using namespace std;

// переменные для подцветки пунктов меню
// для активного пункта меню
int clrSelFon = COLOR::blue; // цвет фона
int clrSelSym = COLOR::light_yellow; // цвет символа
// для неактивных пунктов меню
int clrUnselFon = COLOR::green;
int clrUnselSym = COLOR::black;
//  цвет консоли по умолчанию 0,7 = black,white
int clrDefaultFon = COLOR::black;
int clrDefaultSym = COLOR::white;


int Menu( string Items[], int Size,
          int Row, int Col,
          int Select /* =0 */)
{
  CursorHide(); // скрыть курсор
  // основной цикл меню
  while (true) {
    // вывод пунктов на экран
    for (int i = 0; i < Size; i++) {
      SetPos(Row + i, Col);
      if (i == Select) {
        SetColor(clrSelFon, clrSelSym); // подцветка активного пункта
      }
      else {
        SetColor(clrUnselFon, clrUnselSym); // нективный пункт
      }
      cout << Items[i]; // вывод i-го пункта меню на экран
    } // for()
    // обработка нажатий клавиш
    int key = _getch(); // 
    switch (key) {
      case _KEY::UP: case 'w': case 'W': // вверх
        if (Select > 0) { Select--; }
        else            { Select = Size - 1; }
        break;
      case _KEY::DOWN: case 's': case 'S': // вниз
        if (Select < Size-1) { Select++; }
        else                 { Select = 0; }
        break;
      case _KEY::ENTER:
        CursorHide(TRUE, 25); // показать курсор
        return Select; // возвращаем номер (индекс) выбранного пункта меню
      case _KEY::ESC:
        CursorHide(TRUE, 25); // показать курсор
        return -1; // отказ от выбора
    } // switch(key)
  } // while(true)
}