#pragma once
#include "Action.h"
class AddTriangleAction :public Action
{
private:
	Point P1, P2, P3; //Triangle_ Corners
	GfxInfo triGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);
	virtual void UndoFun();
	virtual void Redo();
	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
};

