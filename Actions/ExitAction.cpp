#include "ExitAction.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"SaveAction.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Do You want save before Exit? if yes please enter Yes");
	string s;
	s = pIn->GetSrting(pOut);
	if (s == "Yes")
	{
		ActionType pAct = SAVE;
		pManager->ExecuteAction(pAct);
	}
	else
	{
		pOut->PrintMessage("good bye");
	}
}