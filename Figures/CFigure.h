#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<iostream>
using namespace std;

//Base class for all figures
class CFigure
{
protected:
	int ID;
	static int cnt;
	bool Selected;	//true if the figure is selected.
	bool clicked;   // to check the shape the child clicked on is removed.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
	
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	int getid()const;
	virtual string gettype()=0; //return string with figur name
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsClicked();           //check if the figure is chosed by kid in play mood
	void setclicked(bool b);
	color GetFillClr();             // get fill color of the shape

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void PrintDetails(Output* pOut) const = 0;				//print information of figures

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void makeselectedfalse();

	virtual bool CheckPointInsideFigure(int x, int y)=0; //check a given click inside a figure or not
	virtual Point GetCenter() = 0;   //return center of shapes
	virtual void Move(int diffx,int diffy)=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	string getColor(color c) const;
	color GetString(string s) const;
	virtual void Save(ofstream &file) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &FileIn) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif