#include "ChangeFillColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void ChangeFillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	SelectedFigure = pManager->GetSelectedFig();
	if (SelectedFigure == NULL)
	{
		pOut->PrintMessage("You Have To Select Figure first");
		return;
	}
	else
	{
		pOut->PrintMessage("Select Color to Change Drawing Color of Selected Figure");
	}

	SelectedColorOrder = pManager->GetUserAction();
	pOut->ClearStatusBar();
}

void ChangeFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if (SelectedFigure == NULL)
	{
		pOut->PrintMessage("You Have To Select Figure first");
		return;
	}
	if (SelectedColorOrder == BLACK1) {
		NewColor = BLACK;
		pOut->PrintMessage("Fill color changed to black");
	}
	else if (SelectedColorOrder == YELLOW1) {
		NewColor = YELLOW;
		pOut->PrintMessage("Fill color changed to yellow");
	}
	else if (SelectedColorOrder == ORANGE1) {
		NewColor = ORANGE;
		pOut->PrintMessage("Fill color changed to orange");
	}
	else if (SelectedColorOrder == RED1) {
		NewColor = RED;
		pOut->PrintMessage("Fill color changed to red");
	}
	else if (SelectedColorOrder == GREEN1) {
		NewColor = GREEN;
		pOut->PrintMessage("Fill color changed to green");
	}
	else if (SelectedColorOrder == BLUE1) {
		NewColor = BLUE;
		pOut->PrintMessage("Fill color changed to blue");
	}
	else {
		pOut->PrintMessage("No color has been selected");
	}
	if (SelectedFigure != NULL)
	{
	
		pManager->ChangeSelectedFillColor(NewColor);
		pOut->ChangeFillColor(NewColor);
		pOut->SetFilled(true);
		
	}
	if (pManager->IsRecord())
		pManager->addrecord(this);
	
}


