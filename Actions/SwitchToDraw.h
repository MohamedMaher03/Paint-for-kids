#pragma once
#include "Action.h"
class SwitchToDraw :  public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();


	virtual void Execute();
};

