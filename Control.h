#pragma once
#include <Windows.h>
#include "CSnake.h"
#include "CFood.h"
class Control
{
public:
	Control();
	~Control();
	void drawGameArea();
	void drawGameInfo();
	void runGame();
public:
	CFood f;
	/*CSnake* s=new CSnake;*/
	CSnake s;
};

