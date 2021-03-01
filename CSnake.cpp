#include "CSnake.h"
#include "CUnit.h"
#include "CFood.h"
#include<Windows.h>
#include<conio.h>
#include "Control.h"
#include <stdlib.h>


CSnake::CSnake(int x, int y , int length, Directions dir, int speed , char pic )
{
	m_HeadX= x;
    m_HeadY=y;
	m_Speed=speed;
	m_Length = length;
	m_Dir = dir;
	for (int i = 0; i < m_Length; i++)
	{
		CUnit myunit(0, 0, pic);
		m_Body.push_back(myunit);
		switch (dir)
		{
		case UP:
			m_Body[i].m_X = m_HeadX;
			m_Body[i].m_Y = m_HeadY+i;
			break;
		case DOWN:
			m_Body[i].m_X= m_HeadX;
			m_Body[i].m_Y= m_HeadY -i;
			break;
		case LEFT:
			m_Body[i].m_X= m_HeadX +i;
			m_Body[i].m_Y= m_HeadY;
			break;
		case RIGHT:
			m_Body[i].m_X= m_HeadX -i;
			m_Body[i].m_Y= m_HeadY;
			break;
		default:
			break;
		}
	}
}
CSnake::~CSnake()
{
}
void CSnake::changeDirection(int vkValue)//变换方向
{
	switch (vkValue)
	{
	case 72:
		if (m_Dir !=DOWN )
		{
			m_Dir = UP;
		}
		break;
	case 80:
		if (m_Dir != UP)
		{
			m_Dir = DOWN;
		}
		break;
	case 75:
		if (m_Dir != RIGHT)
		{
			m_Dir = LEFT;
		}
		break;
	case 77:
		if (m_Dir != LEFT)
		{
			m_Dir = RIGHT;
		}
		break;
	default:
		break;
	}
}
void CSnake::move(CFood *pFood)//移动
{
	showSnake();
	Sleep(m_Speed);
	eraseSnake();
	eatFood(pFood);
	if (_kbhit())//判断是否按下键
	{
		m_Dir = _getch();
		changeDirection(m_Dir);
	}
	die();
	
	for (int i = m_Length - 1; i > 0; i--)
	{
		m_Body[i].m_X = m_Body[i - 1].m_X;
		m_Body[i].m_Y = m_Body[i - 1].m_Y;
	}
	switch (m_Dir)
	{
	case UP:
		m_Body[0].m_Y--;
		break;
	case DOWN:
		m_Body[0].m_Y++;
		break;
	case LEFT:
		m_Body[0].m_X--;
		break;
	case RIGHT:
		m_Body[0].m_X++;
		break;
	default:
		break;
	}	
}
bool CSnake::eatFood(CFood *pFood)//吃食物
{
	if (m_Body[0].m_X == pFood->m_X 
		&& m_Body[0].m_Y == pFood->m_Y)
	{
		growup();
		score();
		pFood->gotoxy(65,3);
		cout << m_score<<endl;
		pFood->createPos();
		pFood->show();
		return true;
	}
	return false;
}
void CSnake::showSnake()//
{
	for (int i = 0; i < m_Length; i++)
	{
		m_Body[i].show();
	}
}
void CSnake::eraseSnake()//
{
	//m_Body.back().erase();
	for (int i = 0; i < m_Length; i++)
	{
		m_Body[i].erase();
	}
}
void CSnake::growup()
{
	CUnit MyUnit(0, 0, '#');
	m_Body.push_back(MyUnit);
	m_Length++;
}
void CSnake::die()
{
	for (int i = 2; i < m_Length; i++)//自残死
	{
		if (m_Body[0].m_X == m_Body[i].m_X&&m_Body[0].m_Y== m_Body[i].m_Y)
		{
			int ret = MessageBox(NULL, L"你咬到了自己！", L"游戏结束",0);
			cin.get();
		}
	}
	if(m_Body[0].m_X== CUnit::KLEFT
		||m_Body[0].m_X== CUnit::KLEFT + CUnit::KWIDTH -1
		||m_Body[0].m_Y==CUnit::KUP+2
		||m_Body[0].m_Y== CUnit::KUP+ CUnit::KHEIGHT+1)//碰壁死
	{
		int ret = MessageBox(NULL, L"撞到了墙壁！", L"游戏结束",0);
		cin.get();
	}
}
void CSnake::score()
{
	m_score++;
}
