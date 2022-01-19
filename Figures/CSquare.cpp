#include "CSquare.h"


CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) 
{
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);

}
Point CSquare::getSecondPoint() {
	Point p;
	p.x = TopLeftCorner.x + length;
	p.y = TopLeftCorner.y + length;
	return p;
}
bool CSquare::PointInFigure(int x, int y)
{
	Point Left = TopLeftCorner;
	Point Right = getSecondPoint();
	Point P;
	P.x = x; P.y = y;
	if ((P.x >= Left.x) && (P.x <= Right.x) && (P.y >= Left.y) && (P.y <=Right.y))
		return true;
	else
		return false;
}
void CSquare::Resize(float size)
{
	length *= size;
}
string CSquare::getSaveData()
{
	string DrawColor = Helpers::getColorName(FigGfxInfo.DrawClr);
	string shapeInfo = "SQUARE\t" + to_string(ID) + "\t" + to_string(TopLeftCorner.x) + "\t" + to_string(TopLeftCorner.y) + "\t" + to_string(length) + "\t" + DrawColor;
	if (FigGfxInfo.isFilled)
	{
		string fillColor = Helpers::getColorName(FigGfxInfo.FillClr);
		shapeInfo += "\t" + fillColor;
	}
	else {
		shapeInfo += "\tNO_FILL";
	}
	return shapeInfo;
}
string CSquare::GetShapeInfo()
{
	string DrawColor = Helpers::getColorName(FigGfxInfo.DrawClr);
	string shapeInfo = "ID: " + to_string(ID) + " || Shape: Square || Point 1: (" + to_string(TopLeftCorner.x) + ", " + to_string(TopLeftCorner.y) + ")" + " || Side Length: " + to_string(length) + " || Area: " + to_string(length * length) + " Draw Color: " + DrawColor;
	if (FigGfxInfo.isFilled)
	{
		string fillColor = Helpers::getColorName(FigGfxInfo.FillClr);
		shapeInfo += "|| Filled || Fill Color: " + fillColor;
	}
	return shapeInfo;
}
CFigure* CSquare::Clone()
{
	return new CSquare(*this);
}
