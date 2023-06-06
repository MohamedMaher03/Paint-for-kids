#include "startrecord.h"
#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"
#include"stoprecord.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>

startrecord::startrecord(ApplicationManager* pApp):Action(pApp)
{
	
}

void startrecord::ReadActionParameters()
{
	
}

void startrecord::Execute()
{
	
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (UI.beginrec == true)
	{

		pOut->PrintMessage("start recording");
		pManager->setCheckRecord(true);
	}
	else
		pOut->PrintMessage("Error : please click on clear all icon first");

	
}
