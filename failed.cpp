#include<iostream>
#include "ball.h"



//실패판정함수
bool Failed(BALL& b)
{
	if (b.f_FailedPos())
	{
		gotoxy(5, 5);
		cout << "공이 바닥으로 떨어졌습니다. \n";
		cout << "\t1.재도전\n\t2.처음화면으로 돌아가기\n\t3.게임종료" << endl;
		int option;
		while (1)
		{
			cin >> option;
			if (option == 1 || option == 2)
			{
				Reset(option);
				//option에서 처음이냐 재도전이냐 
				//재도전함수
				break;
			}
			if(option == 3)
			{
				exit(0);
			}
			else
			{
				cout << "다시 선택해주세요" << endl;
				continue;
			}
		}
		//실패가 아니므로
		return false;
	}



