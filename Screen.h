#include<iostream>
#include<Windows.h>
#include<conio.h> // _getch()�Լ��� ����ϱ����� �������


using namespace std;


//���� 50 ���� 25 �׸��� �ϳ� ũŰ�� 2 X 1
//(0,0) ---------------------------> x
//	��
//	��
// 	��
// 	��
// 	��
// 	��
// 	��
// 	��
// 	�� 
//  �� 
// y 
 

//�ܼ�â���� Ŀ���� �Է��� x,y��ǥ�� ��ġ ��Ŵ
void gotoxy(int x, int y)
{
	COORD CurSorPosition = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurSorPosition);
}



//Board- ���ӿ��� �� ���� �׸��� �Լ�
void ScreenLine()
{
	gotoxy(0, 0);
	cout << "����������������������������������������������������������������������������������������������������";
	for (int i = 1; i < 25; i++)
	{
		gotoxy(0, i);
		cout << "��                                                ��";
	}

	gotoxy(0, 25);
	cout << "����������������������������������������������������������������������������������������������������";
}


//���� �ʱ�ȭ�� - ���̵��� �Է¹���
int InitScreen()
{

	gotoxy(2, 2);
	cout << "********************************************************************\n";
	cout << "                          �� �� �� �� �� ��                         \n";
	gotoxy(2, 4);
	cout << "********************************************************************\n";
	cout << endl << endl;
	cout << "                ���̵��� �����ϼ��� 1. ��   2. ��   3.��";
	int Level;
	while (1)
	{
		Level = _getch(); //ASCII �� ��ȯ
		if (Level > 48 && Level < 52)
		{
			break;
		}

	}
	return Level;

}


//���� ��� â - Board ���� ��� ��� ��
void ScoreScreen(int Level)
{


	gotoxy(5, 5);
	if (Level == '1')
	{
		cout << "���̵�  :  ��";
	}
	else if (Level == '2')
	{
		cout << "���̵�  :  ��";
	}
	else if (Level == '3')
	{
		cout << "���̵�  :  ��";
	}

	gotoxy(5, 7);
	//Brickobj.Score_print();
}


//�Ű����� �����ؼ� Render() �ϰ� goto�� �� Ŭ������ ��ǥ ����
void Render(int x , int y)
{
	gotoxy(x, y);
	cout << "��";  // �� -ó����ǥ(24,19)
	cout << "��";  // ����� - �̰� 3�� 5�� 7�� �ϸ� �� ó����ǥ 3���϶�-(22,20) 5���϶� - (20,20) 7���϶� - (18,20)
	cout << "��";  //���� ���� 20�� ���� 3��

}