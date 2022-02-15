// GameSnake.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Win10.h" // SetColor/SetPos
#include "GameSnake.h"
using namespace std;
#pragma warning(disable:4996)

// ���������� ���������� ����
int poleRow, poleCol; // �������� ���������� �������� ����
int poleHeight, poleWidth; // ������� ����

// ���������� ������ ������������ ����
int snRow, snCol;
int snSize; // �����, ������ ������
int rndRow, rndCol; // ������� �� ������ ��� ������� ����. ��������� ������

int FRow, FCol; // ���������� �������� ������
bool isFVisible; // ����� ����� ��� ���

// ����-��� ���������� ���������� ����
void InitSnake() {
  poleRow = 4;  poleCol = 9; // �����. ���� �� ������
  poleHeight = 12; poleWidth = 30; // ������� ����
  // ������� ��� ��������� ����. ��������� ������
  rndRow = 3; rndCol = 4;
  // ���������� ������ ������������ ���� � �� �����
  //  �� ������ ����
  //snRow = poleHeight / 2;
  //snCol = poleWidth / 2;
  // ������ ���������� ����. � �������
  snRow = RAND(rndRow, poleHeight - rndRow);
  snCol = RAND(rndCol, poleWidth  - rndCol);
  snSize = RAND(2, 5); // =3 ����� ������
  // ����� - ����. ����������
  FRow = RAND(0, poleHeight - 1);
  FCol = RAND(0, poleWidth  - 1);
  isFVisible = true; // ����� ����� ����� � ������ ����
}

// ������ ����� ����
string mainMenu[] = {
  "������ ����� ����",
  "���������� ����",
  "��������� ����",
  "�� ������� � ����",
  "�������",
  "�����"
};
// ����������� ������ ������������ ������� mainMenu
int sizeMenu = sizeof(mainMenu) / sizeof(mainMenu[0]);
// �������� ���������� �������� ���� ����
int menuRow = 5, menuCol = 12;

// �-��� ������� ��������� ����-������
void GameSnake()
{
  InitSnake(); // ���������� � ��������� ���������
  // �������� ���� ��������� ����-������
  int choose = 0;
  bool isExit = false; // ������ � ������ �� ����� �������� ���������

  while( !isExit ) // while (isExit == false)
  {
    // ����� �������� ���� ����
    choose = Menu(mainMenu, sizeMenu,
                      menuRow, menuCol, choose);
    // ��������� ���������� ������ ����
    switch (choose) {
      case 0: // ������ ����� ����
        //StartGame(); // �-��� ������ ����� ����
        break;
      case 1: // ���������� ����
        //ResumeGame(); // �-��� ����������� ����
        break;
      case 2: // ���������
        //Settings(); // ���������
        break;
      case 3: // �� �������
        //About();
        break;
      case 4: // �������
        //ShowTop(); // ����� �������� �� �����
        break;
      case 5:   // "�����"
      case -1:  // ����� �� ������ - ����� �� �������� ����
        isExit = true; // ������ � ������ �� ���������
        break;
    } // switch (choose)
  } // while(!isExit);
  // 
  system("cls"); // ������� �����
  SetPos(4, 10);
  cout << "�� ��������!";
  SetPos(5, 10);
  system("pause");
} // GameSnake()

