#include "SwitchToPlayMode.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void SwitchToPlayMode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void SwitchToPlayMode::Execute()
{

	Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces
	pOut->PrintMessage("Switch To Play Mode");
	UI.InterfaceMode = MODE_PLAY;
	pOut->CreatePlayToolBar();
}
