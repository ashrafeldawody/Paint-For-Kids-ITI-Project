#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
#include"../SaveLoad/ActionSave.h"
class ActionExit : public Action
{
	GUI* pGUI;
public:
	ActionExit(ApplicationManager* pApp);
	void Execute();
};

