#include "ActionDeleteSelected.h"


ActionDeleteSelected::ActionDeleteSelected(ApplicationManager* pApp):Action(pApp)
{
	pGUI = pManager->GetGUI();
}

void ActionDeleteSelected::Execute()
{
	if (pManager->getSelected() != NULL)
	{
		pManager->singleFigureDeleted();
		pGUI->ClearDrawArea();
		pGUI->PrintMessage("Deleted Successfully");
	}
	else
		pGUI->PrintMessage("Please Select a figure before deleting");
}
