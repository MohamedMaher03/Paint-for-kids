#include "type_colorgame.h"

#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>

type_colorgame::type_colorgame(ApplicationManager* pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	win = 0;
	lose = 0;


}

void type_colorgame::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	win = 0;
	lose = 0;
	pManager->reset();
	pManager->UpdateInterface();
	CFigure* fig=NULL;
	
	fig = pManager->getrandomfig();
	if (fig != NULL)
	{
		type = fig->gettype();
		Color = fig->GetFillClr();
		colorname = fig->getColor(Color);
	}
	
	if (fig == NULL)
	{
		pOut->PrintMessage("NO figures");
		type ="NULL";
		colorname = "COLOR";
	}
	else if (colorname == "COLOR")
	{
		
		pOut->PrintMessage("there is no fill figures");
	}
	else
	{
	
		pOut->PrintMessage("Please Pick all " + fig->getColor(Color) +" " +type+"s");
	}

	


}

void type_colorgame::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	
	correcttype_colornum = pManager->correcttype_colornum(type,Color);
	if (type != "NULL" && colorname != "COLOR")
	{

		while (correcttype_colornum != win)
		{
			pIn->GetPointClicked(p1.x, p1.y);
			ActionType restart;
			restart = pIn->GetUserAction(p1.x, p1.y, false);

			CFigure* clicked = pManager->GetFigure(p1.x, p1.y);
			if (clicked == NULL && restart == TYPE_FILL)
				ReadActionParameters();
			else if (clicked == NULL && restart != TYPE_FILL || clicked->GetFillClr() == Color && clicked->gettype() == type && clicked->IsClicked() == true)
				pOut->PrintMessage("NO new figure is choosed");

			else if (clicked->GetFillClr() == Color && clicked->gettype() == type && clicked->IsClicked() == false)
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

