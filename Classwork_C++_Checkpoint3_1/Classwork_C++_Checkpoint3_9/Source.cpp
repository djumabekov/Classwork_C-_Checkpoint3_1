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
  ���� "������"
*/

int main()
{
  system("chcp 1251 > nul");
  srand((unsigned int)time(0));
  /* // ��� �������� ����������� Win10.cpp/Win10.h
  SetColor(COLOR::blue, COLOR::yellow);
  SetPos(4, 10);
  cout << "Hello World!";*/
  
  //TitleStart();  // ��������� ��������
  GameSnake();   // ����� ���� ����
  //TitleFinish(); // �������� ��� ������ �� ���������

  cin.get(); cin.get();
}
