#pragma once
#include "CUnit.h"
#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

class CFood :public CUnit
{
public:
	CFood(int x = 0, int y = 0, char pic = '$');
	virtual ~CFood();
public:
	void createPos();
	/*void createPos(int x, int y);*/
};