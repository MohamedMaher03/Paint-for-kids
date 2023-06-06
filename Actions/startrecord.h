#pragma once
#include "Action.h"

class startrecord :
    public Action
{
private:


public:
	startrecord(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();



};

