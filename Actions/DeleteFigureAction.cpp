#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void DeleteFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	fig = pManager->GetSelectedFig();

}

void DeleteFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	
	if (fig == NULL) {
		pOut->PrintMessage("There is no selected figure to delete");

	}
	else {
		pManager->DeleteSelectedFigure();
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pOut->PrintMessage("Selected figure deleted");
	}
	if (pManager->IsRecord())
		pManager->addrecord(this);
}