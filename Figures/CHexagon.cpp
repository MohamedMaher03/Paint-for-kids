#include "CHexagon.h"
#include<fstream>



CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

CHexagon::CHexagon()
{
	
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a Hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

void CHexagon::PrintDetails(Output* pOut) const {
	pOut->PrintMessage("Selected Hexagon , Id is:" + to_string(ID) + " Center is:(" + to_string(Center.x) + "," + to_string(Center.y) + ") , the length of each side is:" + to_string(80));
}

bool  CHexagon::CheckPointInsideFigure(int x, int y) {
	bool checkx = false; //check if point between x1 and x2
	bool checky = false; //check if point between y1 and y2
	if (x >= Center.x - 80 && x <= Center.x + 80)
		checkx = true;
	if (y >= Center.y - 80 && y <= Center.y + 80)
		checky = true;
	if (checkx && checky) //return true if and only if two condition satisfied
		return true;
	else
		return false;
}

string CHexagon::gettype() {
	string FigureName = "Hexagon";
	return FigureName;
}
Point CHexagon::GetCenter() {

	return Center;
}
void  CHexagon::Move(int diffx, int diffy) {
	Center.x += diffx;
	Center.y += diffy;
}
void CHexagon::Save(ofstream& file)
{

	file << "Hexagon    " << ID << "\t" << this->Center.x << "\t" << this->Center.y << "\t"<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		file << this->getColor(this->FigGfxInfo.FillClr) << "\n ";
	else
		file << "NON-FILLED  " << "\n";
}
void CHexagon::Load(ifstream& FileIn)
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