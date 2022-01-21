#include "ChangeBGColor.h"

ChangeBGColor::ChangeBGColor(ApplicationManager* pApp,color c):Action(pApp)
{
	bgColor = c;
}


void ChangeBGColor::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	UI.BkGrndColor = bgColor;
	pGUI->PrintMessage("BackGround Color Changed Successfully");
	pGUI->ClearDrawArea();
	pGUI->CreateDrawToolBar();
}
