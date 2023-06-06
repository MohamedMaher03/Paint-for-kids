#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->AddUndoAction(this);
	UI.beginrec = false;
}

void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	if (pOut->isFilled()) RectGfxInfo.isFilled = true;
	else RectGfxInfo.isFilled = false;

	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddRectAction::UndoFun()
{
	newAction = false;
	pManager->DeleteFigure();
}

void AddRectAction::Redo()
{
	pManager->ReAddFigureUpdate();

}

//Execute the action
void AddRectAction::Execute()
{
	//This action needs to read some parameters first
	if (newAction)

		ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);


	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	if (pManager->IsRecord())
		pManager->addrecord(this);

}
