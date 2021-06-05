#pragma once
#ifndef __BALL_H__
#define __BALL_H_
#include "Bar.h"
#include"Brick.h"
//공의 이동방향
#define Left_top 0
#define Left_down 1
#define Right_top 2
#define Right_down 3

class Ball
{
private:
	//공의 왼쪽위
	int BallX;
	int BallY;

	//공의 현재상태
	bool InitBallMove=false , BallMoveX=true, BallMoveY=true;	 //초기에 가만히있는 BALL , 오른쪽, 위쪽 True
	int Ball_Direct;
public:
	Ball();
	int f_Ball_Get_Direct() const;
	int f_Ball_Get_X() const;
	int f_Ball_Get_Y() const;
	void f_InitBALL();
	bool f_BALL_Brick (Ball& , Brick&);
	bool f_BALL_Bar(Ball&, Bar&);
	bool f_BALL_Board(Ball&);
	void f_MoveBall(Ball&);
	void Render();
	friend bool Failed(const Ball& ballobj);
};

#endif 






