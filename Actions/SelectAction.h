#pragma once
#include "Action.h"
class SelectAction :public Action
{
private:
	Point p1;// point that user click on draw area 
public:
	SelectAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	
	virtual void Execute();
};

