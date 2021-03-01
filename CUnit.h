#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;

class CUnit
{
public:
	CUnit(int x =10, int y = 5, char pic = '@');
	virtual ~CUnit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	int m_X;
	int m_Y;
	char m_Pic;
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH =80;
	const static int KHEIGHT =20;
};

