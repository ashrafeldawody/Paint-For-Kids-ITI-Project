#include "CHexagon.h"
#include <cmath>

#define PI 3.14159265

CHexagon::CHexagon(){}
CHexagon::CHexagon(Point _center, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
    radius = 100;
    center = _center;
}

bool CHexagon::generatePoints()
{
    Point temp[6];
    for (int i = 0; i < 6; i++) {
        temp[i].x = center.x + radius * cos(2 * PI * i / 6);
        temp[i].y = center.y + radius * sin(2 * PI * i / 6);
        if (!Helpers::checkPointInsideDrawArea(temp[i].x, temp[i].y))
            return false;
    }
    //if loop didn't return false.. it means all points are valid
    for (int i = 0; i < 6; i++) {
        points[i] = temp[i];
    }
    return true;
}

void CHexagon::DrawMe(GUI* pGUI)
{
	pGUI->DrawHexagon(points, FigGfxInfo, Selected);
}
bool CHexagon::Resize(float factor)
{
    //try to resize shape
    radius *= factor;
    //if one of the points outside draw area..
    if (generatePoints()) return true;

    //change radius back to it's original value
    radius /= factor;
    return false;

}
bool CHexagon::PointInFigure(int x,int y)
{
        float dx = abs(x - center.x) / radius;
        float dy = abs(y - center.y) / radius;
        float a = 0.25 * sqrt(3.0);
        return (dy < a) && (a * dx + 0.25 * dy < 0.5 * a);
}

string CHexagon::GetShapeInfo()
{
    string DrawColor = Helpers::getColorName(FigGfxInfo.DrawClr);
    string shapeInfo = "ID: " + to_string(ID) + " || Shape: HEXAGON || Center Point: (" + to_string(center.x) + ", " + to_string(center.y) + ")" + " || Radius: " + to_string(radius) + " || Draw Color: " + DrawColor;
    if (FigGfxInfo.isFilled)
    {
        string fillColor = Helpers::getColorName(FigGfxInfo.FillClr);
        shapeInfo += " || Filled || Fill Color: " + fillColor;
    }
    else {
        shapeInfo += " || NO FILL";
    }
    return shapeInfo;
}
CFigure* CHexagon::Clone()
{
    return new CHexagon(*this);
}

string CHexagon::getShapeType()
{
    return "Hexagon";
}

// for save & load
void CHexagon::Save(ofstream& OutFile)
{
    //to Convert color from Enum color to String Color
    string DrawColor = Helpers::getColorName(this->FigGfxInfo.DrawClr);
    string fillColor = Helpers::getColorName(this->FigGfxInfo.FillClr);

    OutFile << "Hexagon\t" << ID << "\t" 
        << this->center.x << "\t" << this->center.y << "\t"
        << radius << "\t"
        << DrawColor << "\t";
    if (this->FigGfxInfo.isFilled)
        OutFile << fillColor << "\t";
    else
        OutFile << "NON-FILLED\t";

    OutFile << this->FigGfxInfo.BorderWdth << "\n";

}
void CHexagon::Load(ifstream& Infile)
{
    string color;
 
    Infile >> ID >>
        center.x >> center.y >> radius;

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
    generatePoints();
}

