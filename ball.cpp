#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include"Ball.h"
#include"Screen.h"
#include"Bar.h"
#include"Brick.h"
using namespace std;

//공반지름
#define R 1

//막대기의 높이
#define BarHeight 1

//블록의 가로길이
#define BrickWidth 2
#define BrickHeight 1

//1.Ball의 멤버변수를 사용하기위한 함수
int Ball::f_Ball_Get_Direct() const
{
	return Ball_Direct;
}
int Ball :: f_Ball_Get_X() const
{
	return BallX;
}
int Ball::f_Ball_Get_Y() const 
{
	return BallY;
}

Ball::Ball()
{
	BallX = 24;
	BallY = 19;
}

//2.초기발사 왼쪽위 or오른쪽위
//처음에 InitBall호출
void Ball:: f_InitBALL()
{
	BallX = 24;
	BallY = 19;
	InitBallMove = true;

	srand((unsigned int)time(NULL));

	int Startdirect= rand() % 2;
	if (Startdirect == 1)
	{
		Ball_Direct = Right_top;
		BallMoveX = true;
		BallMoveY = true;
	}
	
	//왼쪽위
	else
	{
		Ball_Direct = Left_top;
		BallMoveX = false;
		BallMoveY = true;
	}
}


////다른 객체들과 충돌할때 호출되어 공의 방향을 바꿔줍니다
////3.이동방향함수
//int Ball::f_BALL_Direct()
//{
//	
//	// 공이 움직이지 않으면 리턴
//	if (!InitBallMove)
//		return 0;
//
//	switch (Ball_Direct)
//	{
//		//공의 방향이 Left_top이면 공의 방향을 Left_down으로 바꿔줌
//	case 0:
//		Ball_Direct = Left_down;
//		BallMoveX = false;
//		BallMoveY = false;
//		return Ball_Direct;
//		//Left_down -> Left_top
//	case 1:
//		Ball_Direct = Left_top;
//		BallMoveX = false;
//		BallMoveY = true;
//		return Ball_Direct;
//		//Right_top->Right_down
//	case 2:
//		Ball_Direct = Right_down;
//		BallMoveX = true;
//		return Ball_Direct;
//		//Right_down -> Right_top
//	case 3:
//		Ball_Direct = Right_top;
//		BallMoveX = true;
//		BallMoveY = true;
//		return Ball_Direct;
//	}
//}


//4.벽돌과 충돌판정 함수
bool Ball::f_BALL_Brick(Ball& ballobj, Brick& Brickobj)
{
	if (!ballobj.InitBallMove)
		return false;

	int BallTop = ballobj.BallY;
	int BallBottom = ballobj.BallY + R;
	int BallLeft = ballobj.BallX ;
	int BallRight = ballobj.BallX + 2*R;

	int BrickNumY=3, BrickNumX = 20;
	int BrickX, BrickY;
	int BrickLeft, BrickRight, BrickTop, BrickBottom;
	// Brick[]-XY블록 2차원 배열 ,  BrickNumX Y - X, Y 블록갯수 
	for (int y = 0; y < BrickNumY; y++)
	{
		for (int x = 0; x < BrickNumX; x++)
		{
			// 벽돌이 죽어있는 경우 다음 블록으로
			//Brick.on 블록이 살아있는지
			if ((Brickobj.get_coord(x,y).get_display_signal()==0))
			{
				continue;
			}

			BrickLeft = Brickobj.get_coord(x, y).get_x();
			BrickRight = BrickLeft + BrickWidth;
			BrickTop = Brickobj.get_coord(x, y).get_y();
			BrickBottom = BrickTop +BrickHeight;
			
			int index;
			if (x == 0) 
			{
				index = x + y;
			}
			else if (x == 1)
			{
				index=x + y + 19;
			}
			else if (x == 2)
			{
				index=x + y + 39;
			}

			// 공하고 벽돌하고 충돌 체크

			// 상하가 부딪치는 경우
			if ( BrickLeft-R<=BallLeft<=BrickLeft+R)
			{
				// 아랫면 충돌
				if (ballobj.BallMoveY && (BallTop >= BrickBottom) && (BallTop - BrickBottom ==0))
				{
					Brickobj.delete_bricks(index);
					ballobj.BallMoveY = !ballobj.BallMoveY;
					return true;
				}

				// 윗면 충돌
				if (!ballobj.BallMoveY && (BallBottom <= BrickTop) && (BallBottom - BrickTop ==0))
				{
					Brickobj.delete_bricks(index);
					ballobj.BallMoveY = !ballobj.BallMoveY;
					return true;
				}
			}

			// 좌우가 부딪치는 경우
			if ( BallTop == BrickTop && BallBottom == BrickBottom)
			{
				//왼쪽면 충돌
				if (ballobj.BallMoveX && (BallRight <= BrickLeft) && (BallRight -BrickLeft==0))
				{
					Brickobj.delete_bricks(index);
					ballobj.BallMoveX = !ballobj.BallMoveX;
					return true;
				}
				// 오른쪽면 충돌
				if (!ballobj.BallMoveX && (BallLeft >= BrickRight) && (BallLeft-BrickRight == 0 ))
				{
					Brickobj.delete_bricks(index);
					ballobj.BallMoveX = !ballobj.BallMoveX;
					return true;
				}
			}
		}
	}

	//충돌하지 않았을때
	return false;
	
}




