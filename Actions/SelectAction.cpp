#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select Figure");
	// read the figure that user selected
	pIn->GetPointClicked(p1.x, p1.y);

}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure * Selectedshape =pManager->GetFigure(p1.x, p1.y);
	if (Selectedshape) //if selectedshape point to a shape not to NULL  
	{
		pManager->Add_RemoveSelectedFigure(Selectedshape);
	}
	else
	pOut->PrintMessage("There is no figure selected");
	if (pManager->IsRecord())
		pManager->addrecord(this);
}
