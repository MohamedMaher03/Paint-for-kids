#include "AddHexagonAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->AddUndoAction(this);
	UI.beginrec = false;
}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	HexagonGfxInfo.isFilled = false;	//default is not filled

	if (pOut->isFilled()) HexagonGfxInfo.isFilled = true;
	else HexagonGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexagonGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddHexagonAction::UndoFun()
{
	newAction = false;
	pManager->DeleteFigure();
}

void AddHexagonAction::Redo()
{
	pManager->ReAddFigureUpdate();

}

//Execute the action
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	if (newAction)
		ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexagonGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	if (pManager->IsRecord())
		pManager->addrecord(this);
}
