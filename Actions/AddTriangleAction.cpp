#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->AddUndoAction(this);
	UI.beginrec = false;
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3nd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	triGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	if (pOut->isFilled()) triGfxInfo.isFilled = true;
	else triGfxInfo.isFilled = false;

	triGfxInfo.DrawClr = pOut->getCrntDrawColor();
	triGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriangleAction::UndoFun()
{
	newAction = false;
	pManager->DeleteFigure();
}

void AddTriangleAction::Redo()
{
	pManager->ReAddFigureUpdate();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	if (newAction)

		ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, triGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
	if (pManager->IsRecord())
		pManager->addrecord(this);
}
