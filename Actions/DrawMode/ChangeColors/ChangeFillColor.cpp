#include "ChangeFillColor.h"
#include <stdio.h>

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp,color c):Action(pApp)
{ 
	fillColor = c;
}

void ChangeFillColor::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	CFigure* selected = pManager->getSelected();
	if (selected == NULL) {
		UI.FillColor = fillColor;
		pGUI->PrintMessage("Fill Color Changed.. You can draw with it now ^_^ ");
	}
	else {
		selected->ChngFillClr(fillColor);
		pGUI->PrintMessage("Shape Fill Color Changed");
	}

	pGUI->ClearDrawArea();
	pGUI->CreateDrawToolBar();
}

