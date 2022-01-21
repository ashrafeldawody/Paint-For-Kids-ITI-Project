#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	ACTION_DRAW_SQUARE,	//Draw a Square
	ACTION_DRAW_ELLIPSE,		//Draw an Ellipse
	ACTION_DRAW_HEXAGON,		//Draw a Hexagon
	ACTION_SELECT, // select or unselect
	ACTION_CHNG_DRAW_CLR, // change draw color
	ACTION_CHNG_FILL_CLR, // Change fill color
	ACTION_CHNG_BG_CLR,	//Change background color
	ACTION_DELETE,			//Delete a figure(s)
	ACTION_RESIZE,			//Resize a figure(s)
	ACTION_SEND_BACK,		//Send a figure to the back of all figures
	ACTION_BRNG_FRNT,		//Bring a figure to the front of all figures
	ACTION_SAVE,			//Save the whole graph to a file
	ACTION_LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	//Colors
	//DRAW
	ACTION_DRAW_BLACK,
	ACTION_DRAW_RED,
	ACTION_DRAW_CHOCOLATE,
	ACTION_DRAW_DARKGOLDENROD,
	ACTION_DRAW_DARKRED,
	ACTION_DRAW_DEEPPINK,
	ACTION_DRAW_OLIVEDRAB,
	//FILL
	ACTION_FILL_NONE,
	ACTION_FILL_DARKCYAN,
	ACTION_FILL_DARKMAGENTA,
	ACTION_FILL_GREEN,
	ACTION_FILL_HOTPINK,
	ACTION_FILL_INDIAN,
	ACTION_FILL_LIGHTCORAL,
	ACTION_FILL_PERU,
	ACTION_FILL_SIENNA,
	ACTION_FILL_SPRINGGREEN,
	ACTION_FILL_TOMATO,
	//BG
	ACTION_BG_BURLYWOOD,
	ACTION_BG_LIGHTGREEN,
	ACTION_BG_LIGHTYELLOW,
	ACTION_BG_THISTLE,
	ACTION_BG_WHEAT,
	//Resize
	ACTION_QUARTAR,
	ACTION_HALF,
	ACTION_DOUBLE,
	ACTION_2DOUBLE,

	//Play Mode
	ACTION_PLAY_TYPE,
	ACTION_PLAY_FILL,
	ACTION_PLAY_TYPEFILL,
	ACTION_PLAY_RESET,

	ACTION_TO_DRAW,		//Switch interface to Draw mode
	ACTION_TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif