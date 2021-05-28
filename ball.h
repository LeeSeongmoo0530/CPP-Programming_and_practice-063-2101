#ifndef __BALL_H__
#define __BALL_H_
using namespace std;

#define R 1
#define BALLSPEED 1.0

//공의 이동방향
typedef enum _Direct	
{
	Left_top, Left_down, Right_top,Right_down
	//  0		  1			  2			3
}DIRECT;


//막대기의 높이
#define BarHeight 1


//블록의 가로길이
#define BrickWidth 2
#define BrickHeight 1


//f_BALL은 함수 Ball은 변수


class BALL
{
private:
	//공의 중점위치
	int BallX;
	int BallY;

	//공의 현재상태
	bool InitBallMove=false , BallMoveX=true, BallMoveY=true;	 //초기에 가만히있는 BALL 오른쪽, 위쪽 True
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






