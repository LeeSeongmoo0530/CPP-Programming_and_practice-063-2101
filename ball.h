#ifndef __BALL_H__
#define __BALL_H_
using namespace std;

#define R 1
#define BALLSPEED 1.0

//���� �̵�����
typedef enum _Direct	
{
	Left_top, Left_down, Right_top,Right_down
	//  0		  1			  2			3
}DIRECT;


//������� ����
#define BarHeight 1


//����� ���α���
#define BrickWidth 2
#define BrickHeight 1


//f_BALL�� �Լ� Ball�� ����


class BALL
{
private:
	//���� ������ġ
	int BallX;
	int BallY;

	//���� �������
	bool InitBallMove=false , BallMoveX=true, BallMoveY=true;	 //�ʱ⿡ �������ִ� BALL ������, ���� True
	DIRECT Ball_Direct;

public:
	BALL();	

	int f_InitBALL();
	int f_BALL_Direct(const BALL& b);
	int f_BALL_Brick(BALL& ballobj);
	int f_BALL_Bar(BALL& ballobj);
	int f_BALL_Board(BALL& ballobj);
	bool f_FailedPos() const;

	void Render();
	~BALL();
};

#endif 






