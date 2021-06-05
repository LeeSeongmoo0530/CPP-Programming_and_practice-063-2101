#pragma once
#ifndef __BAR_H_
#define __BAR_H_

class Bar 
{
private:
	int x;
	int y = 25;
	int size;
public:
	Bar(int level);

	int Get_X()const;
	int Get_Y() const;
	int Get_Size() const;
	void InitBar();

	void Render();
	void input();
};




#endif
