#include "CTriangle.h"
#include <fstream>

float triangleArea(Point p1, Point p2, Point p3) {         //find area of triangle formed by p1, p2 and p3
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y-p2.y)) / 2.0);
}

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


CTriangle::CTriangle()
{
	
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

void CTriangle::PrintDetails(Output* pOut) const
{
	pOut->PrintMessage("Selected Triangle, ID: " + to_string(ID) + ", Corner1:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + "), Corner2:(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner3:(" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")");
}

bool   CTriangle::CheckPointInsideFigure(int x, int y) {
	Point checkpoint;
	checkpoint.x = x;
	checkpoint.y = y;
	float area  = triangleArea(Corner1,Corner2,Corner3); //calculate area of the main triangle
	float area1 = triangleArea(Corner1, Corner2, checkpoint); //calculate area of the first triangle
	float area2 = triangleArea(Corner1, checkpoint, Corner3); //calculate area of the second triangle
	float area3 = triangleArea(checkpoint, Corner2, Corner3); //calculate area of the third triangle
	if (area == area1 + area2 + area3) //point is inside or at triangle 
	{
		return true;
	}
	return false;
}

string  CTriangle::gettype() {
	string FigureName = "Triangle";
	return FigureName;
}
Point  CTriangle::GetCenter() {
	Point C;
	C.x = ((Corner1.x + Corner2.x+Corner3.x) / 3);
	C.y = ((Corner1.y + Corner2.y+Corner3.y) / 3);
	return C;
}
void  CTriangle::Move(int diffx, int diffy) {
	Corner1.x += diffx;
	Corner2.x += diffx;
	Corner3.x += diffx;
	Corner1.y += diffy;
	Corner2.y += diffy;
	Corner3.y += diffy;
}

void CTriangle::Save(ofstream& file)
{

	file <<"Triangle   "<< ID << "\t" << this->Corner1.x << "\t" << this->Corner1.y << "\t"<< this->Corner2.x << "\t" << this->Corner2.y << "\t"<< this->Corner3.x << "\t" << this->Corner3.y << "\t "
	<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		file << this->getColor(this->FigGfxInfo.FillClr) << "\n";
	else
		file << "NON-FILLED  " << "\n";

}

void CTriangle::Load(ifstream& FileIn)
{

	FileIn >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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