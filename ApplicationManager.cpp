#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddHexagonAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SaveAction.h"
#include"Actions/LoadAction.h"
#include "Actions\ChangeDrawColorAction.h"
#include"Actions\ChangeFillColorAction.h"
#include"Actions\DeleteFigureAction.h"
#include"Actions/MoveAction.h"
#include"Actions/ExitAction.h"
#include"Actions/SwitchToDraw.h"
#include"Actions\SwitchToPlayMode.h"
#include "Actions\colorgame.h"
#include "Actions\type_colorgame.h"
#include "Actions\typegame.h"
#include "Actions\startrecord.h"
#include "Actions\stoprecord.h"
#include "Actions/Undo.h"
#include "Actions/RedoAction.h"
#include "ClearAction.h"
#include<string>
#include<fstream>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	SelectedCount = 0;
	RecCount = 0;
	CheckRecord = false;
	
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	


	undocount = 0;
	ActionCount = 0;

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexagonAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;
		case SELECT_SH:
			pAct = new SelectAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD :
			pAct = new LoadAction(this);
			break;
		case DRAW:
			pAct = new ChangeDrawColorAction(this);
			break;
		case FILL:
			pAct = new ChangeFillColorAction(this);
			break;
		case DELETE_FIGURE:
			pAct = new DeleteFigureAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDraw(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayMode(this);
			break;
		case TYPE:
			pAct = new typegame(this);
			break;
		case COLOR:
			pAct = new colorgame(this);
			break;
		case TYPE_FILL:
			pAct = new type_colorgame(this);
			break;
		case START:
			pAct = new startrecord(this);
			break;
		case CLEAR:
			pAct = new ClearAction(this);
			break;
		case STOP:
			pAct = new stoprecord(this);
			break;
		case EXIT:
			pAct = new ExitAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		default:
				break;
	}
	
	//Execute the created action
	
	if (pAct) {
		pAct->Execute();//Execute
		delete pAct;
	}
		
		
	

}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
	
}

void ApplicationManager::ClearFigures()
{
	for (int i = 0; i < FigCount; i++) {
		FigList[i] = NULL;
	}
	FigCount = 0;
}

 
void  ApplicationManager::Add_RemoveSelectedFigure(CFigure* Selected) {
	if (Selected == NULL) // if Cfigure point to null stop
	{
		return;
	}

	if (SelectedFig == NULL) //if no selected figures make selectedfig point directly
	{
		SelectedFig = Selected;
		SelectedFig->SetSelected(true);
		SelectedFig->PrintDetails(pOut);
		return;
	}
	

	if (SelectedFig->IsSelected()==true) //if figure is selected
	{
		if (SelectedFig->getid() == Selected->getid()) //check if figure user point at it same to figure selected before or not
		{
			SelectedFig->SetSelected(false);
			SelectedFig = NULL;
			pOut->PrintMessage("Figure is unselected , Now there is no selected figures");
		}
		else             //transfer selection from first to new figure 
		{
			SelectedFig->SetSelected(false);
			SelectedFig = Selected;
			SelectedFig->SetSelected(true);
			SelectedFig->PrintDetails(pOut);
		
		}
	}
	else 
	{	
		SelectedFig = Selected;
		SelectedFig->SetSelected(true);
		SelectedFig->PrintDetails(pOut);
	
	}

}

void  ApplicationManager:: DeleteSelectedFigure() {


	for (int i = 0;i < FigCount;i++) {
		if (SelectedFig != NULL) {
			if (SelectedFig->getid() == FigList[i]->getid())
			{
				FigList[i] = NULL;
				delete SelectedFig;
				SelectedFig = NULL;
				for (int j = i;j < FigCount - 1;j++)
				{
					FigList[j] = FigList[j + 1];
				}
				FigList[FigCount - 1] = NULL;
				FigCount--;
			}
		}
	}

	}


string ApplicationManager::randomtype()
{
	if (FigCount == 0)
		return"NULL";
	else
	{
		int randindex = rand() % FigCount;
		return FigList[randindex]->gettype();
	}

}



color ApplicationManager::randomcolor()
{
	if (FigCount == 0)
		return GOLD;
	else
	{
		int randindex = rand() % FigCount;
		return FigList[randindex]->GetFillClr();
	}
}

