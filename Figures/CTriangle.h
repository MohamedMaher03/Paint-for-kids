#pragma once
#include "CFigure.h"
class CTriangle :public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;


public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	bool CheckPointInsideFigure(int x, int y);
	void PrintDetails(Output* pOut) const;
	string gettype();
	Point GetCenter();
	void Move(int diffx, int diffy);
	virtual void Save(ofstream& file) ;	//Save the tria parameters to the file
	virtual void Load(ifstream& FileIn);
};

