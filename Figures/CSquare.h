#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	void DrawMe(GUI* pOut);
	Point getSecondPoint();
	bool PointInFigure(int, int);
	bool Resize(float);
	string GetShapeInfo();
	CFigure* Clone();
	string getShapeType();

	//save & Load
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};

