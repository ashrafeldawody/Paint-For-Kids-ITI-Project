#include "ActionResizeSelected.h"


ActionResizeSelected::ActionResizeSelected(ApplicationManager* pApp, float _resizeFactor) :Action(pApp)
{
	resizeFactor = _resizeFactor;

}

void ActionResizeSelected::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	CFigure* fig = pManager->getSelected();


	if (fig != NULL)
	{
		fig->Resize(resizeFactor);
		pManager->UpdateInterface();
		pGUI->PrintMessage("Shape Resized Successfully");
	}
	else
	{
		pGUI->PrintMessage("select the shape first");
	}


}