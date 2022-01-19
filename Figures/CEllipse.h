#pragma once

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point FirstPoint,SecondPoint;
public:
	CEllipse(Point,Point, GfxInfo FigureGfxInfo);
	void DrawMe(GUI* pOut);
	bool Resize(float);
	Point getCenter();
	bool PointInFigure(int,int);
	string getSaveData();
	string GetShapeInfo();
	CFigure * Clone();
	string getShapeType();
};
