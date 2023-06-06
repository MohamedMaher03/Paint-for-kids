#pragma once
#include "Action.h"
class colorgame :
    public Action
{

	Point p1;
	color Color;
	int win, lose;
	int correctcolornum;
	string colorname;
public:
	colorgame(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();



};

