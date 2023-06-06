#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class ChangeDrawColorAction :public Action
{
private:
	color NewColor;
	int SelectedColorOrder;
	CFigure* SelectedFigure;

public:
	ChangeDrawColorAction(ApplicationManager* pApp);

	//Reads move parameters
	virtual void ReadActionParameters();
	virtual void UndoFun() {};
	virtual void Redo() {};

	virtual void Execute();
};

