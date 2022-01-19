#include "CHexagon.h"
#include <cmath>

#define PI 3.14159265

CHexagon::CHexagon(Point _center, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
    radius = 100;
    center = _center;
    generatePoints();

}

void CHexagon::generatePoints()
{
    for (int i = 0; i < 6; i++) {
        points[i].x = center.x + radius * cos(2 * PI * i / 6);
        points[i].y = center.y + radius * sin(2 * PI * i / 6);
    }
}

void CHexagon::DrawMe(GUI* pGUI)
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(points, FigGfxInfo, Selected);
}
void CHexagon::Resize(float factor)
{
    radius *= factor;
    generatePoints();
}
bool CHexagon::PointInFigure(int x,int y)
{
    Point p;
    p.x = x;
    p.y = y;
    // Create a point for line segment from p to infinite 
    Point extreme = { 10000, y };

    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % 6;

        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (Helpers::doIntersect(points[i], points[next], p, extreme))
        {
            // If the point 'p' is collinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (Helpers::orientation(points[i], p, points[next]) == 0)
                return Helpers::onSegment(points[i], p, points[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise 
    return count%2 == 1;
}

string CHexagon::getSaveData()
{
    string DrawColor = Helpers::getColorName(FigGfxInfo.DrawClr);
    string shapeInfo = "HEXAGON\t" + to_string(ID) + "\t" + to_string(center.x) + "\t" + to_string(center.y) + "\t" + to_string(radius) + "\t" + DrawColor;
    if (FigGfxInfo.isFilled)
    {
        string fillColor = Helpers::getColorName(FigGfxInfo.FillClr);
        shapeInfo += "\t" + fillColor;
    }
    else
    {
        shapeInfo += "\tNO_FILL";
    }
    return shapeInfo;
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

