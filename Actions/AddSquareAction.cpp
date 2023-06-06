#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->AddUndoAction(this);
	UI.beginrec = false;
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	if (pOut->isFilled()) SquareGfxInfo.isFilled = true;
	else SquareGfxInfo.isFilled = false;

	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSquareAction::UndoFun()
{
	newAction = false;
	pManager->DeleteFigure();
}

void AddSquareAction::Redo()
{
	pManager->ReAddFigureUpdate();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	if (newAction)

		ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* C = new CSquare(P1, SquareGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(C);
	if (pManager->IsRecord())
		pManager->addrecord(this);
}
