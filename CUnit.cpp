#include "CUnit.h"
#include<iostream>
#include<windows.h>
using namespace std;

CUnit::CUnit(int x,int y,char pic)//���캯��
{
	 m_X=x;
	 m_Y=y;
	 m_Pic=pic;
}
CUnit::~CUnit()//��������
{
}
void CUnit::show()//��ʾ�ַ�
{
	gotoxy(m_X,m_Y);
    cout<<m_Pic;
}
void CUnit::erase()//�����ַ�
{
	gotoxy(m_X,m_Y);
	cout << " ";
}
void CUnit::gotoxy(int x, int y)//��λ���
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;
	position.Y = y;
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);
}