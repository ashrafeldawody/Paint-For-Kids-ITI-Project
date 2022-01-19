#include "ActionNewGame.h"

ActionNewGame::ActionNewGame(ApplicationManager* pApp):Action(pApp)
{
	
}


void ActionNewGame::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pManager->restoreFigList();
}
