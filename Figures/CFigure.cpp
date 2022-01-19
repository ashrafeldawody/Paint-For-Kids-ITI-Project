#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;
	Selected = false;
}

void CFigure::SetID(int _ID)
{
	ID = _ID;
}
void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const{
	return Selected; 
}

color CFigure::getFillColor()
{
	return FigGfxInfo.isFilled ? FigGfxInfo.FillClr : NULL;
}

void CFigure::Unfill()
{
	FigGfxInfo.FillClr = NULL;
	FigGfxInfo.isFilled = false;
}

void CFigure::ChngDrawClr(color Dclr){
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

