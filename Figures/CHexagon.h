#pragma once
#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	bool CheckPointInsideFigure(int x, int y);
	void PrintDetails(Output* pOut) const;
	string gettype();
	Point GetCenter();
	void Move(int diffx, int diffy);
	virtual void Save(ofstream& file);	//Save the Hexagon parameters to the file
	virtual void Load(ifstream& FileIn);
};

