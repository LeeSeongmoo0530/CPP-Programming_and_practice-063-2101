#include<iostream>
#include<Windows.h>
#include<conio.h> // _getch()함수를 사용하기위한 헤더파일


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



//Board- 게임에서 양 벽을 그리는 함수
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
	return Level;

}


//점수 출력 창 - Board 옆에 계속 출력 중
void ScoreScreen(int Level)
{


	gotoxy(5, 5);
	if (Level == '1')
	{
		cout << "난이도  :  상";
	}
	else if (Level == '2')
	{
		cout << "난이도  :  중";
	}
	else if (Level == '3')
	{
		cout << "난이도  :  하";
	}

	gotoxy(5, 7);
	//Brickobj.Score_print();
}


//매개변수 제거해서 Render() 하고 goto에 각 클래스의 좌표 대입
void Render(int x , int y)
{
	gotoxy(x, y);
	cout << "●";  // 공 -처음좌표(24,19)
	cout << "▣";  // 막대기 - 이건 3개 5개 7개 하면 됨 처음좌표 3개일때-(22,20) 5개일때 - (20,20) 7개일때 - (18,20)
	cout << "■";  //벽돌 가로 20개 세로 3줄

}