#pragma once
#include "CFigure.h"
class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	bool CheckPointInsideFigure(int x, int y);
	void PrintDetails(Output* pOut) const;
	string gettype();
	Point GetCenter();
	void Move(int diffx, int diffy);
	virtual void Save(ofstream& file);	//Save the Square parameters to the file
	virtual void Load(ifstream& FileIn);
};

