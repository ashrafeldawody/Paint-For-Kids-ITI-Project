#include "ActionExit.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{
	
}
void ActionExit::Execute()
{
	GUI * pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Do you want to save your graph befor exit? if yes then write Y or any key to exit");
	string userInput = pGUI->GetString(pGUI);
	if (userInput == "Y" || userInput == "y")
	{
		//2- Create the corresponding Action
		Action* pAct = pManager->CreateAction(ACTION_SAVE);

		//3- Execute the action
		pManager->ExecuteAction(pAct);

	}
	else
	{
		pGUI->PrintMessage("Goodbye see you soon ... ");
	}
}
