#pragma once
#include "CFigure.h"
class CCircle :public CFigure
{
private:
	Point Center;
	Point Radius;
	float radlen;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool CheckPointInsideFigure(int x, int y);
	void PrintDetails(Output* pOut) const;
	string gettype();
	Point GetCenter();
	void Move(int diffx, int diffy);
	virtual void Save(ofstream& file);	//Save the Circle parameters to the file
	virtual void Load(ifstream& FileIn);
};

