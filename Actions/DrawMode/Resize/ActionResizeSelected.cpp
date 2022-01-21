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
		if (fig->Resize(resizeFactor)) {
			pManager->UpdateInterface();
			pGUI->PrintMessage("Shape Resized Successfully");
		}
		else {
			pGUI->PrintMessage("Resized shape can't fit into the drawing area");
		}
	}
	else
	{
		pGUI->PrintMessage("select the shape first");
	}
	pGUI->CreateDrawToolBar();                        

}