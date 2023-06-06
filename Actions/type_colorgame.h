#pragma once
#include "Action.h"
class type_colorgame :  public Action
{

	Point p1;
	color Color;
	string type;
	string colorname;
	int win, lose;
	int correcttype_colornum;
public:
	type_colorgame(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

