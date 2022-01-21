#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PICK_FILL_COLOR,
	MODE_PICK_DRAW_COLOR,
	MODE_PICK_BG_COLOR,
	MODE_RESIZE,
	MODE_PLAY	//Playing mode
};
enum COLOR_PICK_MODE	//Graphical user interface mode
{
	DRAW_COLOR,
	FILL_COLOR,
	BACKGROUND_COLOR,
};
enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	MAIN_MENU_SQUARE,	
	MAIN_MENU_ELLIPSE,
	MAIN_MENU_HEXAGON,

	MAIN_MENU_SELECT,
	MAIN_MENU_CHG_BG,
	MAIN_MENU_CHG_DRAW,
	MAIN_MENU_CHG_FILL,
	MAIN_MENU_RESIZE,
	MAIN_MENU_DELETE,
	MAIN_MENU_SEND_BACK,
	MAIN_MENU_BRING_FRONT,

	MAIN_MENU_SAVE,
	MAIN_MENU_LOAD,

	MAIN_MENU_PLAY,

	MAIN_MENU_EXIT,

	MAIN_MENU_COUNT

};

enum BGColorsItem //The items of the Color menu (you should add more items)
{
	COLOR_BURLYWOOD,
	COLOR_LIGHTGREEN,
	COLOR_LIGHTYELLOW,
	COLOR_THISTLE,
	COLOR_WHEAT,

	COLOR_BG_COUNT
};
enum FillColorsItem //The items of the Color menu (you should add more items)
{
	COLOR_NONE,
	COLOR_DARKCYAN,
	COLOR_DARKMAGENTA,
	COLOR_GREEN,
	COLOR_HOTPINK,
	COLOR_INDIAN,
	COLOR_LIGHTCORAL,
	COLOR_PERU,
	COLOR_SIENNA,
	COLOR_SPRINGGREEN,
	COLOR_TOMATO,

	COLOR_FILL_COUNT
};
enum DrawColorsItem //The items of the Color menu (you should add more items)
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_CHOCOLATE,
	COLOR_DARKGOLDENROD,
	COLOR_DARKRED,
	COLOR_DEEPPINK,
	COLOR_OLIVEDRAB,

	COLOR_DRAW_COUNT
};
enum resizeMenuItem //The items of the Resize menu (you should add more items)
{
	RESIZE_QUARTAR,
	RESIZE_HALF,
	RESIZE_DOUBLE,
	RESIZE_2DOUBLE,

	RESIZE_COUNT

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	PLAY_TYPE,
	PLAY_FILL,
	PLAY_TYPEFILL,
	PLAY_RESET,
	PLAY_BACK,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	/// Add more members if needed
	
}UI;	//create a global object UI
