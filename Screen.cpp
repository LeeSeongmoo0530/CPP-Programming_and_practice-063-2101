#include<iostream>
#include<Windows.h>
#include<conio.h> // _getch()함수를 사용하기위한 헤더파일
#include"Brick.h"
#include "Bar.h"

using namespace std;


//가로 50 세로 35 그림들 하나 크키는 2 X 1
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
	for (int i = 1; i < 35;i++)
	{
		gotoxy(0, i);
		cout << "┃                                                ┃";
	}

	gotoxy(0, 35);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
}


//게임 초기화면 - 난이도를 입력받음
int InitScreen()
{
	ScreenLine();
	gotoxy(15, 2);
	cout << "*******************";
	gotoxy(15, 3);
	cout << "*벽 돌 깨 기 게 임*";
	gotoxy(15, 4);
	cout << "*******************";
	gotoxy(5, 6);
	cout << "난이도를 선택하세요 1. 상   2. 중   3.하";
	
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
	return (Level - 48);
}



//점수와 난이도 출력 창 - Board 옆에 계속 출력
void ScoreScreen(int Level, Brick* BrickObj)
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
	BrickObj->score_print();
	
}

//벽돌을 모두 깼을때
void SuccessScreen()
{
	system("cls");
	gotoxy(5, 3);
	cout << "**************************************************";
	for (int i = 0; i < 10; i++)
	{
		gotoxy(5, 4 + i);
		cout << "*                                                *";
	}
	gotoxy(5, 14);
	cout << "**************************************************";
	gotoxy(20, 8);
	cout << "축하드립니다";
	gotoxy(20, 10);
	cout << ("벽돌을 다 깨셨습니다");

}

//게임 끝날때 띄우는창
void EndOfGame()
{
	system("cls");
	gotoxy(5, 3);
	cout << "**************************************************";
	for (int i = 0; i < 10; i++)
	{
		gotoxy(5, 4 + i);
		cout << "*                                                *";
	}
	gotoxy(5, 14);
	cout << "**************************************************";
	gotoxy(20, 8);
	cout << "게임을 종료합니다";
	gotoxy(20, 10);
	cout << "수고하셨습니다.";
	gotoxy(0, 30);

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
	system("mode con:cols=100 lines=55");
	system("title Break_Bricks");
}
