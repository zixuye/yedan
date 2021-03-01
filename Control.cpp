#include "Control.h"
#include "CUnit.h"
#include<iostream>

using namespace std;

Control::Control()
{

}


Control::~Control()
{
}

void Control::runGame()
{
	drawGameArea();
	drawGameInfo();
	
	f.createPos();
	f.show();
	
	s.showSnake();
	while (true)
	{
		s.move(&f);
	}
	f.gotoxy(50, 30);
}

void Control::drawGameArea()
{
	CUnit::gotoxy(CUnit::KLEFT, CUnit::KUP);
	for (int j = 0; j < CUnit::KWIDTH; j++)
	{
		cout << "-";
	}
	CUnit::gotoxy(CUnit::KLEFT, CUnit::KUP + CUnit::KHEIGHT + 1);
	for (int k = 0; k < CUnit::KWIDTH; k++)
	{
		cout << "-";
	}
	CUnit::gotoxy(CUnit::KLEFT + 1, CUnit::KUP + 2);
	for (int i = 0; i < CUnit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
	for (int i = 0; i < CUnit::KHEIGHT; i++)
	{
		CUnit::gotoxy(CUnit::KLEFT, CUnit::KUP + 1 + i);
		cout << "|";
		CUnit::gotoxy(CUnit::KLEFT + CUnit::KWIDTH - 1, CUnit::KUP + 1 + i);
		cout << "|";
	}



}

void Control::drawGameInfo()
{
	
	CUnit::gotoxy(CUnit::KLEFT + 1, CUnit::KUP + 1);

	cout << "游戏名称：贪吃蛇";

	CUnit::gotoxy(CUnit::KLEFT + 25, CUnit::KUP + 1);

	cout << "| 编写者：Niraya";

	CUnit::gotoxy(CUnit::KLEFT + 50, CUnit::KUP + 1);

	cout << "| 当前得分:  0";
}

