#include "CFood.h"
#include<iostream>

using namespace std;
CFood::CFood(int x, int y, char pic)//构造函数
{
	m_X = x;
	m_Y = y;
	m_Pic = pic;
}
CFood::~CFood()
{
}
void CFood::createPos()//生成食物
{
	srand((unsigned)time(NULL));//初始化随机数
	m_X = KLEFT+1+rand()%(KWIDTH-2);
	m_Y = KUP+3+rand()%(KHEIGHT-2);
}

//void CFood::createPos(int x,int y)//生成食物
//{
//	m_X = x;
//	m_Y = y;
//}