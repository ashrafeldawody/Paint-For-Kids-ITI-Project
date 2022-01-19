#include "ActionSendBack.h"


ActionSendBack::ActionSendBack(ApplicationManager* pApp):Action(pApp)
{

}

void ActionSendBack::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedIndex();
	if (selectedIndex != -1){
		pManager->SendToBack(selectedIndex);
		pGUI->ClearDrawArea();
	}else{
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}
