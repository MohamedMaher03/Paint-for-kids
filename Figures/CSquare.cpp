#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

CSquare::CSquare()
{
	
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a Square on the screen	
	pOut->DrawSquare(Center ,FigGfxInfo, Selected);
}

void CSquare::PrintDetails(Output* pOut) const{
	pOut->PrintMessage("Selected Square , Id is:" + to_string(ID) + " Center is:(" + to_string(Center.x) + "," + to_string(Center.y) + ") , the length of each side is:" + to_string(80));
}

bool CSquare::CheckPointInsideFigure(int x, int y) {
	bool checkx = false; //check if point between x1 and x2
	bool checky = false; //check if point between y1 and y2
	if (x >= Center.x-80 && x <= Center.x+80)
		checkx = true;
	if (y >= Center.y-80 && y <= Center.y+80)
		checky = true;
	if (checkx && checky) //return true if and only if two condition satisfied
		return true;
	else
		return false;

}


string CSquare::gettype() {
	string FigureName = "Square";
	return FigureName;
}
Point  CSquare::GetCenter() {

	return Center;
}
void CSquare::Move(int diffx, int diffy) {
	Center.x += diffx;
	Center.y += diffy;
}
void CSquare::Save(ofstream& file)
{

	file <<"Square     " << ID << "\t" << this->Center.x << "\t" << this->Center.y << "\t"<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		file << this->getColor(this->FigGfxInfo.FillClr) << "\n";
	else
		file << "NON-FILLED  " << "\n";

}
void CSquare::Load(ifstream& FileIn)
{

	FileIn >> ID >> Center.x >> Center.y ;
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