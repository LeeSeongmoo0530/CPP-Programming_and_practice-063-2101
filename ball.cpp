#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include"ball.h"
#include"Screen.h"
using namespace std;



//������ ������ �� �ʱ���ġ�� �����ڷ� ����
BALL::BALL()
{
	BallX = 24;
	BallY = 19;
}	




//2.�ʱ�߻� ������ or��������
//ó���� InitBallȣ��
int BALL:: f_InitBALL()
{
	//spcaebar�� 
	kbhit();

	InitBallMove = true;

	srand((unsigned int)time(NULL));
	int Startdirect= rand() % 2;
	if (Startdirect == 1)
	{
		Ball_Direct = Right_top;
		return Ball_Direct;
	}
	
	//������
	else
	{
		Ball_Direct = Left_top;
		return Ball_Direct;
	}
}


//�ٸ� ��ü��� �浹�Ҷ� ȣ��Ǿ� ���� ������ �ٲ��ݴϴ�
//3.�̵������Լ�
int BALL::f_BALL_Direct(const BALL& b)
{
	// ���� �������� ������ ����
	if (!b.InitBallMove)
		return false;

	switch (b.Ball_Direct)
	{
		//���� ������ Left_top�̸� ���� ������ 
	case 0:
		Ball_Direct = Left_down;
		BallMoveX = false;
		BallMoveY = false;
		return Ball_Direct;
		//Left_down�̸�
	case 1:
		Ball_Direct = Left_top;
		BallMoveX = false;
		BallMoveY = true;
		return Ball_Direct;
		//Right_top�̸�
	case 2:
		Ball_Direct = Right_down;
		BallMoveX = true;
		BallMoveY = false;
		return Ball_Direct;
		//Right_down�̸�
	case 3:
		Ball_Direct = Right_top;
		BallMoveX = true;
		BallMoveY = true;
		return Ball_Direct;
	}
}


// �ڷ��� int���̰� BALL�� BAR�� Speed�� 1�̿��� ��ǥ���� �� =�� �־����ϴ�.
//4.������ �浹
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
	// Brick[]-XY��� 2���� �迭 ,  BrickNumX Y - X, Y ��ϰ��� 
	for (int y = 0; y < BrickNumY; y++)
	{
		for (int x = 0; x < BrickNumX; x++)
		{
			// ������ �׾��ִ� ��� ���� �������
			//Brick.on ����� ����ִ���
			if (!(Brick[y * BrickNumX + x].on))
			{
				continue;
			}

			BrickLeft = Brick[y * BrickNumX + x].X��ǥ-0.5*BrickWidth;
			BrickRight = BrickLeft + BrickWidth;
			//����� ������ǥ X
			BrickX = BrickLeft + 0.5 * BrickWidth;

			BrickTop = Brick[y * BrickNumX + x].Y��ǥ + 0.5*BrickHeight;
			BrickBottom = BrickTop -BrickHeight;
			//����� ������ǥ Y
			BrickY = BrickTop - 0.5*BrickHeight;


			// ���ϰ� �����ϰ� �浹 üũ

			// ���ϰ� �ε�ġ�� ���
			if (BallLeft > BrickLeft && BallRight < BrickRight)
			{
				// �Ʒ��� �浹
				if (BallMoveY && (BallTop > BrickBottom) && (BallTop - BrickBottom <=R)) 
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}

				// ���� �浹
				if (!BallMoveY && (BallBottom < BrickTop) && (BrickBottom - BallTop <= R))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
			}

			// �¿찡 �ε�ġ�� ���
			if ( BallTop == BrickTop && BallBottom == BrickBottom)
			{
				//���ʸ� �浹
				if (BallX && (BallRight < BrickLeft) && (BrickLeft - BallRight <= 0.5 * BrickWidth))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
				// �����ʸ� �浹
				if (BallX && (BallLeft > BrickRight) && (BrickRight - BallLeft <=  0.5 * BrickWidth))
				{
					Brick[y * BrickNumX + x].on = false;
					return f_BALL_Direct(ballobj);
				}
			}
		}
	}

	//�浹���� �ʾ�����
	return false;
	
}




//5.����� �浹
int BALL::f_BALL_Bar(BALL& ballobj)
{
	if (!InitBallMove)
	{
		return false;
	}

	// �� ������ ���̸� ����
	if (BallMoveY) return false;

	
	int BallBottom = BallY - R;
	int BallLeft = BallX - R;
	int BallRight = BallX + R;

	// �簢�� �ٿ� ���� ���� �浹 ó��
	// ����
	if (BallBottom >= BarTop && BallBottom <= BarBottom)
	{
		// �¿�
		if (BallRight > BarLeft && BallLeft < BarRight)
		{
			return f_BALL_Direct(ballobj);
		}
	}

	//�浹���� �ʾ�����
	return false;
}




//6.���� �浹
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

	// ����
	if (BallLeft <= BoardLeft)
	{
		BallX = BoardLeft + R; // ��ġ ����
		return f_BALL_Direct(ballobj);
	}

	// ������
	if (BallRight >= BoardRight)
	{
	
		BallX = BoardRight - R; // ��ġ ����
		return f_BALL_Direct(ballobj);
	}

	// ��
	if (BallTop >= BoardTop)
	{
		BallY = BoardTop + R; // ��ġ ����
		return f_BALL_Direct(ballobj);
	}

	// �Ʒ�
	if (BallBottom <= BoardBottom)
	{
		Failed(ballobj);
	}

	//�浹���� �ʾ�����
	return false;
}





//7.������ġ
//����,ó��ȭ��
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
	cout << "���� �ٴ����� ���������ϴ�. ";
}

//�Ҹ���, ������ġ������ ȣ��




void BALL::Render()
{
	gotoxy(BallX-R, BallY-R);
	cout << "��";
}