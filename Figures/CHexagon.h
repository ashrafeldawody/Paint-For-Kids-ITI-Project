#pragma once

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point points[6];
	Point center;
	int radius;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	bool generatePoints();
	void DrawMe(GUI* pOut);
	bool Resize(float);
	bool PointInFigure(int,int);
	string GetShapeInfo();
	CFigure* Clone();
	string getShapeType();

	//save & Load
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};