//5.막대와 충돌판정 함수
bool Ball::f_BALL_Bar(Ball& ballobj, Bar& Barobj)
{
	if (!ballobj.InitBallMove)
	{
		return false;
	}

	// 공 방향이 위이면 리턴
	if (ballobj.BallMoveY)
	{
		return false;
	}
	int BallBottom = ballobj.BallY + R;
	int BallLeft = ballobj.BallX;
	int BallRight = ballobj.BallX + 2*R;
	
	int BarTop = Barobj.Get_Y();
	int BarBottom= Barobj.Get_Y()+BarHeight;
	int BarLeft = Barobj.Get_X();
	int BarRight = Barobj.Get_X()+Barobj.Get_Size(); //+레벨에 따른 길이;
	
	// 사각형 바와 원형 공의 충돌 처리
	// 높이
	if (BarTop >= BallBottom  && (BarTop-BallBottom==0))
	{
		// 좌우
		if (BallRight < BarLeft || BallLeft < BarRight)
		{
			ballobj.BallMoveY = !ballobj.BallMoveY;
			return true;
		}
	}

	//충돌하지 않았을때
	return false;
}




//6.벽과 충돌판정 함수
bool Ball::f_BALL_Board(Ball& ballobj)

{
	if (!ballobj.InitBallMove)
	{
		return false;
	}
		
	int BallTop = ballobj.BallY;
	int BallBottom = ballobj.BallY+R;
	int BallLeft = ballobj.BallX;
	int BallRight = ballobj.BallX + 2*R;

	int BoardLeft = 0;
	int BoardRight = 50;
	int BoardTop = 0;
	int BoardBottom = 25;

	// 왼쪽
	if (BallLeft == BoardLeft)
	{
		ballobj.BallX = BoardLeft; // 위치 지정
		ballobj.BallMoveX = !ballobj.BallMoveX;
		return true;
	}

	// 오른족
	if (BallRight == BoardRight)
	{
	
		ballobj.BallX = BoardRight - 2*R; // 위치 지정
		ballobj.BallMoveX = !ballobj.BallMoveX;
		return true;
	}

	// 위
	if (BallTop == BoardTop)
	{
		ballobj.BallY = BoardTop ; // 위치 지정
		ballobj.BallMoveY = !ballobj.BallMoveY;
		return true;
	}

	// 아래
	if (ballobj.BallY > 20)
	{
		InitBallMove = false;
	}

	//충돌하지 않았을때
	return false;
}

//Ball의 이동방향에 따라 이동시켜주는 함수 함수
void Ball::f_MoveBall(Ball& ballobj)
{

	if (ballobj.BallMoveX == false && ballobj.BallMoveY == true)
	{
		ballobj.Ball_Direct = Left_top;
	}
	else if (ballobj.BallMoveX == false && ballobj.BallMoveY == false)
	{
		ballobj.Ball_Direct = Left_down;
	}
	else if (ballobj.BallMoveX == true && ballobj.BallMoveY == true)
	{
		ballobj.Ball_Direct = Right_top;
	}
	else
		ballobj.Ball_Direct = Right_down;

	switch (ballobj.Ball_Direct)
	{
	case 0:
		ballobj.BallX -= 1;
		ballobj.BallY -= 1;
		break;
	case 1:
		ballobj.BallX -= 1;
		ballobj.BallY += 1;
		break;
	case 2:
		ballobj.BallX += 1;
		ballobj.BallY -= 1;
		break;
	case 3:
		ballobj.BallX += 1;
		ballobj.BallY += 1;
		break;
	}
}

//콘솔창에 Ball을 출력해주는 함수
void Ball::Render()
{
	gotoxy(BallX, BallY);
	cout << "◎";
}
bool Failed(const Ball& ballobj)
{
	if (ballobj.BallY> 20)
		return true;
	else
		return false;
}


