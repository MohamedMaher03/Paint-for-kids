#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int length;
	int width;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	bool CheckPointInsideFigure(int x, int y);
	void PrintDetails(Output* pOut) const;
	string gettype();
	Point GetCenter();
	void Move(int diffx, int diffy);
	virtual void Save(ofstream& file) ;	//Save the Rect parameters to the file
	virtual void Load(ifstream &FileIn);
};

#endif