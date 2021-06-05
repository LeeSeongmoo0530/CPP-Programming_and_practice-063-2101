#pragma once
#ifndef __SCREEN_H_
#define __SCREEN_H_
#include"Brick.h"


void gotoxy(int x, int y);
void ScreenLine();
int InitScreen();
void ScoreScreen(int Level, Brick* BrickObj);
void EndOfGame();
void CursorView(char show);
void SetConsoleView();
void SuccessScreen();


#endif
