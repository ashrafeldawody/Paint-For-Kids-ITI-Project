#include "ChangeDrawColor.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp,color c):Action(pApp)
{

	drawColor = c;
}

void ChangeDrawColor::Execute()
{
	
	GUI* pGUI = pManager->GetGUI();
	CFigure* selected = pManager->getSelected();
	if (selected == NULL) {
		UI.DrawColor = drawColor;
		pGUI->PrintMessage("Draw Color Changed.. You can draw with it now ^_^ ");
	}
	else {
		selected->ChngDrawClr(drawColor);
		pGUI->PrintMessage("Shape Draw Color Changed");
	}

	pGUI->ClearDrawArea();
	pGUI->CreateDrawToolBar();
}


