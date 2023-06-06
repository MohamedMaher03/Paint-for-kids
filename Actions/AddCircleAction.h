#pragma once
#include "Action.h"
class AddCircleAction :  public Action
{
private:
	Point P1, P2; //circle points
	GfxInfo CircGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	virtual void UndoFun();
	virtual void Redo();
	//Add circle to the ApplicationManager
	virtual void Execute();
};

