#include <iostream>
#include <conio.h> //getch함수사용
#include <Windows.h>
#include "Screen.h"
#include"Bar.h"
#include"Ball.h"
#include"Brick.h"
using namespace std;

#define LEFT 75
#define RIGHT 77


int Bar::Get_X() const
{
	return x;
}
int Bar::Get_Y() const
{
	return y;
}
int Bar:: Get_Size() const
{
	return size;
}

void Bar::InitBar()
{
	if (size == 6)
		x = 22;
	else if (size == 10)
		x = 20;
	else
		x = 18;
}

Bar::Bar(int level) 
{
	//난이도별
	switch (level) 
	{		
	case 1:
	{
		x = 22;
		size = 6;
		break;
	}
	case 2:
	{
		x = 20;
		size = 10; 
		break;

	}
	case 3:
	{
		x = 18; 
		size =14;
	}
	}
}

void Bar:: Render()
{
	gotoxy(x, y);
	for (int i = 0; i < (size/2) ; i++)
	{
		cout << "▣";
	}
}

void Bar::input()
{
	
	if (int i = _kbhit())
	{
		i = _getch();
		if (i == 224)
		{
			i = _getch();
			switch (i)
			{
			case LEFT:
			{
				x--; break; //왼쪽으로 이동
			}
			case RIGHT:
			{
				x++;
				break; //오른쪽으로 이동
			}
			}
		}
	}
	else
	{
		this->x = x;
		this->y = y;
	}

	if (x <= 0)
	{
		this->x = 0;
	}
	else if (x + size >= 50)
	{
		this->x = 50-size;
	}

	
}
