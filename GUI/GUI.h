#pragma once

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <iostream>


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	COLOR_PICK_MODE CMode;
	GUI()
	{
		//Initialize user interface parameters
		UI.InterfaceMode = MODE_DRAW;

		UI.width = 1285;
		UI.height = 700;
		UI.wx = 5;
		UI.wy = 5;


		UI.StatusBarHeight = 50;
		UI.ToolBarHeight = 50;
		UI.MenuItemWidth = 80;

		UI.DrawColor = NAVY;	//Drawing color
		UI.FillColor = NULL;	//Filling color
		UI.MsgColor = RED;		//Messages color
		UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
		UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
		UI.StatusBarColor = TURQUOISE;
		UI.PenWidth = 3;	//width of the figures frames

		//Create the output window
		pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
		//Change the title
		pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

		CreateDrawToolBar();
		CreateStatusBar();

	}
	void GetPointClicked(int& x, int& y) const
	{
		pWind->WaitMouseClick(x, y);	//Wait for mouse click
	}

	string GetString(GUI* pO) const
	{
		string Label;
		char Key;
		while (1)
		{
			pWind->WaitKeyPress(Key);
			if (Key == 27)	//ESCAPE key is pressed
				return "";	//returns nothing as user has cancelled label
			if (Key == 13)	//ENTER key is pressed
				return Label;
			if (Key == 8)	//BackSpace is pressed
				Label.resize(Label.size() - 1);
			else
				Label += Key;
			if (pO)
				pO->PrintMessage(Label);
		}
	}

	//This function reads the position where the user clicks to determine the desired action
	ActionType	MapInputToActionType() const
	{
		int x, y;
		pWind->WaitMouseClick(x, y);

		if (UI.InterfaceMode == MODE_DRAW)
		{
			if (pointInsideToolBar(y))
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				switch (ClickedItemOrder)
				{
					case MAIN_MENU_SQUARE: return ACTION_DRAW_SQUARE;
					case MAIN_MENU_ELLIPSE: return ACTION_DRAW_ELLIPSE;
					case MAIN_MENU_HEXAGON: return ACTION_DRAW_HEXAGON;
					case MAIN_MENU_SELECT: return ACTION_SELECT;
					case MAIN_MENU_CHG_BG: return ACTION_CHNG_BG_CLR;
					case MAIN_MENU_CHG_DRAW: return ACTION_CHNG_DRAW_CLR;
					case MAIN_MENU_CHG_FILL: return ACTION_CHNG_FILL_CLR;
					case MAIN_MENU_RESIZE: return ACTION_RESIZE;
					case MAIN_MENU_DELETE: return ACTION_DELETE;
					case MAIN_MENU_SEND_BACK: return ACTION_SEND_BACK;
					case MAIN_MENU_BRING_FRONT: return ACTION_BRNG_FRNT;

					case MAIN_MENU_PLAY: return ACTION_TO_PLAY;

					case MAIN_MENU_SAVE: return ACTION_SAVE;
					case MAIN_MENU_LOAD: return ACTION_LOAD;
					case MAIN_MENU_EXIT: return EXIT;

					default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}
			//[3] User clicks on the status bar
			return STATUS;
		}else if (UI.InterfaceMode == MODE_PICK_COLOR) {
			if (pointInsideToolBar(y))
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				switch (ClickedItemOrder)
				{
				case COLOR_BLACK: return ACTION_BLACK;
				case COLOR_RED: return ACTION_RED;
				case COLOR_YELLOW: return ACTION_YELLOW;
				case COLOR_GREEN: return ACTION_GREEN;
				case COLOR_NAVY: return ACTION_NAVY;
				case COLOR_DEEPPINK: return ACTION_DEEPPINK;
				case COLOR_GRAY: return ACTION_GRAY;
				case COLOR_DEEPORANGE: return ACTION_DEEPORANGE;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}
			//[3] User clicks on the status bar
			return STATUS;
			
		}else if (UI.InterfaceMode == MODE_RESIZE) {
			if (pointInsideToolBar(y))
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				switch (ClickedItemOrder)
				{
				case RESIZE_QUARTAR: return ACTION_QUARTAR;
				case RESIZE_HALF: return ACTION_HALF;
				case RESIZE_DOUBLE: return ACTION_DOUBLE;
				case RESIZE_2DOUBLE: return ACTION_2DOUBLE;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}
			//[3] User clicks on the status bar
			return STATUS;
		}else{
			if (pointInsideToolBar(y))
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				switch (ClickedItemOrder)
				{
				case PLAY_TYPE: return ACTION_PLAY_TYPE;
				case PLAY_FILL: return ACTION_PLAY_FILL;
				case PLAY_TYPEFILL: return ACTION_PLAY_TYPEFILL;
				case PLAY_RESET: return ACTION_PLAY_RESET;
				case PLAY_BACK: return ACTION_TO_DRAW;

				default: return EMPTY;	//A click on empty place in desgin toolbar
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

	}
	//======================================================================================//
	//								Output Functions										//
	//======================================================================================//

	window* CreateWind(int w, int h, int x, int y) const
	{
		window* pW = new window(w, h, x, y);
		pW->SetBrush(UI.BkGrndColor);
		pW->SetPen(UI.BkGrndColor, 1);
		pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
		return pW;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void CreateStatusBar() const
	{
		pWind->SetPen(UI.StatusBarColor, 1);
		pWind->SetBrush(UI.StatusBarColor);
		pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void ClearStatusBar() const
	{
		//Clear Status bar by drawing a filled white Square
		pWind->SetPen(UI.StatusBarColor, 1);
		pWind->SetBrush(UI.StatusBarColor);
		pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void CreateDrawToolBar() const
	{
		UI.InterfaceMode = MODE_DRAW;
		//You can draw the tool bar icons in any way you want.
		//Below is one possible way

		//First prepare List of images for each menu item
		//To control the order of these images in the menu, 
		//reoder them in UI_Info.h ==> enum DrawMenuItem
		string MenuItemImages[MAIN_MENU_COUNT];
		MenuItemImages[MAIN_MENU_SQUARE] = "images\\MenuItems\\square.jpg";
		MenuItemImages[MAIN_MENU_ELLIPSE] = "images\\MenuItems\\ellipse.jpg";
		MenuItemImages[MAIN_MENU_HEXAGON] = "images\\MenuItems\\hexagon.jpg";
		MenuItemImages[MAIN_MENU_SELECT] = "images\\MenuItems\\select.jpg";
		MenuItemImages[MAIN_MENU_CHG_BG] = "images\\MenuItems\\bgcolor.jpg";
		MenuItemImages[MAIN_MENU_CHG_DRAW] = "images\\MenuItems\\drawcolor.jpg";
		MenuItemImages[MAIN_MENU_CHG_FILL] = "images\\MenuItems\\fillcolor.jpg";
		MenuItemImages[MAIN_MENU_RESIZE] = "images\\MenuItems\\resize.jpg";
		MenuItemImages[MAIN_MENU_DELETE] = "images\\MenuItems\\delete.jpg";
		MenuItemImages[MAIN_MENU_SEND_BACK] = "images\\MenuItems\\sendback.jpg";
		MenuItemImages[MAIN_MENU_BRING_FRONT] = "images\\MenuItems\\bringfront.jpg";
		MenuItemImages[MAIN_MENU_SAVE] = "images\\MenuItems\\save.jpg";
		MenuItemImages[MAIN_MENU_LOAD] = "images\\MenuItems\\load.jpg";
		MenuItemImages[MAIN_MENU_PLAY] = "images\\MenuItems\\playmode.jpg";
		MenuItemImages[MAIN_MENU_EXIT] = "images\\MenuItems\\exit.jpg";

		//TODO: Prepare images for each menu item and add it to the list

		//Draw menu item one image at a time
		for (int i = 0; i < MAIN_MENU_COUNT; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	}
	void CreateColorPickerToolBar() const
	{
		UI.InterfaceMode = MODE_PICK_COLOR;
		ClearToolBarArea();
		string ColorsMenuImages[COLOR_COUNT];
		if(CMode == FILL_COLOR)
			ColorsMenuImages[COLOR_BLACK] = "images\\ColorMenu\\none.jpg";
		else
			ColorsMenuImages[COLOR_BLACK] = "images\\ColorMenu\\black.jpg";
			ColorsMenuImages[COLOR_GRAY] = "images\\ColorMenu\\gray.jpg";
			ColorsMenuImages[COLOR_RED] = "images\\ColorMenu\\red.jpg";
			ColorsMenuImages[COLOR_YELLOW] = "images\\ColorMenu\\yellow.jpg";
			ColorsMenuImages[COLOR_GREEN] = "images\\ColorMenu\\green.jpg";
			ColorsMenuImages[COLOR_NAVY] = "images\\ColorMenu\\navy.jpg";
			ColorsMenuImages[COLOR_DEEPORANGE] = "images\\ColorMenu\\darkorange.jpg";
			ColorsMenuImages[COLOR_DEEPPINK] = "images\\ColorMenu\\deeppink.jpg";

		//TODO: Prepare images for each menu item and add it to the list
		ClearToolBarArea();
		//Draw menu item one image at a time
		for (int i = 0; i < COLOR_COUNT; i++)
			pWind->DrawImage(ColorsMenuImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void CreateResizeToolBar() const
	{
		UI.InterfaceMode = MODE_RESIZE;
		ClearToolBarArea();
		string ResizeMenuImages[RESIZE_COUNT];
		ResizeMenuImages[RESIZE_QUARTAR] = "images\\ResizeMenu\\quartar.jpg";
		ResizeMenuImages[RESIZE_HALF] = "images\\ResizeMenu\\half.jpg";
		ResizeMenuImages[RESIZE_DOUBLE] = "images\\ResizeMenu\\double.jpg";
		ResizeMenuImages[RESIZE_2DOUBLE] = "images\\ResizeMenu\\2double.jpg";

		//TODO: Prepare images for each menu item and add it to the list
		//Draw menu item one image at a time
		for (int i = 0; i < RESIZE_COUNT; i++)
			pWind->DrawImage(ResizeMenuImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void getPointInsideDrawArea(int& x, int& y) {
		GetPointClicked(x, y);
		while ((y < UI.StatusBarHeight || y > UI.height - UI.StatusBarHeight))
		{
			PrintMessage("Please, Choose a valid Point");
			GetPointClicked(x, y);
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	void CreatePlayToolBar() const
	{
		UI.InterfaceMode = MODE_PLAY;
		ClearToolBarArea();
		string PlayMenuImages[PLAY_ITM_COUNT];
		PlayMenuImages[PLAY_TYPE] = "images\\PlayMenu\\type.jpg";
		PlayMenuImages[PLAY_FILL] = "images\\PlayMenu\\fill.jpg";
		PlayMenuImages[PLAY_TYPEFILL] = "images\\PlayMenu\\typeandfill.jpg";
		PlayMenuImages[PLAY_RESET] = "images\\PlayMenu\\newgame.jpg";
		PlayMenuImages[PLAY_BACK] = "images\\PlayMenu\\back.jpg";

		//TODO: Prepare images for each menu item and add it to the list
		//Draw menu item one image at a time
		for (int i = 0; i < PLAY_ITM_COUNT; i++)
			pWind->DrawImage(PlayMenuImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	void ClearDrawArea() const
	{
		pWind->SetPen(UI.BkGrndColor, 1);
		pWind->SetBrush(UI.BkGrndColor);
		pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	}
	void ClearToolBarArea() const
	{
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	}
	//////////////////////////////////////////////////////////////////////////////////////////

	void PrintMessage(string msg) const	//Prints a message on status bar
	{
		ClearStatusBar();	//First clear the status bar

		pWind->SetPen(UI.MsgColor, 50);
		pWind->SetFont(20, BOLD, BY_NAME, "Arial");
		pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	color getCrntDrawColor() const	//get current drwawing color
	{
		return UI.DrawColor;
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	color getCrntFillColor() const	//get current filling color
	{
		return UI.FillColor;
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	int getCrntPenWidth() const		//get current pen width
	{
		return UI.PenWidth;
	}

	//======================================================================================//
	//								Figures Drawing Functions								//
	//======================================================================================//

	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;


		pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);

	}
	void DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawEllipse(P1.x, P1.y,P2.x, P2.y, style);

	}

	void DrawHexagon(Point points[], GfxInfo RectGfxInfo, bool selected) const
	{
		color DrawingClr;
		if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		int XPoints2[] = { points[0].x, points[1].x, points[2].x, points[3].x, points[4].x, points[5].x };
		int YPoints2[] = { points[0].y, points[1].y, points[2].y, points[3].y, points[4].y, points[5].y };
		pWind->DrawPolygon(XPoints2, YPoints2, 6, style);
	}


	//////////////////////////////////////////////////////////////////////////////////////////
	bool pointInsideToolBar(int y) const {
		if (y >= 0 && y < UI.ToolBarHeight)
			return true;
		else
			return false;
	}
	COLOR_PICK_MODE getColorBarMode()
	{
		return CMode;
	}
	void setColorBarMode(COLOR_PICK_MODE mode)
	{
		CMode = mode;
	}
	~GUI()
	{
		delete pWind;
	}


};