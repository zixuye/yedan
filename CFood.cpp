#include "CFood.h"
#include<iostream>

using namespace std;
CFood::CFood(int x, int y, char pic)//���캯��
{
	m_X = x;
	m_Y = y;
	m_Pic = pic;
}
CFood::~CFood()
{
}
void CFood::createPos()//����ʳ��
{
	srand((unsigned)time(NULL));//��ʼ�������
	m_X = KLEFT+1+rand()%(KWIDTH-2);
	m_Y = KUP+3+rand()%(KHEIGHT-2);
}

//void CFood::createPos(int x,int y)//����ʳ��
//{
//	m_X = x;
//	m_Y = y;
//}