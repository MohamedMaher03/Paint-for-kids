#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CTriangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<fstream>


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.beginrec = false;
}
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter file name");
	FileName = pIn->GetSrting(pOut); //get file name
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	string Type;
	int FigCount;
	string draw;
	string Fill;
	ReadActionParameters();
	

	ifstream FileIn;
	FileIn.open(FileName + ".txt");   //open file
	if (!FileIn.is_open())
	{
		pOut->PrintMessage("Load failed ,there is no graph with this file name");

	}
	else {
		pOut->ClearDrawArea();
		pManager->ClearFigures();



		FileIn >> draw;
		if (draw == "ORANGE")
			UI.DrawColor == ORANGE;
		else  if (draw == "RED")
			UI.DrawColor == RED;
		else if (draw == "WHITE")
			UI.DrawColor == WHITE;
		else if (draw == "BLACK")
			UI.DrawColor == BLACK;
		else if (draw == "BLUE")
			UI.DrawColor == BLUE;
		else if (draw == "GREEN")
			UI.DrawColor == GREEN;



		FileIn >> Fill;
		if (Fill == "ORANGE")
			UI.FillColor == ORANGE;
		else  if (Fill == "RED")
			UI.FillColor == RED;
		else if (Fill == "WHITE")
			UI.FillColor == WHITE;
		else if (Fill == "BLACK")
			UI.FillColor == BLACK;
		else if (Fill == "BLUE")
			UI.FillColor == BLUE;
		else if (Fill == "GREEN")
			UI.FillColor == GREEN;





		FileIn >> FigCount;
		CFigure* MyFig = NULL;
		for (int i = 0;i < FigCount;i++)
		{
			FileIn >> Type;
			if (Type == "Rectangle")
				MyFig = new CRectangle;
			else if (Type == "Circle")
				MyFig = new CCircle;
			else if (Type == "Hexagon")
				MyFig = new CHexagon;
			else if (Type == "Triangle")
				MyFig = new CTriangle;
			else if (Type == "Square")
				MyFig = new CSquare;


			MyFig->Load(FileIn);
			pManager->AddFigure(MyFig);

		}
		pManager->reset();
		pManager->makeselectedfalse();
		pManager->UpdateInterface();
		pOut->PrintMessage("Graph Loaded Successfully");


	}

	
}