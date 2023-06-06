#pragma once
#include "Action.h"
class stoprecord :   public Action
{
private:
	
public:
	stoprecord(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();








};

