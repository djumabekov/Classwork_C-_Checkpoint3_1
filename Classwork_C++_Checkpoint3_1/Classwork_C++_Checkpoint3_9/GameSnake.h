// GameSnake.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

// прототип ф-ции Menu()
int Menu(string Items[], int Size,
  int Row, int Col, int Select = 0);

// глобальный прототип ф-ции GameSnake() из файла GameSnake.cpp
void GameSnake();