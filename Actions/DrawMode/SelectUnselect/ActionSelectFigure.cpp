#pragma once
#include "ActionSelectFigure.h"
#include <iostream>


ActionSelectFigure::ActionSelectFigure(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionSelectFigure::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Please Click on figure to select ");
	pGUI->getPointInsideDrawArea(P.x, P.y);

	
	pGUI->ClearStatusBar();

	CFigure* fig = pManager->GetFigure(P.x, P.y);


	if (fig != NULL)
	{
		if (fig->IsSelected()) {
			fig->SetSelected(false);
		}
		else {
			pManager->UnselectAll();
			fig->SetSelected(true);
		}
	}
	else
	{
		pGUI->PrintMessage("No Shape Found");
	}
}