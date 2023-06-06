#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 56;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ToolBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.beginrec = true;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\triangule.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[CH_DRAW] = "images\\MenuItems\\ch_draw.jpg";
	MenuItemImages[CH_FILL] = "images\\MenuItems\\ch_fill.jpg";
	MenuItemImages[C_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[C_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[C_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[C_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[C_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[C_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[DELETE_FIG] = "images\\MenuItems\\delete_fig.jpg";
	MenuItemImages[MOVE_FIG] = "images\\MenuItems\\move_fig.jpg";
	
	MenuItemImages[CLEAR_ALL] = "images\\MenuItems\\delete_all.jpg";
	MenuItemImages[START_REC] = "images\\MenuItems\\start_rec.jpg";

	
	MenuItemImages[SAVE_GRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[LOAD_GRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[SWICH_TO_PLAY] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time

	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar()const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[FIG_TYPE] = "images\\MenuItems\\fig_type.jpg";
	MenuItemImages[FIG_FILL_COLOR] = "images\\MenuItems\\fig_fill_color.jpg";
	MenuItemImages[FIG_TYPE_FILL] = "images\\MenuItems\\fig_type_fill.jpg";
	MenuItemImages[SWICH_TO_DRAW] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[Exit] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output:: ChangeDrawColor(color color)  //change color of drawing 
{
	UI.DrawColor=color;
}
void Output::ChangeFillColor(color color)   //change color of fill
{
	UI.FillColor = color;
}

void Output::SetFilled(bool filled)
{
	UI.Filled = filled;
}
void Output::SetCrntFillColor(const color c)
{
	UI.FillColor = c;
}
bool Output::isFilled() const
{
	return UI.Filled;
}
color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() 	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected) const {
	const int width = 80;//let width be half of the diagonal length &let the size of width of square and hexagon = 75
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// p1 is the center of the square

	pWind->DrawRectangle(P1.x - width, P1.y - width, P1.x + width, P1.y + width, style);
}

void Output::DrawHexagon(Point P1, GfxInfo RectGfxInfo, bool selected) const {
	const int width = 80;//let width be half of the diagonal length &let the size of width of square and hexagon = 75

	int arrx[6] = { P1.x + width,P1.x + width / 2,P1.x - width / 2,P1.x - width,P1.x - width / 2,P1.x + width / 2 };
	int arry[6] = { P1.y,P1.y + width,P1.y + width,P1.y,P1.y - width,P1.y - width };



	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// p1 is the center of the hexagon


	pWind->DrawPolygon(arrx, arry, 6, style);

}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected)
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;



	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected)
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int dy, dx, d;
	dx = (P1.x - P2.x);
	dy = (P2.y - P1.y);
	int d2 = sqrt(dx * dx + dy * dy);
	pWind->DrawCircle(P1.x, P1.y, d2, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

