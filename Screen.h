#ifndef __SCREEN_H_
#define __SCREEN_H_
#include<iostream>
#include<Windows.h>
#include<conio.h> // _getch()함수를 사용하기위한 헤더파일
#include"Brick.h"
#include "Bar.h"

using namespace std;


//가로 50 세로 25 그림들 하나 크키는 2 X 1
//(0,0) ---------------------------> x
//	｜
//	｜
// 	｜
// 	｜
// 	｜
// 	｜
// 	｜
// 	｜
// 	｜ 
//  ∨ 
// y 
 

//콘솔창에서 커서를 입력한 x,y좌표에 위치 시킴
void gotoxy(int x, int y)
{
	COORD CurSorPosition = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurSorPosition);
}

//Board- 게임에서 양 벽을 그리는 함수 -
void ScreenLine()
{
	gotoxy(0, 0);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	for (int i = 1; i < 25; i++)
	{
		gotoxy(0, i);
		cout << "┃                                                ┃";
	}

	gotoxy(0, 25);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
}


//게임 초기화면 - 난이도를 입력받음
int InitScreen()
{

	gotoxy(2, 2);
	cout << "********************************************************************\n";
	cout << "                          벽 돌 깨 기 게 임                         \n";
	gotoxy(2, 4);
	cout << "********************************************************************\n";
	cout << endl << endl;
	cout << "                난이도를 선택하세요 1. 상   2. 중   3.하";
	int Level;
	while (1)
	{
		Level = _getch(); //ASCII 로 반환
		if (Level > 48 && Level < 52)
		{
			break;
		}

	}
	//콘솔창 지워줌
	system("cls");
	return (Level-48);
}


//점수와 난이도 출력 창 - Board 옆에 계속 출력
void ScoreScreen(int Level,Brick& BrickObj)
{


	gotoxy(55, 5);
	if (Level == 1)
	{
		cout << "난이도  :  상";
	}
	else if (Level == 2)
	{
		cout << "난이도  :  중";
	}
	else if (Level == 3)
	{
		cout << "난이도  :  하";
	}

	gotoxy(55, 7);
	BrickObj.score_print();
}

//게임 끝날때 띄우는창
void EndOfGame()
{


}

//커서 안보이게 (show=0 이면 안보임 1이면 보임)
void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

//콘솔창 크기와 제목
void SetConsoleView()
{
	system("mode con:cols=50 lines=25");
	system("title Break_Bricks");}

#endif
