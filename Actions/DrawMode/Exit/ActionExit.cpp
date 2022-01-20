#include "ActionExit.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{
	pGUI = pManager->GetGUI();
}
void ActionExit::Execute()
{
	pGUI->PrintMessage("Do you want to save your graph befor exit? if yes then write Y or any key to exit");
	string userInput = pGUI->GetString(pGUI);
	if (userInput == "Y" || userInput == "y")
	{
		ActionType pAct = ACTION_SAVE;
		pManager->CreateAction(pAct);
	}
	else
	{
		pGUI->PrintMessage("Goodbye see you soon ... ");
	}
}
