// Source.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include "Win10.h"
#include "GameSnake.h"
using namespace std;
#pragma warning(disable:4996)

/*
  Игра "Змейка"
*/

int main()
{
  system("chcp 1251 > nul");
  srand((unsigned int)time(0));
  /* // для проверки подключения Win10.cpp/Win10.h
  SetColor(COLOR::blue, COLOR::yellow);
  SetPos(4, 10);
  cout << "Hello World!";*/
  
  //TitleStart();  // стартовая заставка
  GameSnake();   // старт кода игры
  //TitleFinish(); // заставка при выходе из программы

  cin.get(); cin.get();
}
