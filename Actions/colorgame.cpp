#include "colorgame.h"

#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>

colorgame::colorgame(ApplicationManager* pApp) :Action(pApp)
{
	void UpdateInterface();
	win = 0;
	lose = 0;


}

void colorgame::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->reset();
	pManager->UpdateInterface();
	win = 0;
	lose = 0;
	Color = pManager->randomcolor();
	
	if (Color==BLACK)
		pOut->PrintMessage("please choose all black figures");
	else if (Color == YELLOW)
		pOut->PrintMessage("please choose all yellow figures");
	else if (Color == BLUE)
		pOut->PrintMessage("please choose all blue figures");
	else if (Color == RED)
		pOut->PrintMessage("please choose all red figures");
	else if (Color == ORANGE)
		pOut->PrintMessage("please choose all orange figures");
	else if (Color == GREEN)
		pOut->PrintMessage("please choose all green figures");
	else
		pOut->PrintMessage("there is no fill figures");
	

}

void colorgame::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	
	correctcolornum = pManager->correctcolornum(Color);
	if (Color!=GOLD)
	{
		while (correctcolornum != win)
		{
			pIn->GetPointClicked(p1.x, p1.y);
			ActionType restart;
			restart = pIn->GetUserAction(p1.x, p1.y, false);

			CFigure* clicked = pManager->GetFigure(p1.x, p1.y);
			if (clicked == NULL && restart == COLOR)
				ReadActionParameters();
			else if (clicked == NULL && restart != COLOR || clicked->GetFillClr() == Color && clicked->IsClicked() == true)
				pOut->PrintMessage("NO new figure is choosed");

			else if (clicked->GetFillClr() == Color && clicked->IsClicked() == false)
			{
				win++;
				pOut->PrintMessage("correct");
				clicked->setclicked(true);

			}
			else
			{
				pOut->PrintMessage("incorrect");
				lose++;
			}
			pManager->UpdateInterface();


		}

		pOut->PrintMessage("number of correct =" + to_string(win) + "number of incorrect =" + to_string(lose));
	}
	}





