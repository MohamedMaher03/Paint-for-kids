#pragma once
#include "Action.h"
class SwitchToPlayMode : public Action
{
public:
	SwitchToPlayMode(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();


	virtual void Execute();

};

