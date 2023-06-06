#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxUndoActions = 5 };

private:
	int FigCount;		//Actual number of figures
	int SelectedCount;   //Actual number of selected
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int RecCount;       //Actual number of recorded actions 
	bool CheckRecord;  //check if I record or not
	Action* record[20]; // array to store the recorded actions (array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;


	//Actual number of actions 
	int undocount = 0;
	int ActionCount = 0;
	bool wasLastUndoRedo = false;
	bool wasLastUndo = false;
	Action* pActList[MaxUndoActions];


public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void makeselectedfalse();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList		
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFig()const;         //return selected figure 
	void Add_RemoveSelectedFigure(CFigure* Selected); //select or unselect a figure and store it in SelectedFig  
	void ChangeDrawingColor(color SelectedColor);
	void ChangeSelectedFillColor(color SelectedColor);
	void DeleteSelectedFigure();          //Delete The Selected Figure
	bool IsThereSelectedFigure();      //check there is selected figure or not
	void MoveSelectedFigure(Point p,int diffx,int diffy);         //move selected fig
	int GetFigCount() const; 
	void SaveAll(ofstream& Out);
	void reset();//reset the graph win kid wanted to restart the game or choose another game
	void addrecord(Action* last);
	bool IsRecord();
	
	void ClearFigures(); //clear figlist;
	void setCheckRecord(bool b);
	

	string randomtype();//chose random shape for play mode
	color randomcolor();//chose random color for play mode
	CFigure* getrandomfig();// get random figure
	int gettypenum(string type);// get number of shapes drawed
	int correcttypenum(string);//return number of correct shapes kid chooses
	int correctcolornum(color);//return number of correct colors kid chooses
	int correcttype_colornum(string type, color m);//return number of correct shapes and colors kid chooses
	
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void AddUndoAction(Action* pAct1);
	void DeleteFigure();          //Delete The  Figure
	void ReAddFigureUpdate(); //add figure after redo

};

#endif