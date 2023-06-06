#include "CCircle.h"
#include<cmath>
#include<string>
#include<fstream>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
	radlen= sqrt(pow((Center.x - Radius.x), 2) + pow((Center.y - Radius.y), 2));
}

CCircle::CCircle()
{
	
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Radius, FigGfxInfo, Selected);
}

void  CCircle:: PrintDetails(Output* pOut) const {
	pOut->PrintMessage("Selected Circle , Id is:" + to_string(ID) + " Center is:(" + to_string(Center.x) + "," + to_string(Center.y) + ") , Radius is:" + to_string(radlen));
}

bool  CCircle::CheckPointInsideFigure(int x, int y) {
	//calculate raduis of passed point and compare it with exist radius
	float checkrad2 = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (checkrad2 <= radlen)
		return true;
	return false;
}

string  CCircle::gettype() {
	string FigureName = "Circle";
	return FigureName;
}
Point  CCircle:: GetCenter() {
	return Center;
}
void CCircle::Move(int diffx, int diffy) {
	Center.x += diffx;
	Radius.x += diffx;
	Center.y += diffy;
	Radius.y += diffy;
}
void CCircle::Save(ofstream& file)
{

	file << "Circle     " << ID << "\t" << this->Center.x << "\t" << this->Radius.x << "\t"<<
		this->Center.y << "\t" << this->Radius.y << "\t"<< 
		this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	
	if (this->FigGfxInfo.isFilled)
		file << this->getColor(this->FigGfxInfo.FillClr) << " \n ";
	else
		file << "NON-FILLED  " << "\n";
}
void CCircle::Load(ifstream& FileIn)
{

	FileIn >> ID >> Center.x >> Radius.x >> Center.y >> Radius.y;
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