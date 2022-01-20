#pragma once
#include "../../Action.h"
#include "../../../Figures/CSquare.h"
#include "../../../Figures/CEllipse.h"
#include "../../../Figures/CHexagon.h"

class ActionLoad : public Action
{
	GUI* pGUI;
	string FileName;  //We need a name to create a file on the disk

public:
	ActionLoad(ApplicationManager* pApp);
	void Execute();

};
