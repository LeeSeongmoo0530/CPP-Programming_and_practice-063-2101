#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include"ball.h"
#include"Screen.h"
using namespace std;



//게임을 실행할 때 초기위치를 생성자로 설정
BALL::BALL()
{
	BallX = 24;
	BallY = 19;
}	




//2.초기발사 왼쪽위 or오른쪽위
//처음에 InitBall호출
int BALL:: f_InitBALL()
{
	//spcaebar로 
	kbhit();

	InitBallMove = true;

	srand((unsigned int)time(NULL));
	int Startdirect= rand() % 2;
	if (Startdirect == 1)
	{
		Ball_Direct = Right_top;
		return Ball_Direct;
	}
	
	//왼쪽위
	else
	{
		Ball_Direct = Left_top;
		return Ball_Direct;
	}
}


//다른 객체들과 충돌할때 호출되어 공의 방향을 바꿔줍니다
//3.이동방향함수
int BALL::f_BALL_Direct(const BALL& b)
{
	// 공임 움직이지 않으면 리턴
	if (!b.InitBallMove)
		return false;

	switch (b.Ball_Direct)
	{
		//공의 방향이 Left_top이면 공의 방향을 
	case 0:
		Ball_Direct = Left_down;
		BallMoveX = false;
		BallMoveY = false;
		return Ball_Direct;
		//Left_down이면
	case 1:
		Ball_Direct = Left_top;
		BallMoveX = false;
		BallMoveY = true;
		return Ball_Direct;
		//Right_top이면
	case 2:
		Ball_Direct = Right_down;
		BallMoveX = true;
		BallMoveY = false;
		return Ball_Direct;
		//Right_down이면
	case 3:
		Ball_Direct = Right_top;
		BallMoveX = true;
		BallMoveY = true;
		return Ball_Direct;
	}
}


// 자료형 int형이고 BALL과 BAR의 Speed가 1이여서 좌표비교할 때 =을 넣었습니다.
//4.벽돌과 충돌
int BALL::f_BALL_Brick(BALL& ballobj)
{
	if (!InitBallMove) 
		return false;

	int BallTop = BallY + R;
	int BallBottom = BallY - R;
	int BallLeft = BallX - R;
	int BallRight = BallX + R;

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
			if (!(Brick[y * BrickNumX + x].on))
			{
				continue;
			}

			BrickLeft = Brick[y * BrickNumX + x].X좌표-0.5*BrickWidth;
			BrickRight = BrickLeft + BrickWidth;
			//블록의 중점좌표 X
			BrickX = BrickLeft + 0.5 * BrickWidth;

			BrickTop = Brick[y * BrickNumX + x].Y좌표 + 0.5*BrickHeight;
			BrickBottom = BrickTop -BrickHeight;
			//블록의 중점좌표 Y
			BrickY = BrickTop - 0.5*BrickHeight;


			// 공하고 벽돌하고 충돌 체크

			// 상하가 부딪치는 경우
			if (BallLeft > BrickLeft && BallRight < BrickRight)
			{
				// 아랫면 충돌
				if (BallMoveY && (BallTop > BrickBottom) && (BallTop - BrickBottom <=R)) 
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}

				// 윗면 충돌
				if (!BallMoveY && (BallBottom < BrickTop) && (BrickBottom - BallTop <= R))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
			}

			// 좌우가 부딪치는 경우
			if ( BallTop == BrickTop && BallBottom == BrickBottom)
			{
				//왼쪽면 충돌
				if (BallX && (BallRight < BrickLeft) && (BrickLeft - BallRight <= 0.5 * BrickWidth))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
				// 오른쪽면 충돌
				if (BallX && (BallLeft > BrickRight) && (BrickRight - BallLeft <=  0.5 * BrickWidth))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
			}
		}
	}

	//충돌하지 않았을때
	return false;
	
}




//5.막대와 충돌
int BALL::f_BALL_Bar(BALL& ballobj)
{
	if (!InitBallMove)
	{
		return false;
	}

	// 공 방향이 위이면 리턴
	if (BallMoveY) return false;

	
	int BallBottom = BallY - R;
	int BallLeft = BallX - R;
	int BallRight = BallX + R;

	// 사각형 바와 원형 공의 충돌 처리
	// 높이
	if (BallBottom >= BarTop && BallBottom <= BarBottom)
	{
		// 좌우
		if (BallRight > BarLeft && BallLeft < BarRight)
		{
			return f_BALL_Direct(ballobj);
		}
	}

	//충돌하지 않았을때
	return false;
}




//6.벽과 충돌
int BALL::f_BALL_Board(BALL& ballobj)

{
	if (!InitBallMove)
	{
		return false;
	}
		
	int BallTop = BallY - R;
	int BallBottom = BallY + R;
	int BallLeft = BallX - R;
	int BallRight = BallX + R;

	int BoardLeft = 0;
	int BoardRight = 50;
	int BoardTop = 0;
	int BoardBottom = 25;

	// 왼쪽
	if (BallLeft <= BoardLeft)
	{
		BallX = BoardLeft + R; // 위치 지정
		return f_BALL_Direct(ballobj);
	}

	// 오른족
	if (BallRight >= BoardRight)
	{
	
		BallX = BoardRight - R; // 위치 지정
		return f_BALL_Direct(ballobj);
	}

	// 위
	if (BallTop >= BoardTop)
	{
		BallY = BoardTop + R; // 위치 지정
		return f_BALL_Direct(ballobj);
	}

	// 아래
	if (BallBottom <= BoardBottom)
	{
		Failed(ballobj);
	}

	//충돌하지 않았을때
	return false;
}





//7.실패위치
//리셋,처음화면
bool BALL::f_FailedPos() const
{

	if (BallY >= 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}


BALL::~BALL()
{
	cout << "공이 바닥으로 떨어졌습니다. ";
}

//소멸자, 실패위치에가면 호출




void BALL::Render()
{
	gotoxy(BallX-R, BallY-R);
	cout << "◎";
}