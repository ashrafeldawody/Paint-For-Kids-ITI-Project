#include "ActionBringFront.h"


ActionBringFront::ActionBringFront(ApplicationManager* pApp):Action(pApp)
{

}

void ActionBringFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedIndex();
	if (selectedIndex != -1) {
		pManager->BringToFront(selectedIndex);
		pGUI->ClearDrawArea();
	}
	else {
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}
