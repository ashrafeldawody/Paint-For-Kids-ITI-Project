#include "CSquare.h"

CSquare::CSquare() {}

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
bool CSquare::Resize(float size)
{
	length *= size;
	//if both points inside draw area
	if (Helpers::checkPointInsideDrawArea(TopLeftCorner.x, TopLeftCorner.y) && Helpers::checkPointInsideDrawArea(TopLeftCorner.x + length, TopLeftCorner.y + length))
		return true;

	length /= size;
	return false;
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

string CSquare::getShapeType()
{
	return "Square";
}


// for save & load
void CSquare::Save(ofstream& OutFile)
{
	//to Convert color from Enum color to String Color
	string DrawColor = Helpers::getColorName(this->FigGfxInfo.DrawClr);
	string fillColor = Helpers::getColorName(this->FigGfxInfo.FillClr);

	OutFile << "Square\t"
		<< ID << "\t" << this->TopLeftCorner.x << "\t" << this->TopLeftCorner.y << "\t"
		<< this->length << "\t"
		<< DrawColor << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << fillColor << "\t";
	else
		OutFile << "NON-FILLED\t";

	OutFile << this->FigGfxInfo.BorderWdth << "\n";

}
void CSquare::Load(ifstream& Infile)
{
	string color;

	Infile >> ID >> TopLeftCorner.x >> TopLeftCorner.y	>> length;

	Infile >> color;
	//to Convert color from String color to Enum Color
	FigGfxInfo.DrawClr = Helpers::getColorFromString(color);
	
	Infile >> color;
	if (color == "NON-FILLED") {
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = NULL;
	}
	else
	{
		FigGfxInfo.FillClr = Helpers::getColorFromString(color);
		FigGfxInfo.isFilled = true;
	}
	Infile >>FigGfxInfo.BorderWdth;
	Selected = false;
}