CFigure* ApplicationManager::getrandomfig()
{
	if (FigCount != 0)
	{
		int randindex = rand() % FigCount;
		return FigList[randindex];
	}
	else return NULL;
}



int ApplicationManager::gettypenum(string type)
{
	return FigCount;
}

int ApplicationManager::correcttypenum(string type)
{

	int num = 0;
	for (int i = 0; i < FigCount; i++)
		if ((FigList[i]->gettype() == type))
			num++;
	return num;
}



int ApplicationManager::correctcolornum(color m)
{
	int num = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetFillClr() == m)
			num++;
	return num;
}

int ApplicationManager::correcttype_colornum(string type, color m)
{
	int num = 0;
	for (int i = 0; i < FigCount; i++)
		if ((FigList[i]->GetFillClr() == m) && (FigList[i]->gettype() == type))
			num++;
	return num;
}


void ApplicationManager::reset()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->setclicked(false);
}

void ApplicationManager::addrecord(Action* last)
{
	if (RecCount < 20)
		record[RecCount++] = last;
}

bool ApplicationManager::IsRecord()
{
	return CheckRecord;
}


void ApplicationManager::setCheckRecord(bool b)
{
	CheckRecord = b;
}



void ApplicationManager::ChangeDrawingColor(color SelectedColor)
{
	SelectedFig->ChngDrawClr(SelectedColor);
}

void ApplicationManager::ChangeSelectedFillColor(color SelectedColor)
{
		SelectedFig->ChngFillClr(SelectedColor);
	
}


////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->CheckPointInsideFigure(x, y))
			return FigList[i];
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}



CFigure* ApplicationManager:: GetSelectedFig()const {
	return SelectedFig;
}
bool ApplicationManager:: IsThereSelectedFigure() {
	if (SelectedFig == NULL)
		return false;
	return true;
}
void  ApplicationManager:: MoveSelectedFigure(Point p, int diffx, int diffy) {
	
	Point Centerofselectedfig;
	Centerofselectedfig.x = 0;
	Centerofselectedfig.y = 0;
	for (int i = 0;i < FigCount;i++) {
		if (SelectedFig->getid() == FigList[i]->getid()) {
			Centerofselectedfig.x = FigList[i]->GetCenter().x;
			Centerofselectedfig.y = FigList[i]->GetCenter().y;
			diffx = p.x - Centerofselectedfig.x;
			diffy = p.y - Centerofselectedfig.y;
			FigList[i]->Move(diffx, diffy);
			break;
		}
	}
	
}

void ApplicationManager::SaveAll(ofstream& Out) 
{
	for (int i = 0;i < FigCount;i++)
	{
		FigList[i]->Save(Out);
	}

}
int  ApplicationManager::GetFigCount() const
{
	return FigCount;
}

void ApplicationManager::makeselectedfalse()
{
	for (int i = 0;i < FigCount;i++)
	{
		FigList[i]->makeselectedfalse();
	}

}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {
		if(!(FigList[i]->IsClicked()))
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

	}
}
void ApplicationManager::AddUndoAction(Action* pAct1)
{
	if (wasLastUndo == false) {
		if (ActionCount < MaxUndoActions)
		{
			pActList[ActionCount] = pAct1;
			ActionCount++;
		}
		else
		{
			delete pActList[0];
			for (int i = 0; i < MaxUndoActions - 1; i++)
			{
				pActList[i] = pActList[i + 1];
			}
			pActList[ActionCount - 1] = pAct1;
		}
	}
	else {

		for (int i = ActionCount; ActionCount - undocount < i; i--)
		{
			delete pActList[i - 1];
		}

		ActionCount = ActionCount - undocount + 1;
		undocount = 0;
		pActList[ActionCount - 1] = pAct1;

	}
}
void ApplicationManager::DeleteFigure()
{
	FigCount--;
	delete FigList[FigCount];
	FigList[FigCount] = NULL;
	pOut->ClearDrawArea();

	UpdateInterface();
}
void ApplicationManager::ReAddFigureUpdate()
{
	pActList[ActionCount - undocount - 1]->Execute();
	pOut->ClearDrawArea();
	UpdateInterface();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < RecCount; i++)
		delete record[i];
	delete pIn;
	delete pOut;
	
}
