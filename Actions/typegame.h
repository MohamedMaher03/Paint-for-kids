#pragma once
#include "Action.h"

class typegame : public Action
{
private:
	Point p1;
	string type;
	int win, lose;
	int correcttypenum;
public:
	typegame(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	

};

