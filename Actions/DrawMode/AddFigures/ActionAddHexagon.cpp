#include "ActionAddHexagon.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point point;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getCrntFillColor() == NULL ? false : true;

	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	pGUI->PrintMessage("New Hexagon: Click to select Center Point");
	pGUI->getPointInsideDrawArea(point.x, point.y);


	CHexagon* R = new CHexagon(point, SqrGfxInfo);
	//hexagon violates draw area borders
	if (!R->generatePoints()){
		pGUI->PrintMessage("Shape can't fit into the drawing area");
		delete R;
		return;
	}

	pManager->AddFigure(R);
}
