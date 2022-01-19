#include "ActionDeleteSelected.h"


ActionDeleteSelected::ActionDeleteSelected(ApplicationManager* pApp):Action(pApp)
{
}

void ActionDeleteSelected::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	
	if (pManager->getSelected() != NULL)
	{
		pManager->singleFigureDeleted();
		pGUI->ClearDrawArea();
		//pManager->UpdateInterface();
		pGUI->PrintMessage("Deleted Successfully");
	}
	else
		pGUI->PrintMessage("Please Select a figure before deleting");
}
