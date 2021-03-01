#include "CUnit.h"
#include<iostream>
#include<windows.h>
using namespace std;

CUnit::CUnit(int x,int y,char pic)//构造函数
{
	 m_X=x;
	 m_Y=y;
	 m_Pic=pic;
}
CUnit::~CUnit()//析构函数
{
}
void CUnit::show()//显示字符
{
	gotoxy(m_X,m_Y);
    cout<<m_Pic;
}
void CUnit::erase()//擦除字符
{
	gotoxy(m_X,m_Y);
	cout << " ";
}
void CUnit::gotoxy(int x, int y)//定位光标
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}