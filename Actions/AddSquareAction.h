#pragma once
#include "Action.h"
class AddSquareAction : public Action
{
private:
	Point P1; //square center
	GfxInfo SquareGfxInfo;
public:

	virtual void UndoFun();
	virtual void Redo();
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
};

