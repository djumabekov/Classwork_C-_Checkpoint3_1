// GameSnake.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ��������������� ��������� ��� ��������� ��������� ������
struct Coord {
  int row, col;
};

// �������� �-��� Menu()
int Menu(string Items[], int Size,
  int Row, int Col, int Select = 0);

// ���������� �������� �-��� GameSnake() �� ����� GameSnake.cpp
void GameSnake();
void StartGame();
void ResumeGame();
void Settings();
void About();
void ShowTop();
