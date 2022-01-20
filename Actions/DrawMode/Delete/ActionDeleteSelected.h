#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
#include"../../../Figures/CFigure.h"
class ActionDeleteSelected : public Action
{
	GUI* pGUI;
public:
	ActionDeleteSelected(ApplicationManager* pApp);
	void Execute();

};
