#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13) //ENTER key is pressed
			return Label;

		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO) {
			pO->PrintMessage(Label);
		}
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int x, int y, bool b) const
{
	if (b)
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CIRC: return DRAW_CIRC;
			case SELECT: return SELECT_SH;
			case CH_DRAW: return DRAW;
			case CH_FILL: return FILL;
			case C_BLACK: return BLACK1;
			case C_YELLOW:return YELLOW1;
			case C_ORANGE: return ORANGE1;
			case C_RED: return RED1;
			case C_GREEN: return GREEN1;
			case C_BLUE: return BLUE1;
			case DELETE_FIG: return DELETE_FIGURE;
			case MOVE_FIG: return MOVE;

			case CLEAR_ALL: return CLEAR;
			case START_REC: return START;
			
			
			case SAVE_GRAPH: return SAVE;
			case LOAD_GRAPH: return LOAD;
			case SWICH_TO_PLAY:return TO_PLAY;
			case ITM_EXIT: return EXIT;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case FIG_TYPE: return TYPE;
			case FIG_FILL_COLOR: return COLOR;
			case FIG_TYPE_FILL: return TYPE_FILL;
			case SWICH_TO_DRAW: return TO_DRAW;
			case PLAY_ITM_COUNT: return COUNT;
			case Exit: return EXIT;
			default: return EMPTY;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return STATUS;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
