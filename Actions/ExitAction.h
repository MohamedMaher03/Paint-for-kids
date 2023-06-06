#pragma once
#include "Action.h"
class ExitAction :
    public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();


	virtual void Execute();
};

