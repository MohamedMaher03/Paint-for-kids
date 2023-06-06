#include "AddCircleAction.h"

#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
	pApp->AddUndoAction(this);
	UI.beginrec = false;
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point at distance = radius");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	if (pOut->isFilled()) CircGfxInfo.isFilled = true;
	else CircGfxInfo.isFilled = false;

	//get drawing, filling colors and pen width 
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = (pOut->getCrntPenWidth());

	pOut->ClearStatusBar();

}

void AddCircleAction::UndoFun()
{
	newAction = false;
	pManager->DeleteFigure();

}

void AddCircleAction::Redo()
{
	pManager->ReAddFigureUpdate();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	if (newAction)
		ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
	if (pManager->IsRecord())
		pManager->addrecord(this);
}
