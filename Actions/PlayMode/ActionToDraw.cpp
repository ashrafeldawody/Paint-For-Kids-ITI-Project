#include "ActionToDraw.h"

ActionToDraw::ActionToDraw(ApplicationManager* pApp):Action(pApp)
{
	
}


void ActionToDraw::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->ClearToolBarArea();
	pGUI->CreateDrawToolBar();
	pManager->restoreFigList();	
	pManager->clearFigListBackup();
	UI.InterfaceMode == MODE_DRAW;
}
