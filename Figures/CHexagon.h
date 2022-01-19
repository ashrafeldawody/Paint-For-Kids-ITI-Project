#pragma once

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point points[6];
	Point center;
	int radius;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	bool generatePoints();
	void DrawMe(GUI* pOut);
	bool Resize(float);
	bool PointInFigure(int,int);
	string getSaveData();
	string GetShapeInfo();
	CFigure* Clone();
	string getShapeType();
};
