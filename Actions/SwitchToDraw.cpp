#include "SwitchToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void SwitchToDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void SwitchToDraw::Execute()
{
	pManager->reset();
	Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces
	pOut->PrintMessage("Switch To Draw Mode");
	UI.InterfaceMode = MODE_DRAW;
	pOut->CreateDrawToolBar();
}
