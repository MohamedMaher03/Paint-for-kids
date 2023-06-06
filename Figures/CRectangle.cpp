#include "CRectangle.h"
#include <Windows.h>
#include<MMsystem.h>
#include <fstream>



CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	length = P2.x - P1.x;
	width  = P2.y - P1.y;
}
	
CRectangle::CRectangle()
{

}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);

}

bool CRectangle:: CheckPointInsideFigure(int x,int y) {
	bool checkx = false; //check if point between x1 and x2
	bool checky = false; //check if point between y1 and y2
	if (x >= Corner1.x && x <= Corner2.x)
		checkx = true;
	if (y >= Corner1.y && y <= Corner2.y)
		checky = true;
	if (checkx && checky) //return true if and only if two condition satisfied
		return true;
	else
		return false;
}

void CRectangle::PrintDetails(Output* pOut) const {
	pOut->PrintMessage("Selected Rectangle , Id is:" + to_string(ID) + " Length is:" + to_string(length) + " Width is:" + to_string(width));
}

string  CRectangle::gettype() {
	string FigureName = "Rectangle";
	return FigureName;
}
Point  CRectangle::GetCenter() {
	Point C;
	C.x = ((Corner1.x + Corner2.x) / 2);
	C.y = ((Corner1.y + Corner2.y) / 2);
	return C;
}

void  CRectangle::Move(int diffx, int diffy) {
	Corner1.x += diffx;
	Corner2.x += diffx;
	Corner1.y += diffy;
	Corner2.y += diffy;
}

void CRectangle:: Save(ofstream& file)
{
	
	file << "Rectangle  "<< ID << "\t" << this->Corner1.x << "\t" << this->Corner1.y << "\t"<< this->Corner2.x << "\t" << this->Corner2.y << "\t"<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		file << this->getColor(this->FigGfxInfo.FillClr) << "\n ";
	else
		file << "NON-FILLED  " << "\n";
	
}
void CRectangle::Load(ifstream& FileIn)
{

	FileIn >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	string s;
	FileIn >> s;
	FigGfxInfo.DrawClr = GetString(s);
	FileIn >> s;
	if (s == "NON-FILLED")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = GetString(s);
		FigGfxInfo.isFilled = true;
	}
}


