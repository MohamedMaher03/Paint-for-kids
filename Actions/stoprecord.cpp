#include "stoprecord.h"
#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>

stoprecord::stoprecord(ApplicationManager* pApp):Action(pApp)
{
	
	UI.beginrec = false;
		
}

void stoprecord::ReadActionParameters()
{
}

void stoprecord::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("stop recording");
	pManager->setCheckRecord(false);
}
