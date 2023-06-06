#pragma once
#include "Action.h"
class AddHexagonAction :public Action
{
private:
	Point P1; //hexagon center
	GfxInfo HexagonGfxInfo;
public:

	virtual void UndoFun();
	virtual void Redo();
	AddHexagonAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
};

