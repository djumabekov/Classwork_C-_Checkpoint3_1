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
char** Pole = nullptr; // ��������� �� ������ ���������� ��� ������������� ���������� �������

// ���������� ������ ������������ ����
int snRow, snCol;
int snSize; // �����, ������ ������
int rndRow, rndCol; // ������� �� ������ ��� ������� ����. ��������� ������
// ������ ��������� ��������� ������
Coord* Snake = nullptr;

int FRow, FCol; // ���������� �������� ������
bool isFVisible; // ����� ����� ��� ���

// ����-��� ���������� ���������� ����
void InitSnake() {
  poleRow = 4;  poleCol = 9; // �����. ���� �� ������
  poleHeight = 12; poleWidth = 30; // ������� ����
  // �������� ���������� ������������� ������� ��� ������ �������� ����
  // 1 �������� ������� ���������� �� ������
  Pole = new char* [poleHeight];
  // 2 �������� ����� ���������� �������
  for (int i = 0; i < poleHeight; i++) {
    // �������� i-�� ������ ����. ���. �������
    Pole[i] = new char[poleWidth + 1]; // +1 ��� '\0'
    // �������� ������ �������
    for (int j = 0; j < poleWidth; j++) {
      Pole[i][j] = ' '; // ������ � (i,j)-� �������
    }
    Pole[i][poleWidth] = '\0'; // ��������� ������
  }

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
  // �������� ������� ��� ��������� ������
  Snake = new Coord[poleHeight * poleWidth];
  // ���������� ������ ������
  Snake[0].row = snRow;
  Snake[0].col = snCol;
  // ���� ������
  for (int i = 1; i < snSize; i++) {
    Snake[i].row = snRow;
    Snake[i].col = snCol - i;
    //Snake[i].row = Snake[i - 1].row;
    //Snake[i].col = Snake[i - 1].col - 1;
  }
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
    choose = Menu( mainMenu, sizeMenu,
                   menuRow, menuCol, choose);
    // ��������� ���������� ������ ����
    switch (choose) {
      case 0: // ������ ����� ����
        StartGame(); // �-��� ������ ����� ����
        break;
      case 1: // ���������� ����
        ResumeGame(); // �-��� ����������� ����
        break;
      case 2: // ���������
        Settings(); // ���������
        break;
      case 3: // �� �������
        About();
        break;
      case 4: // �������
        ShowTop(); // ����� �������� �� �����
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

void StartGame() {
  InitSnake();  // ����� ���������� ���� � �������� ���������
  ResumeGame(); // ���������� ���� � ���������� ���������� ����������
}
// ������� �������, ������ ����
void DrawBorder() {
  char sym = '*';
  // ������� ������� ����
  SetPos(poleRow - 1, poleCol - 1);
  for (int i = 0; i < poleWidth + 2; i++) {
    cout << sym;
  }
  // ������� �������
  for (int i = 0; i < poleHeight; i++) {
    // ����� �������
    SetPos(poleRow + i, poleCol - 1);
    cout << sym;
    // ������ �������
    SetPos(poleRow + i, poleCol + poleWidth);
    cout << sym;
  }
  // ������ �������
  SetPos(poleRow + poleHeight, poleCol - 1);
  for (int i = 0; i < poleWidth + 2; i++) {
    cout << sym;
  }
}
void ResumeGame() {
  CursorHide();
  system("cls"); // ������� ������
  DrawBorder(); // ������� �������, ������ ����
  // ����� ������
  char symHead = '@', symBody = 'o';
  // ����� ������ �� ����
  Pole[ Snake[0].row ][ Snake[0].col ] = symHead;
  // ����� ���� ������ �� ����
  for (int i = 1; i < snSize; i++) {
    int r = Snake[i].row;
    int c = Snake[i].col;
    Pole[r][c] = symBody;
  }
  // �������� ���� ����
  int dir = 0; // ����������� �������� ������
  bool isGameOver = false;
  while (!isGameOver) // while (isGameOver == false)
  {
    // ����� ������ �� ����
    if (isFVisible == true) {
      Pole[FRow][FCol] = 'F';
    }
    // ����� �������� ����
    for (int i = 0; i < poleHeight; i++) {
      SetPos(poleRow + i, poleCol);
      cout << Pole[i]; // ����� i-�� ������ ����
    }
    //   ��������� ������ ���������� ������� � ����������
    if ( _kbhit() ) // �������� ������� ����������
    { 
      int key = _getch(); // ��� ������� ������
      switch (key) {
        case _KEY::UP:    dir = 1; break; // �����
        case _KEY::DOWN:  dir = 2; break; // ����
        case _KEY::LEFT:  dir = 3; break; // �����
        case _KEY::RIGHT: dir = 4; break; // ������
        case _KEY::SPACE: dir = 0; break; // ����� ����
        case _KEY::ESC: // ����� � ������� ����
          return;
      }
    } // if ( _kbhit() )
    // �������� ������
    if (dir != 0) { // ������ �� ����� � �����
      // ���� ����������� ��������� ���� ������
      for (int i = snSize - 1; i >= 0; i--) {
        Snake[i + 1] = Snake[i];
      }
      if (dir == 1) { // �����
        if (Snake[0].row > 0) { Snake[0].row--; }
        else { isGameOver = true; }
      }
      if (dir == 2) { // ����
        if (Snake[0].row < poleHeight - 1) { Snake[0].row++; }
        else { isGameOver = true; }
      }
      if (dir == 3) { // �����
        if (Snake[0].col > 0) { Snake[0].col--; }
        else { isGameOver = true; }
      }
      if (dir == 4) { // ������
        if (Snake[0].col < poleWidth - 1) { Snake[0].col++; }
        else { isGameOver = true; }
      }
      Pole[Snake[0].row][Snake[0].col] = symHead; // ������
      Pole[Snake[1].row][Snake[1].col] = symBody; // ��� ������
      if (FRow == Snake[0].row && FCol == Snake[0].col) {
        snSize++; // ����� �����, ������ ����������
        // ����� ���������� ��� ������, ����� ���������
        //  ����� ��� �� ����������� � ����� ������
        FRow = RAND(0, poleHeight);
        FCol = RAND(0, poleWidth);
      }
      else {
        int r = Snake[snSize].row;
        int c = Snake[snSize].col;
        Pole[r][c] = ' '; // ������� ���� ������� ������� ������
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