#include "typegame.h"
#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>

typegame::typegame(ApplicationManager* pApp) :Action(pApp)
{
	
	void UpdateInterface();
	win = 0;
	lose = 0;


}

void typegame::ReadActionParameters()
{
	pManager->reset();
	win = 0;
	lose = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->UpdateInterface();
	type = pManager->randomtype();
	if (type != "NULL")
		pOut->PrintMessage("please pick all " + type + "s");
	else
		pOut->PrintMessage("NO figures");

}

void typegame::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (type != "NULL") {
		correcttypenum = pManager->correcttypenum(type);
		while (correcttypenum != win)
		{
			pIn->GetPointClicked(p1.x, p1.y);
			ActionType restart;
			restart = pIn->GetUserAction(p1.x,p1.y,false);
			
			CFigure* clicked = pManager->GetFigure(p1.x, p1.y);
			if (clicked == NULL && restart == TYPE)
				ReadActionParameters();
			else if (clicked == NULL && restart != TYPE || clicked->gettype() == type && clicked->IsClicked() == true)
				pOut->PrintMessage("NO new figure is choosed");
			 
			else if (clicked->gettype() == type&& clicked->IsClicked()==false)
			{
				win++;
				pOut->PrintMessage("correct");
				clicked->setclicked(true);

			}
			else 
			{
				pOut->PrintMessage("incorrect :please pick all " + type + "s");
				lose++;
			}
			pManager->UpdateInterface();


		}
		pOut->PrintMessage("number of correct =" + to_string(win) + "number of incorrect =" + to_string(lose));

	}



}