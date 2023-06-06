#include "SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<fstream>
#include<ostream>


SaveAction::SaveAction(ApplicationManager* pApp ) :Action(pApp)
{
	FileName = "MyFile";
	UI.beginrec = false;
	
}
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please write file name");
	FileName = pIn->GetSrting(pOut); //read file name
}
void SaveAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	ofstream file; //file object of ofstram
	file.open(FileName + ".txt");//create file and name it
	if (file)
	{
		pOut->PrintMessage("file saved");
		if (UI.DrawColor == ORANGE)
			file << "ORANGE" <<"     ";
		else if (UI.DrawColor == RED)
			file << "Red" << "     ";
		else if (UI.DrawColor == BLACK)
			file << "BLACK" << "     ";
		else if (UI.DrawColor == GREEN)
			file << "GREEN" << "     ";
		else if (UI.DrawColor == BLUE)
			file << "BLUE" << "     ";
		else if (UI.DrawColor == YELLOW)
			file << "YELLOW" << "     ";
		
		if (UI.FillColor == ORANGE)
			file << "ORANGE" << endl;
		else if (UI.FillColor == RED)
			file << "Red" << endl;
		else if (UI.FillColor == BLACK)
			file << "BLACK" << endl;
		else if (UI.FillColor == GREEN)
			file << "GREEN" << endl;
		else if (UI.FillColor == BLUE)
			file << "BLUE" << endl;
		else if (UI.FillColor == YELLOW)
			file << "YELLOW" << endl;
		 
		file << pManager->GetFigCount() << endl;
		pManager->SaveAll(file);
		file.close();

	}
	

	
	
}
