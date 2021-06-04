#ifndef __BALL_H__
#define __BALL_H_
#include"Bar.h"
#include"Brick.h"
using namespace std;



//공의 이동방향
typedef enum _Direct	
{
	Left_top, Left_down, Right_top,Right_down
	//  0		  1			  2			3
}DIRECT;

class Ball
{
private:
	//공의 왼쪽위
	int BallX;
	int BallY;

	//공의 현재상태
	bool InitBallMove=false , BallMoveX=true, BallMoveY=true;	 //초기에 가만히있는 BALL 오른쪽, 위쪽 True
	DIRECT Ball_Direct;

public:
	int f_Ball_Get_Direct() const;
	int f_Ball_Get_X() const;
	int f_Ball_Get_Y() const;
	void f_InitBALL();
	int f_BALL_Direct();
	int f_BALL_Brick (Brick& );
	int f_BALL_Bar(Bar& );
	int f_BALL_Board(Ball&);
	void f_MoveBall();
	void f_Ball_Render();
	friend bool Failed(const Ball&);
};

bool Failed(const Ball& ballobj)
{
	if (ballobj.BallY<=20)
		return true;
	else
		return false;
}


#endif 






