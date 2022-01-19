#include "ActionAddEllipse.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getCrntFillColor() == NULL ? false : true;
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user
	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->getPointInsideDrawArea(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->getPointInsideDrawArea(P2.x, P2.y);

	pGUI->ClearStatusBar();
	if (!Helpers::checkPointInsideDrawArea(P1.x, P1.y) || !Helpers::checkPointInsideDrawArea(P2.x, P2.y)) {
		pGUI->PrintMessage("Shape can't fit into the drawing area");
		return;
	}
	//Step 3 - Create a Square with the parameters read from the user
	CEllipse* R = new CEllipse(P1, P2, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
