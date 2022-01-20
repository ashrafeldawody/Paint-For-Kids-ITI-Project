#include "CEllipse.h"
#include<string>
#include<fstream>
CEllipse::CEllipse() {}

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	FirstPoint = P1;
	SecondPoint = P2;
}

void CEllipse::DrawMe(GUI* pGUI)
{
	//Call Output::DrawEllipse to draw a Ellipse on the screen	
	pGUI->DrawEllipse(FirstPoint, SecondPoint, FigGfxInfo, Selected);

}
bool CEllipse::Resize(float factor)
{
	int x = SecondPoint.x - FirstPoint.x;
	int y = SecondPoint.y - FirstPoint.y;

	Point tempSecondPoint = SecondPoint;
	SecondPoint.x = FirstPoint.x + (x * factor);
	SecondPoint.y = FirstPoint.y + (y * factor);
	
	if (Helpers::checkPointInsideDrawArea(SecondPoint.x, SecondPoint.y))
		return true;

	SecondPoint = tempSecondPoint;
	return false;
}
Point CEllipse::getCenter()
{
	Point temp;
	temp.x = (FirstPoint.x + SecondPoint.x) / 2;
	temp.y = (FirstPoint.y + SecondPoint.y) / 2;
	return temp;
}
bool CEllipse::PointInFigure(int x,int y){
	Point Center = Helpers::getMidPoint(FirstPoint, SecondPoint);
	Point SemiMajorAxises;
	SemiMajorAxises.x = Center.x - FirstPoint.x;
	SemiMajorAxises.y = Center.y - FirstPoint.y;

	if ((pow((x - Center.x), 2) / pow(SemiMajorAxises.x, 2)) + (pow((y - Center.y), 2) / pow(SemiMajorAxises.y, 2)) < 1)
	{
		return true;
	}
	return false;
}

string CEllipse::GetShapeInfo()
{
	string id = to_string(ID);
	string dColor = Helpers::getColorName(FigGfxInfo.DrawClr);
	string data = "Ellipse || ID: " + id + " First Point: (" + to_string(FirstPoint.x) + ", " + to_string(FirstPoint.y) + ") Second Point: (" + to_string(SecondPoint.x) + ", " + to_string(SecondPoint.y) + ") DrawColor:" + dColor;
	if (FigGfxInfo.isFilled)
	{
		data += " FillColor: " + Helpers::getColorName(FigGfxInfo.FillClr);
	}
	else{
		data += " FillColor: NO-Fill";
	}
	return data;
}

CFigure* CEllipse::Clone()
{ 
	return new CEllipse(*this);
}

string CEllipse::getShapeType()
{
	return "Ellipse";
}

// for save & load
void CEllipse::Save(ofstream& OutFile)
{
	//to Convert color from Enum color to String Color
	string DrawColor = Helpers::getColorName(this->FigGfxInfo.DrawClr);
	string fillColor = Helpers::getColorName(this->FigGfxInfo.FillClr);

	OutFile << "Ellipse\t"
		<< ID << "\t" << this->FirstPoint.x << "\t" << this->FirstPoint.y << "\t"
		<< this->SecondPoint.x << "\t" << this->SecondPoint.y << "\t"
		<< DrawColor << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << fillColor << "\t";
	else
		OutFile << "NON-FILLED\t";

	OutFile << this->FigGfxInfo.BorderWdth << "\n";

}
void CEllipse::Load(ifstream& Infile)
{
	string color;

	Infile >> ID >> FirstPoint.x >> FirstPoint.y >> SecondPoint.x >>  SecondPoint.y;

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

