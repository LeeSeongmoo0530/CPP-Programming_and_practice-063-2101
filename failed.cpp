#include<iostream>
#include "ball.h"



//���������Լ�
bool Failed(BALL& b)
{
	if (b.f_FailedPos())
	{
		gotoxy(5, 5);
		cout << "���� �ٴ����� ���������ϴ�. \n";
		cout << "\t1.�絵��\n\t2.ó��ȭ������ ���ư���\n\t3.��������" << endl;
		int option;
		while (1)
		{
			cin >> option;
			if (option == 1 || option == 2)
			{
				Reset(option);
				//option���� ó���̳� �絵���̳� 
				//�絵���Լ�
				break;
			}
			if(option == 3)
			{
				exit(0);
			}
			else
			{
				cout << "�ٽ� �������ּ���" << endl;
				continue;
			}
		}
		//���а� �ƴϹǷ�
		return false;
	}



