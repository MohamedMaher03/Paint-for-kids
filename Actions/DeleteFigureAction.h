#pragma once
#include "Action.h"
#include "../Figures/CFigure.h";
class DeleteFigureAction :public Action
{
private:
	CFigure* fig;
public:
	DeleteFigureAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();


	virtual void Execute();
};

