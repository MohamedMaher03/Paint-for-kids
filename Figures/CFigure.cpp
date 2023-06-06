#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	ID = cnt++;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	clicked = false;
}
CFigure::CFigure()
{
	
}
int CFigure::cnt = 0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::makeselectedfalse() {
	Selected = false;
}

int CFigure::getid()const {
	return ID;
}

string CFigure::getColor(color c) const
{
	if (c == BLACK) return "BLACK";
	else if (c == WHITE) return "WHITE";
	else if (c == BLUE) return "BLUE";
	else if (c == RED) return "RED";
	else if (c == YELLOW) return "YELLOW";
	else if (c == GREEN) return "GREEN";
	else if (c == ORANGE) return "ORANGE";
	
	return "COLOR";
}
color CFigure::GetString(string s) const
{
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "ORANGE")
		return ORANGE;
}
bool CFigure::IsClicked()
{
	return clicked;
}



void CFigure::setclicked(bool b)
{
	clicked = b;
}


color CFigure::GetFillClr()
{
	if (FigGfxInfo.isFilled == true)
	{
		return FigGfxInfo.FillClr;
	}
	else return GOLD;

}



