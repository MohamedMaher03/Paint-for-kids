#pragma once
#include "Actions/Action.h"
#include "..\PaintForKids\ApplicationManager.h"
#include "..\PaintForKids\GUI\Input.h"
#include "..\PaintForKids\GUI\Output.h"
class ClearAction :public Action
{
private:
	Point P1;// point that user click on draw area 
	int diffX; //distance moved in x direction
	int diffY; //distance moved in y direction
public:
	ClearAction::ClearAction(ApplicationManager* pApp) :Action(pApp)
	{
		UI.beginrec = true;
	}

	void ClearAction::ReadActionParameters() {
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();



	}


	void ClearAction::Execute() {
		Output* pOut = pManager->GetOutput();

			pManager->ClearFigures();
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			pOut->PrintMessage("figures cleared");
		
		if (pManager->IsRecord())
			pManager->addrecord(this);
	}
};

