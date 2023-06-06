#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp) 
{
	UI.beginrec = false;
}

void MoveAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();



}


void MoveAction::Execute() {
	Output* pOut = pManager->GetOutput();
	if (!(pManager->IsThereSelectedFigure())) {
		pOut->PrintMessage("There is no selected figure to move");
		return;
	}
	else {
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("Click at new point you want selected figure to move to it");

		//Read new point and store it in point P1
		pIn->GetPointClicked(P1.x, P1.y);
		pManager->MoveSelectedFigure(P1,diffX,diffY);
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pOut->PrintMessage("Figure moved to the new place");
	}
	if (pManager->IsRecord())
		pManager->addrecord(this);
}