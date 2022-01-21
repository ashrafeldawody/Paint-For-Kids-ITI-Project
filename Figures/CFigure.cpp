#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;
	Selected = false;
}
CFigure::CFigure() { } //Use it to "save & load" I want an object from the classes that inherent from CFigure
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


void CFigure::ChngDrawClr(color Dclr){
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.FillClr = Fclr;
	FigGfxInfo.isFilled = (FigGfxInfo.FillClr == NULL ? false : true);

}