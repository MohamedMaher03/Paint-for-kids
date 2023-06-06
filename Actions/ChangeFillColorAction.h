#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class ChangeFillColorAction : public Action
{
private:
	color NewColor;
	int SelectedColorOrder;
	CFigure* SelectedFigure;
	bool IsSelected ;

public:
	ChangeFillColorAction(ApplicationManager* pApp);

	//Reads move parameters
	virtual void ReadActionParameters();


	virtual void Execute();
};
