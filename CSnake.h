#pragma once
#include "CFood.h"
#include <conio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef enum{
	 UP,DOWN,LEFT,RIGHT
}Directions;

class CSnake
{
public:
	CSnake(int x = 40, int y = 10, int length = 4, Directions dir = RIGHT, int speed = 300, char pic = '#');
	virtual ~CSnake();
	void changeDirection(int vkValue);
	void move(CFood *pFood);
	bool eatFood(CFood *pFood);
	void score();
	void showSnake();//ªÊ÷∆…ﬂ…Ì
	void eraseSnake();
	void growup();
	void die();

public:
	int m_Length;
	int m_HeadX;
	int m_HeadY;
	int m_Speed;
	int m_cPic;
	int m_Dir;
	int m_score=0;
	vector<CUnit>m_Body;
};

